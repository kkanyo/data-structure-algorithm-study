#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct Matrix
{
	long long Data[2][2];
} Matrix;

Matrix MatrixMultiply( Matrix a, Matrix b );
Matrix MatrixPower( Matrix matrix, int n );

long long Power( int base, int exponent );

unsigned long Fibonacci( int n );

unsigned long FibonacciDP( int n );

void GetChange( int price, int pay, int coinUnits[], int change[], size_t size );
int CountCoins( int amount, int coinUnit );
void PrintChange( int coinUnits[], int change[], size_t size );