#include "Math.h"

Matrix MatrixMultiply( Matrix a, Matrix b )
{
	return ( Matrix ) {
		{
			{
				a.Data[0][0] * b.Data[0][0] + a.Data[0][1] * b.Data[1][0],
					a.Data[0][0] * b.Data[0][1] + a.Data[0][1] * b.Data[1][1]
			},
			{
				a.Data[1][0] * b.Data[0][0] + a.Data[1][1] * b.Data[1][0],
			  a.Data[1][0] * b.Data[0][1] + a.Data[1][1] * b.Data[1][1]
			}
		}
	};
}


Matrix MatrixPower( Matrix matrix, int n )
{
	if ( n < 0 )
	{
		fprintf( stderr, "Negative exponent is not supported for matrix power.\n" );
		return ( Matrix ) { { { -1, -1 }, { -1, -1 } } }; // or handle as needed
	}

	if ( n > 1 )
	{
		matrix = MatrixPower( matrix, n / 2 );
		matrix = MatrixMultiply( matrix, matrix );

		if ( n & 1 )
		{
			Matrix base = { { { 1, 1 }, { 1, 0 } } };
			return MatrixMultiply( matrix, base );
		}
	}

	return matrix;
}

long long Power( int base, int exponent )
{
	if ( exponent < 0 )
	{
		fprintf( stderr, "Negative exponent is not supported.\n" );
		return -1; // or handle as needed
	}

	if ( base == 0 )
	{
		return 0;
	}
	else if ( base == 1 || exponent == 0 )
	{
		return 1;
	}
	else if ( exponent == 1 )
	{
		return base;
	}

	if ( exponent % 2 == 0 )
	{
		long long newBase = Power( base, exponent / 2 );
		return newBase * newBase;
	}
	else
	{
		long long newBase = Power( base, (exponent - 1 ) / 2 );
		return newBase * newBase * base;
	}
}

unsigned long Fibonacci( int n )
{
	Matrix fibonacci = { { { 1, 1 }, { 1, 0 } } };

	fibonacci = MatrixPower( fibonacci, n );

	return fibonacci.Data[0][1];
}

unsigned long FibonacciDP( int n )
{
	if ( n == 0 || n == 1 )
	{
		return n;
	}

	unsigned long result = 0;
	unsigned long* FibonacciTable = ( unsigned long* ) malloc( ( n + 1 ) * sizeof( unsigned long ) );
	if ( FibonacciTable == NULL )
	{
		fprintf( stderr, "Memory allocation failed.\n" );
		return 0; // or handle as needed
	}

	FibonacciTable[0] = 0;
	FibonacciTable[1] = 1;

	for ( int i = 2; i <= n; i++ )
	{
		FibonacciTable[i] = FibonacciTable[i - 1] + FibonacciTable[i - 2];
	}

	result = FibonacciTable[n];

	free( FibonacciTable );

	return result;
}

void GetChange( int price, int pay, int coinUnits[], int change[], size_t size )
{
	int changeAmount = pay - price;

	for ( int i = 0; i < size; i++ )
	{
		change[i] = CountCoins( changeAmount, coinUnits[i] );
		changeAmount -= coinUnits[i] * change[i];
	}
}

int CountCoins( int amount, int coinUnit )
{
	int coinCount = 0;
	int currentAmmount = amount;

	while ( currentAmmount >= coinUnit )
	{
		coinCount++;
		currentAmmount -= coinUnit;
	}

	return coinCount;
}

void PrintChange( int coinUnits[], int change[], size_t size )
{
	for ( int i = 0; i < size; i++ )
	{
		printf( "%8d¿ø: %d°³\n", coinUnits[i], change[i] );
	}
}

