#pragma once

#include <stdio.h>

typedef struct Matrix
{
	long long Data[2][2];
} Matrix;

Matrix MatrixMultiply( Matrix a, Matrix b );
Matrix MatrixPower( Matrix matrix, int n );

long long Power( int base, int exponent );

unsigned long Fibonacci( int n );