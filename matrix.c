#include "matrix.h"

void matrix_vector_mul(int rows, int cols, double matrix[][cols], double vector[], double result[]) {
    for (int i = 0; i < rows; i++) {
        result[i] = 0.0;
        for (int j = 0; j < cols; j++) {
            result[i] += matrix[i][j] * vector[j];
        }
    }
}

void vector_add(int size, double vector1[], double vector2[], double result[]) {
    for (int i = 0; i < size; i++) {
        result[i] = vector1[i] + vector2[i];
    }
}

void apply_function(int size, double vector[], double (*func)(double), double result[]) {
    for (int i = 0; i < size; i++) {
        result[i] = func(vector[i]);
    }
}

double relu(double x) {
    return (x > 0) ? x : 0;
}
