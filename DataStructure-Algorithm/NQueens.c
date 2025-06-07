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

	// 위협이 되는 위치라면 반환하여 경우를 폐기한다.
	if ( IsThreatened( columns, row ) )
	{
		return;
	}

	// 마지막 부분해라면 하나의 해가 완성되었다는 의미이다.
	if ( row == numberOfQueens - 1 )
	{
		printf( "Solution %d: \n", ++( *solutionCount ) );
		PrintSolution( columns, numberOfQueens );
	}
	else
	{
		for ( int i = 0; i < numberOfQueens; i++ )
		{
			// 다음 행에 퀸을 둔다고 가정하고 진행한다.
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
		// 수직 방향이나 대각선 방향에는 퀸을 둘 수 없다.
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
