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
    FILE* file_matrix_data = fopen(path_file, "r");
    int check_matrix_dim = fscanf(file_matrix_data, "%zu%zu", &rows, &cols);

    // проверка на правильность rows, cols в 1й строке файла
    if (check_matrix_dim != 2) {
        if (check_matrix_dim == EOF) {
            puts("ERROR EOF!");
        } else {
            puts("ERROR invalid file (false structure)!");
        }
        fclose(file_matrix_data);
        return NULL;
    }

    // создание указателя на структуру Matrix и инициализация
    Matrix* matrix_from_file = NULL;
    matrix_from_file = (Matrix*) malloc(sizeof(Matrix));

    matrix_from_file->rows = rows;
    matrix_from_file->cols = cols;
    matrix_from_file->vals = NULL;

    // выделение памяти для значений матрицы
    matrix_from_file->vals = (double**) malloc(rows * sizeof(double*));
        for (size_t i = 0; i < rows; ++i) {
            matrix_from_file->vals[i] = (double*) malloc(cols * sizeof(double));
        }

    // Matrix = 0
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            matrix_from_file->vals[i][j] = 0;
        }
    }

    // инициализация матрицы из файла
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            fscanf(file_matrix_data, "%lf", &matrix_from_file->vals[i][j]);
        }
    }

    // проверка на конец файла
    double temp = 0.0;
    int end_of_file = fscanf(file_matrix_data, "%lf", &temp);
    if (end_of_file != EOF) {
        puts("ERROR invalid file, there is more vals!");

        free_matrix(matrix_from_file);
        fclose(file_matrix_data);
        return NULL;
    }

    fclose(file_matrix_data);
    return matrix_from_file;
}

Matrix* create_matrix(size_t rows, size_t cols) {
    if ((!rows) || (!cols)) {
        return NULL;
    }

    Matrix* matrix_zero = (Matrix*) malloc(sizeof(Matrix));
    matrix_zero->rows = rows;
    matrix_zero->cols = cols;

    matrix_zero->vals = (double**) malloc(rows * sizeof(double*));
    for (size_t i = 0; i < rows; ++i) {
        matrix_zero->vals[i] = (double*) malloc(cols * sizeof(double));
    }

    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            matrix_zero->vals[i][j] = 0;
        }
    }

    return matrix_zero;
}

void free_matrix(Matrix* matrix) {
    if (matrix) {
        size_t rows = matrix->rows;
        for (size_t i = 0; i < rows; ++i) {
            free(matrix->vals[i]);
        }
        free(matrix->vals);
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
            printf("%12.2f", matrix->vals[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}

Matrix* copy(const Matrix* matrix) {
    if (!matrix) {
        return NULL;
    }

    size_t rows = matrix->rows;
    size_t cols = matrix->cols;

    Matrix* return_matrix = NULL;
    return_matrix = create_matrix(rows, cols);
    if (!return_matrix) {
        return NULL;
    }

    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            return_matrix->vals[i][j] = matrix->vals[i][j];
        }
    }
    return return_matrix;
}

Matrix* matrix_without_row_and_col(const Matrix* matrix, size_t row, size_t col) {
    if (!matrix) {
        return NULL;
    }

    if (matrix->rows != matrix->cols) {
        return NULL;
    }

    size_t rows = matrix->rows;
    Matrix* return_matrix = NULL;
    return_matrix = create_matrix(rows-1, rows-1);
    if (!return_matrix) {
        return NULL;
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
            return_matrix->vals[i][j] = matrix->vals[i + offset_row][j + offset_col];
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

    if ((row > rows) || (col > cols)) {
        return BOUNDARY_ERROR;
    }

    *val = matrix->vals[row][col];

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

    matrix->vals[row][col] = val;

    return 0;
}

// Math operations
Matrix* mul_scalar(const Matrix* matrix, double val) {
    if (!matrix) {
        return NULL;
    }

    size_t rows = matrix->rows;
    size_t cols = matrix->cols;

    Matrix* return_matrix = NULL;
    return_matrix = copy(matrix);
    if (!return_matrix) {
        return NULL;
    }

    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            return_matrix->vals[i][j] = val * matrix->vals[i][j];
        }
    }
    return return_matrix;
}

Matrix* transp(const Matrix* matrix) {
    if (!matrix) {
        return NULL;
    }

    size_t rows = matrix->rows;
    size_t cols = matrix->cols;

    Matrix* return_matrix = NULL;
    return_matrix = create_matrix(cols, rows);
    if (!return_matrix) {
        return NULL;
    }

    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            return_matrix->vals[j][i] = matrix->vals[i][j];
        }
    }
    return return_matrix;
}


Matrix* sum(const Matrix* l, const Matrix* r) {
    if (!l || !r) {
        return NULL;
    }

    size_t rows = l->rows;
    size_t cols = l->cols;

    if ((r->rows != rows) || (r->cols != cols)) {
        return NULL;
    }

    Matrix* return_matrix = NULL;
    return_matrix = copy(l);
    if (!return_matrix) {
        return NULL;
    }

    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            return_matrix->vals[i][j] += r->vals[i][j];
        }
    }
    return return_matrix;
}

Matrix* sub(const Matrix* l, const Matrix* r) {
    if (!l || !r) {
        return NULL;
    }

    size_t rows = l->rows;
    size_t cols = l->cols;

    if ((r->rows != rows) || (r->cols != cols)) {
        return NULL;
    }

    Matrix* return_matrix = NULL;
    return_matrix = copy(l);
    if (!return_matrix) {
        return NULL;
    }

    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            return_matrix->vals[i][j] -= r->vals[i][j];
        }
    }
    return return_matrix;
}

Matrix* mul(const Matrix* l, const Matrix* r) {
    if (!l || !r) {
        return NULL;
    }

    size_t l_rows = l->rows;
    size_t l_cols = l->cols;
    size_t r_rows = r->rows;
    size_t r_cols = r->cols;

    if (l_cols != r_rows) {
        return NULL;
    }

    Matrix* return_matrix = NULL;
    return_matrix = create_matrix(l_rows, r_cols);
    if (!return_matrix) {
        return NULL;
    }

    double temp;
    for (size_t i = 0; i < l_rows; ++i) {
        for (size_t j = 0; j < r_cols; ++j) {
            temp = 0;
            for (size_t k = 0; k < l_cols; ++k) {
                temp += l->vals[i][k]*r->vals[k][j];
            }
            return_matrix->vals[i][j] = temp;
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
        *val = matrix->vals[0][0];
        return 0;
    }

    if (rows == 2) {
        *val = (matrix->vals[0][0])*(matrix->vals[1][1]) -
                (matrix->vals[0][1])*(matrix->vals[1][0]);
        return 0;
    }

    Matrix* return_matrix = NULL;
    return_matrix = create_matrix(rows-1, rows-1);
    if (!return_matrix) {
        return NULL_MATRIX;
    }

    double determinant = 0;
    double det_without_row_and_col = 0;
    int degree = 1;
    for (size_t i = 0; i < rows; ++i) {
        return_matrix = matrix_without_row_and_col(matrix, 0, i);

        size_t error = det(return_matrix, &det_without_row_and_col);
        if (error) {
            return NON_STANDARD_ERROR;
        }
        determinant += degree * matrix->vals[0][i] * det_without_row_and_col;

        degree = -degree;
    }

    free_matrix(return_matrix);
    *val = determinant;
    return 0;
}

Matrix* adj(const Matrix* matrix) {
    // присоединенная = обратная * определитель
    if (!matrix) {
        return NULL;
    }

    size_t rows = matrix->rows;
    size_t cols = matrix->cols;

    if (rows != cols) {
        return NULL;
    }

    Matrix* inv_matrix = NULL;
    inv_matrix = inv(matrix);
    if (!inv_matrix) {
        return NULL;
    }

    double determinant = 0;
    int error = det(matrix, &determinant);
    if (error || (fabs(determinant) < EPS)) {
        free_matrix(inv_matrix);
        return NULL;
    }

    Matrix* return_matrix = NULL;
    return_matrix = mul_scalar(inv_matrix, determinant);
    if (!return_matrix) {
        free_matrix(inv_matrix);
        return NULL;
    }

    free_matrix(inv_matrix);
    return return_matrix;
}

Matrix* inv(const Matrix* matrix) {
    if (!matrix) {
        return NULL;
    }

    size_t rows = matrix->rows;
    size_t cols = matrix->cols;

    if (rows != cols) {
        return NULL;
    }

    // если определитель = 0 -> NULL
    double determinant = 0;
    int error = det(matrix, &determinant);
    if (error || (fabs(determinant) < EPS)) {
        return NULL;
    }

    Matrix* return_matrix = NULL;
    return_matrix = create_matrix(rows, rows);
    if (!return_matrix) {
        return NULL;
    }

    if (rows == 1) {
        return_matrix->vals[0][0] = 1/matrix->vals[0][0];
        return return_matrix;
    }

    // единичная матрица
    for (size_t i = 0; i < rows; ++i) {
        return_matrix->vals[i][i] = 1;
    }

    // копия исходной матрицы
    Matrix* matrix_inv = NULL;
    matrix_inv = copy(matrix);
    if (!matrix_inv) {
        free_matrix(return_matrix);
        return NULL;
    }

    // вычисление обратной матрицы
    double temp, temp1;
    for (size_t k = 0; k < rows; ++k) {
        // поиск не равного нулю в столбце элемента
        size_t offset = k;
        temp = matrix_inv->vals[offset][k];
        while ((fabs(temp) < EPS) && (offset < rows)) {
            ++offset;
            temp = matrix_inv->vals[offset][k];
        }

        // поменяли 2 строки местами
        for (size_t r = 0; r < rows; ++r) {
            temp1 = matrix_inv->vals[k][r];
            matrix_inv->vals[k][r] = matrix_inv->vals[offset][r];
            matrix_inv->vals[offset][r] = temp1;

            temp1 = return_matrix->vals[k][r];
            return_matrix->vals[k][r] = return_matrix->vals[offset][r];
            return_matrix->vals[offset][r] = temp1;
        }

        // ошибка если дошли до конца

        temp = matrix_inv->vals[k][k];
        for (size_t j = 0; j < rows; ++j) {
            matrix_inv->vals[k][j] /= temp;
            return_matrix->vals[k][j] /= temp;
        }

        for (size_t i = k + 1; i < rows; ++i) {
            temp = matrix_inv->vals[i][k];
            for (size_t j = 0; j < rows; ++j) {
                matrix_inv->vals[i][j] -= matrix_inv->vals[k][j] * temp;
                return_matrix->vals[i][j] -= return_matrix->vals[k][j] * temp;
            }
        }
    }

    for (size_t k = rows - 1; k > 0; --k) {
        for (size_t i = k - 1; i > 0; --i) {
            temp = matrix_inv->vals[i][k];

            for (size_t j = 0; j < rows; ++j) {
                matrix_inv->vals[i][j] -= matrix_inv->vals[k][j] * temp;
                return_matrix->vals[i][j] -= return_matrix->vals[k][j] * temp;
            }
        }

        // i = 0
        temp = matrix_inv->vals[0][k];

        for (size_t j = 0; j < rows; ++j) {
            matrix_inv->vals[0][j] -= matrix_inv->vals[k][j] * temp;
            return_matrix->vals[0][j] -= return_matrix->vals[k][j] * temp;
        }
    }

    free_matrix(matrix_inv);
    return return_matrix;
}
