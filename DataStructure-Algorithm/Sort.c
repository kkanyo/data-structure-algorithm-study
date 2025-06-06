#include "Sort.h"

void MergeSort( int* list, int startIndex, int endIndex )
{
	if ( endIndex - startIndex < 1 )
	{
		return;
	}

	int midIndex = ( startIndex + endIndex ) / 2;

	MergeSort( list, startIndex, midIndex );
	MergeSort( list, midIndex + 1, endIndex );

	Merge( list, startIndex, midIndex, endIndex );
}

void Merge( int* list, int startIndex, int midIndex, int endIndex )
{
	if ( startIndex < 0 || midIndex < 0 || endIndex < 0 ||
		startIndex >= endIndex || midIndex >= endIndex )
	{
		fprintf( stderr, "Invalid indices for merging.\n" );
		return;
	}

	int* destination = ( int* ) malloc( ( endIndex - startIndex + 1 ) * sizeof( int ) );
	if ( destination == NULL )
	{
		fprintf( stderr, "Memory allocation failed.\n" );
		return;
	}

	int leftIndex = startIndex;
	int rightIndex = midIndex + 1;
	int destIndex = 0;

	while ( leftIndex <= midIndex && rightIndex <= endIndex )
	{
		if ( list[leftIndex] < list[rightIndex] )
		{
			destination[destIndex++] = list[leftIndex++];
		}
		else
		{
			destination[destIndex++] = list[rightIndex++];
		}
	}

	while ( leftIndex <= midIndex )
	{
		destination[destIndex++] = list[leftIndex++];
	}

	while ( rightIndex <= endIndex )
	{
		destination[destIndex++] = list[rightIndex++];
	}

	destIndex = 0;
	for ( int i = startIndex; i <= endIndex; i++ )
	{
		list[i] = destination[destIndex++];
	}

	free( destination );
}
