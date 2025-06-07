#include "NQueens.h"

void FindSolutionForQueen( int columns[], int row, int numberOfQueens, int* solutionCount )
{
	if ( columns == NULL )
	{
		return;
	}

	if ( row < 0 )
	{
		return;
	}

	if ( numberOfQueens < 1 )
	{
		return;
	}

	if ( solutionCount == NULL )
	{
		return;
	}

	// ������ �Ǵ� ��ġ��� ��ȯ�Ͽ� ��츦 ����Ѵ�.
	if ( IsThreatened( columns, row ) )
	{
		return;
	}

	// ������ �κ��ض�� �ϳ��� �ذ� �ϼ��Ǿ��ٴ� �ǹ��̴�.
	if ( row == numberOfQueens - 1 )
	{
		printf( "Solution %d: \n", ++( *solutionCount ) );
		PrintSolution( columns, numberOfQueens );
	}
	else
	{
		for ( int i = 0; i < numberOfQueens; i++ )
		{
			// ���� �࿡ ���� �дٰ� �����ϰ� �����Ѵ�.
			columns[row + 1] = i;
			FindSolutionForQueen( columns, row + 1, numberOfQueens, solutionCount );
		}
	}
}

int IsThreatened( int columns[], int newRow )
{
	int currentRow = 0;
	int threatened = 0;

	while ( currentRow < newRow )
	{
		// ���� �����̳� �밢�� ���⿡�� ���� �� �� ����.
		if ( columns[newRow] == columns[currentRow] ||
			abs( columns[newRow] - columns[currentRow] ) == abs( newRow - currentRow ) )
		{
			threatened = 1;
			break;
		}

		currentRow++;
	}

	return threatened;
}

void PrintSolution( int columns[], int numberOfQueens )
{
	for ( int i = 0; i < numberOfQueens; i++ )
	{
		for ( int j = 0; j < numberOfQueens; j++ )
		{
			if ( columns[i] == j )
			{
				printf( "Q" );
			}
			else
			{
				printf( "X" );
			}
		}
		printf( "\n" );
	}
	printf( "\n" );
}
