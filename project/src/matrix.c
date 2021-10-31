#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
## Общая информация

* Функции интерфейса, возвращающие указатель, должны вернуть валидный указатель на `struct Matrix` в случае успеха и NULL -
в остальных случаях.
* Функции интерфейса, возвращающие `int`, должны вернуть `0` и, если требуется, записать результат в выходную переменную
в случае успеха; вернуть **ненулевое** значение в остальных случаях.
*/

// Init/release operations
Matrix* create_matrix_from_file(const char* path_file) {
    size_t rows, cols;
    FILE* file_matrix_data = NULL;
    file_matrix_data = fopen(path_file, "r");
    if (!file_matrix_data) {
        puts("ERROR READ FROM FILE!");
        return NULL_POINTER;
    }

    int check_matrix_dim = fscanf(file_matrix_data, "%zu%zu", &rows, &cols);

    // проверка на правильность rows, cols в 1й строке файла
    if (check_matrix_dim != 2) {
        if (check_matrix_dim == EOF) {
            puts("ERROR EOF!");
        } else {
            puts("ERROR invalid file (false structure)!");
        }
        fclose(file_matrix_data);
        return NULL_POINTER;
    }

    // создание указателя на структуру Matrix и инициализация
    Matrix* matrix_from_file = NULL;
    matrix_from_file = create_matrix(rows, cols);
    if (!matrix_from_file) {
        fclose(file_matrix_data);
        return NULL_POINTER;
    }

    // инициализация матрицы из файла
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            fscanf(file_matrix_data, "%lf", &matrix_from_file->values[i][j]);
        }
    }

    // проверка на конец файла
    double temp = 0.0;
    int end_of_file = fscanf(file_matrix_data, "%lf", &temp);
    if (end_of_file != EOF) {
        puts("ERROR invalid file, there is more values!");

        free_matrix(matrix_from_file);
        fclose(file_matrix_data);
        return NULL_POINTER;
    }

    fclose(file_matrix_data);
    return matrix_from_file;
}

Matrix* create_matrix(size_t rows, size_t cols) {
    if ((!rows) || (!cols)) {
        return NULL_POINTER;
    }

    Matrix* matrix_zero = NULL;
    matrix_zero = (Matrix*) malloc(sizeof(Matrix));
    if (!matrix_zero) {
        return NULL_POINTER;
    }

    matrix_zero->rows = rows;
    matrix_zero->cols = cols;

    matrix_zero->values = NULL;
    matrix_zero->values = (double**) malloc(rows * sizeof(double*));
    if (!matrix_zero->values) {
        free(matrix_zero);
        return NULL_POINTER;
    }

    for (size_t i = 0; i < rows; ++i) {
        matrix_zero->values[i] = NULL;
        matrix_zero->values[i] = (double*) malloc(cols * sizeof(double));
        if (!matrix_zero->values[i]) {
            free_matrix(matrix_zero);
            return NULL_POINTER;
        }
    }

    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            matrix_zero->values[i][j] = 0;
        }
    }

    return matrix_zero;
}

void free_matrix(Matrix* matrix) {
    if (matrix) {
        size_t rows = matrix->rows;

        if (matrix->values) {
            for (size_t i = 0; i < rows; ++i) {
                if (matrix->values[i]) {
                    free(matrix->values[i]);
                }
            }
            free(matrix->values);
        }
        free(matrix);
    }
}

// Custom operations
int print(const Matrix* matrix) {
    if (!matrix) {
        return NULL_MATRIX;
    }

    size_t rows = matrix->rows;
    size_t cols = matrix->cols;
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            printf("%12.2f", matrix->values[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}

Matrix* copy(const Matrix* matrix) {
    if (!matrix) {
        return NULL_POINTER;
    }

    size_t rows = matrix->rows;
    size_t cols = matrix->cols;

    Matrix* return_matrix = NULL;
    return_matrix = create_matrix(rows, cols);
    if (!return_matrix) {
        return NULL_POINTER;
    }

    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            return_matrix->values[i][j] = matrix->values[i][j];
        }
    }
    return return_matrix;
}

Matrix* matrix_minor(const Matrix* matrix, size_t row, size_t col) {
    if (!matrix) {
        return NULL_POINTER;
    }

    if (matrix->rows != matrix->cols) {
        return NULL_POINTER;
    }

    size_t rows = matrix->rows;
    Matrix* return_matrix = NULL;
    return_matrix = create_matrix(rows-1, rows-1);
    if (!return_matrix) {
        return NULL_POINTER;
    }

    size_t offset_row = 0;
    for (size_t i = 0; i < rows-1; ++i) {
        if (i == row) {
            offset_row = 1;
        }

        size_t offset_col = 0;
        for (size_t j = 0; j < rows-1; ++j) {
            if (j == col) {
                offset_col = 1;
            }
            return_matrix->values[i][j] = matrix->values[i + offset_row][j + offset_col];
        }
    }

    return return_matrix;
}

// Basic operations
int get_rows(const Matrix* matrix, size_t* rows) {
    if (!matrix) {
        return NULL_MATRIX;
    }

    *rows = matrix->rows;

    return 0;
}

int get_cols(const Matrix* matrix, size_t* cols) {
    if (!matrix) {
        return NULL_MATRIX;
    }

    size_t temp = matrix->cols;
    if (!temp) {
        return NON_STANDARD_ERROR;
    }
    *cols = temp;

    return 0;
}

int get_elem(const Matrix* matrix, size_t row, size_t col, double* val) {
    if (!matrix) {
        return NULL_MATRIX;
    }

    size_t rows = matrix->rows;
    size_t cols = matrix->cols;

    if (row > rows || col > cols) {
        return BOUNDARY_ERROR;
    }

    *val = matrix->values[row][col];

    return 0;
}

int set_elem(Matrix* matrix, size_t row, size_t col, double val) {
    if (!matrix) {
        return NULL_MATRIX;
    }

    size_t rows = matrix->rows;
    size_t cols = matrix->cols;

    if ((row > rows) || (col > cols)) {
        return BOUNDARY_ERROR;
    }

    matrix->values[row][col] = val;

    return 0;
}

// Math operations
Matrix* mul_scalar(const Matrix* matrix, double val) {
    if (!matrix) {
        return NULL_POINTER;
    }

    size_t rows = matrix->rows;
    size_t cols = matrix->cols;

    Matrix* return_matrix = NULL;
    return_matrix = copy(matrix);
    if (!return_matrix) {
        return NULL_POINTER;
    }

    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            return_matrix->values[i][j] = val * matrix->values[i][j];
        }
    }
    return return_matrix;
}

Matrix* transp(const Matrix* matrix) {
    if (!matrix) {
        return NULL_POINTER;
    }

    size_t rows = matrix->rows;
    size_t cols = matrix->cols;

    Matrix* return_matrix = NULL;
    return_matrix = create_matrix(cols, rows);
    if (!return_matrix) {
        return NULL_POINTER;
    }

    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            return_matrix->values[j][i] = matrix->values[i][j];
        }
    }
    return return_matrix;
}


Matrix* sum(const Matrix* left, const Matrix* right) {
    if (!left || !right) {
        return NULL_POINTER;
    }

    size_t rows = left->rows;
    size_t cols = left->cols;

    if ((right->rows != rows) || (right->cols != cols)) {
        return NULL_POINTER;
    }

    Matrix* return_matrix = NULL;
    return_matrix = copy(left);
    if (!return_matrix) {
        return NULL_POINTER;
    }

    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            return_matrix->values[i][j] += right->values[i][j];
        }
    }
    return return_matrix;
}

Matrix* sub(const Matrix* left, const Matrix* right) {
    if (!left || !right) {
        return NULL_POINTER;
    }

    size_t rows = left->rows;
    size_t cols = left->cols;

    if ((right->rows != rows) || (right->cols != cols)) {
        return NULL_POINTER;
    }

    Matrix* return_matrix = NULL;
    return_matrix = copy(left);
    if (!return_matrix) {
        return NULL_POINTER;
    }

    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            return_matrix->values[i][j] -= right->values[i][j];
        }
    }
    return return_matrix;
}

Matrix* mul(const Matrix* left, const Matrix* right) {
    if (!left || !right) {
        return NULL_POINTER;
    }

    size_t l_rows = left->rows;
    size_t l_cols = left->cols;
    size_t r_rows = right->rows;
    size_t r_cols = right->cols;

    if (l_cols != r_rows) {
        return NULL_POINTER;
    }

    Matrix* return_matrix = NULL;
    return_matrix = create_matrix(l_rows, r_cols);
    if (!return_matrix) {
        return NULL_POINTER;
    }

    double temp;
    for (size_t i = 0; i < l_rows; ++i) {
        for (size_t j = 0; j < r_cols; ++j) {
            temp = 0;
            for (size_t k = 0; k < l_cols; ++k) {
                temp += left->values[i][k]*right->values[k][j];
            }
            return_matrix->values[i][j] = temp;
        }
    }

    return return_matrix;
}


// Extra operations
int det(const Matrix* matrix, double* val) {
    if (!matrix) {
        return NULL_MATRIX;
    }

    size_t rows = matrix->rows;
    size_t cols = matrix->cols;

    if (rows != cols) {
        return NON_STANDARD_ERROR;
    }

    if (rows == 1) {
        *val = matrix->values[0][0];
        return 0;
    }

    if (rows == 2) {
        *val = (matrix->values[0][0])*(matrix->values[1][1]) -
                (matrix->values[0][1])*(matrix->values[1][0]);
        return 0;
    }

    Matrix* return_matrix = NULL;
    double determinant = 0;
    double det_without_row_and_col = 0;
    int degree = 1;
    for (size_t i = 0; i < rows; ++i) {
        if (return_matrix) free_matrix(return_matrix);
        return_matrix = matrix_minor(matrix, 0, i);

        size_t error = det(return_matrix, &det_without_row_and_col);
        if (error) {
            if (return_matrix) free_matrix(return_matrix);
            return NON_STANDARD_ERROR;
        }
        determinant += degree * matrix->values[0][i] * det_without_row_and_col;

        degree = -degree;
    }

    if (return_matrix) free_matrix(return_matrix);
    *val = determinant;
    return 0;
}

Matrix* adj(const Matrix* matrix) {
    // присоединенная = обратная * определитель
    if (!matrix) {
        return NULL_POINTER;
    }

    size_t rows = matrix->rows;
    size_t cols = matrix->cols;

    if (rows != cols) {
        return NULL_POINTER;
    }

    Matrix* inv_matrix = NULL;
    inv_matrix = inv(matrix);
    if (!inv_matrix) {
        return NULL_POINTER;
    }

    double determinant = 0;
    int error = det(matrix, &determinant);
    if (error || (fabs(determinant) < EPS)) {
        free_matrix(inv_matrix);
        return NULL_POINTER;
    }

    Matrix* return_matrix = NULL;
    return_matrix = mul_scalar(inv_matrix, determinant);
    if (!return_matrix) {
        free_matrix(inv_matrix);
        return NULL_POINTER;
    }

    free_matrix(inv_matrix);
    return return_matrix;
}

Matrix* inv(const Matrix* matrix) {
    if (!matrix) {
        return NULL_POINTER;
    }

    size_t rows = matrix->rows;
    size_t cols = matrix->cols;

    if (rows != cols) {
        return NULL_POINTER;
    }

    // если определитель = 0 -> NULL_POINTER
    double determinant = 0;
    int error = det(matrix, &determinant);
    if (error || (fabs(determinant) < EPS)) {
        return NULL_POINTER;
    }

    Matrix* return_matrix = NULL;
    return_matrix = create_matrix(rows, rows);
    if (!return_matrix) {
        return NULL_POINTER;
    }

    if (rows == 1) {
        return_matrix->values[0][0] = 1/matrix->values[0][0];
        return return_matrix;
    }

    // единичная матрица
    for (size_t i = 0; i < rows; ++i) {
        return_matrix->values[i][i] = 1;
    }

    // копия исходной матрицы
    Matrix* matrix_inv = NULL;
    matrix_inv = copy(matrix);
    if (!matrix_inv) {
        free_matrix(return_matrix);
        return NULL_POINTER;
    }

    // вычисление обратной матрицы
    double temp, temp1;
    for (size_t k = 0; k < rows; ++k) {
        // поиск не равного нулю в столбце элемента
        size_t offset = k;
        temp = matrix_inv->values[offset][k];
        while ((fabs(temp) < EPS) && (offset < rows)) {
            ++offset;
            temp = matrix_inv->values[offset][k];
        }

        // поменяли 2 строки местами
        for (size_t r = 0; r < rows; ++r) {
            temp1 = matrix_inv->values[k][r];
            matrix_inv->values[k][r] = matrix_inv->values[offset][r];
            matrix_inv->values[offset][r] = temp1;

            temp1 = return_matrix->values[k][r];
            return_matrix->values[k][r] = return_matrix->values[offset][r];
            return_matrix->values[offset][r] = temp1;
        }

        // ошибка если дошли до конца

        temp = matrix_inv->values[k][k];
        for (size_t j = 0; j < rows; ++j) {
            matrix_inv->values[k][j] /= temp;
            return_matrix->values[k][j] /= temp;
        }

        for (size_t i = k + 1; i < rows; ++i) {
            temp = matrix_inv->values[i][k];
            for (size_t j = 0; j < rows; ++j) {
                matrix_inv->values[i][j] -= matrix_inv->values[k][j] * temp;
                return_matrix->values[i][j] -= return_matrix->values[k][j] * temp;
            }
        }
    }

    for (size_t k = rows - 1; k > 0; --k) {
        for (size_t i = k - 1; i > 0; --i) {
            temp = matrix_inv->values[i][k];

            for (size_t j = 0; j < rows; ++j) {
                matrix_inv->values[i][j] -= matrix_inv->values[k][j] * temp;
                return_matrix->values[i][j] -= return_matrix->values[k][j] * temp;
            }
        }

        // i = 0
        temp = matrix_inv->values[0][k];

        for (size_t j = 0; j < rows; ++j) {
            matrix_inv->values[0][j] -= matrix_inv->values[k][j] * temp;
            return_matrix->values[0][j] -= return_matrix->values[k][j] * temp;
        }
    }

    free_matrix(matrix_inv);
    return return_matrix;
}
