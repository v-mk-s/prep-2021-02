#include "matrix.h"
#include <stdio.h>

// #define FILENAME_MATRIX_A "matrix_A_3_4.dat"
// #define FILENAME_MATRIX_B "matrix_B_3_4.dat"
// #define FILENAME_MATRIX_C "matrix_C_4_2.dat"

int main(void) {
    Matrix* A = NULL;
    A = create_matrix_from_file("in.txt");

    Matrix* B = NULL;
    B = create_matrix_from_file("out.txt");

    Matrix* C = NULL;
    C = adj(A);

    if (!A || !B || !C) {
        puts("ERROR MAIN!");
    } else {
        puts("SUCCESS!");
    }

    print(A);
    print(B);
    print(C);
    // double determinant = 0;
    // det(A, &determinant);
    // printf("%lf\n", determinant);
    // print(B);
    // print(C);

    if (A) free_matrix(A);
    if (B) free_matrix(B);
    if (C) free_matrix(C);
    return 0;
}

