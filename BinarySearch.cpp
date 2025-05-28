#pragma once

#include <cstdio>
#include <cstdlib>
#include "Point.h"

Point* BinarySearch( Point pointList[], int size, double target )
{
	int left = 0;
	int right = size - 1;
	int mid = 0;

	while ( left <= right )
	{
		mid = ( left + right ) / 2;

		if ( target == pointList[mid].point )
		{
			return &( pointList[mid] );
		}
		else if ( target > pointList[mid].point )
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	return nullptr;
}

int ComparePoint( const void* _elem1, const void* _elem2 )
{
	Point* elem1 = ( Point* ) _elem1;
	Point* elem2 = ( Point* ) _elem2;

	if ( elem1->point > elem2->point )
	{
		return 1;
	}
	else if ( elem1->point < elem2->point )
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

void BinarySearchTest()
{
	int length = sizeof DataSet / sizeof DataSet[0];
	Point* found = nullptr;

	qsort( ( void* ) DataSet, length, sizeof( Point ), ComparePoint );

	found = BinarySearch( DataSet, length, 671.78 );

	printf( "found... ID: %d, Point: %.2f \n", found->id, found->point );
}