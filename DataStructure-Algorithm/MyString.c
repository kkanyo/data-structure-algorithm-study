#include "MyString.h"

int LCS( char* str1, char* str2, int x, int y, LCSTable* table )
{
	if ( str1 == NULL || str2 == NULL || table == NULL )
	{
		fprintf( stderr, "Invalid input parameters.\n" );
		return -1; // or handle as needed
	}

    for ( int i = 0; i <= x; i++ )
    {
		table->Data[i][0] = 0;
    }

	for ( int j = 0; j <= y; j++ )
	{
		table->Data[0][j] = 0;
	}

	for ( int i = 1; i <= x; i++ )
	{
		for ( int j = 1; j <= y; j++ )
		{
			if ( str1[i - 1] == str2[j - 1] )
			{
				table->Data[i][j] = table->Data[i - 1][j - 1] + 1;
			}
			else
			{
				if ( table->Data[i - 1][j] > table->Data[i][j - 1] )
				{
					table->Data[i][j] = table->Data[i - 1][j];
				}
				else
				{
					table->Data[i][j] = table->Data[i][j - 1];
				}
			}
		}
	}

    return table->Data[x][y];
}

void LCS_TraceBack( char* str1, char* str2, int x, int y, LCSTable* table, char* LCS )
{
	if ( str1 == NULL || str2 == NULL || table == NULL )
	{
		fprintf( stderr, "Invalid input parameters.\n" );
		return; // or handle as needed
	}

	if ( x == 0 || y == 0 )
	{
		return;
	}

	if ( table->Data[x][y] > table->Data[x][y - 1] &&
		table->Data[x][y] > table->Data[x - 1][y] &&
		table->Data[x][y] > table->Data[x - 1][y - 1] )
	{
		const int LEN = 100;
		char tempLCS[100];
		strcpy_s( tempLCS, LEN, LCS );
		sprintf_s( LCS, LEN, "%c%s", str1[x - 1], tempLCS );

		LCS_TraceBack( str1, str2, x - 1, y - 1, table, LCS );
	}
	else if ( table->Data[x][y] > table->Data[x - 1][y] &&
		table->Data[x][y] == table->Data[x][y - 1] )
	{
		LCS_TraceBack( str1, str2, x, y - 1, table, LCS );
	}
	else
	{
		LCS_TraceBack( str1, str2, x - 1, y, table, LCS );
	}
}

void LCS_PrintTable( LCSTable* table, char* str1, char* str2, size_t length1, size_t length2 )
{
	printf( "%4s", " " );

	for ( int i = 0; i < length2 + 1; i++ )
	{
		printf( "%c ", str2[i] );
	}
	printf( "\n" );

	for ( int i = 0; i < length1 + 1; i++ )
	{
		if ( i == 0 )
		{
			printf( "%2s", "" );
		}
		else
		{
			printf( "%-2c", str1[i - 1] );
		}

		for ( int j = 0; j < length2 + 1; j++ )
		{
			printf( "%d ", table->Data[i][j] );
		}

		printf( "\n" );
	}
}
