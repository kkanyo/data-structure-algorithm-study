#include "common.h"

int Compare( const void* a, const void* b )
{
	int _a = *( int* ) a;
	int _b = *( int* ) b;

	if ( _a < _b )
	{
		return 1;
	}
	else
	{
		return -1;
	}
}