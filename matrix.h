#ifndef MATRIX_H
#define MATRIX_H

void matrix_vector_mul(int rows, int cols, double matrix[][4], double vector[], double result[]);
void vector_add(int size, double vector1[], double vector2[], double result[]);
void apply_function(int size, double vector[], double (*func)(double), double result[]);
double relu(double x);

#endif
