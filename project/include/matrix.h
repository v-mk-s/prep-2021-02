#ifndef  PROJECT_INCLUDE_MATRIX_H_
#define  PROJECT_INCLUDE_MATRIX_H_

#define EPS    1e-8

#define NON_STANDARD_ERROR    -1
#define NULL_MATRIX           -2
#define BOUNDARY_ERROR        -3

#include <stddef.h>

typedef struct Matrix {
    double** vals;
    size_t rows;
    size_t cols;
} Matrix;

// Init/release operations
Matrix* create_matrix_from_file(const char* path_file);
Matrix* create_matrix(size_t rows, size_t cols);
void free_matrix(Matrix* matrix);

// Custom operations
int print(const Matrix* matrix);  // вывод матрицы в консоль
Matrix* copy(const Matrix* matrix);
// для детерминанта, матрица с удаленной строкой и столбцом
Matrix* matrix_without_row_and_col(const Matrix* matrix, size_t row, size_t col);

// Basic operations
int get_rows(const Matrix* matrix, size_t* rows);
int get_cols(const Matrix* matrix, size_t* cols);
int get_elem(const Matrix* matrix, size_t row, size_t col, double* val);
int set_elem(Matrix* matrix, size_t row, size_t col, double val);

// Math operations
Matrix* mul_scalar(const Matrix* matrix, double val);
Matrix* transp(const Matrix* matrix);

Matrix* sum(const Matrix* l, const Matrix* r);
Matrix* sub(const Matrix* l, const Matrix* r);
Matrix* mul(const Matrix* l, const Matrix* r);

// Extra operations
int det(const Matrix* matrix, double* val);
Matrix* adj(const Matrix* matrix);
Matrix* inv(const Matrix* matrix);


#endif  // PROJECT_INCLUDE_MATRIX_H_
