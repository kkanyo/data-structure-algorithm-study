#include "DisjointSet.h"

void DS_UnionSet( DisjointSet* set1, DisjointSet* set2 )
{
	set2 = DS_FindSet( set2 );
	set2->Parent = set1;
}

DisjointSet* DS_FindSet( DisjointSet* set )
{
	while ( set->Parent != nullptr )
	{
		set = set->Parent;
	}

	return set;
}

DisjointSet* DS_MakeSet( void* newData )
{
	DisjointSet* newNode = ( DisjointSet* ) malloc( sizeof( DisjointSet ) );
	if ( newNode == nullptr )
	{
		return nullptr;
	}
	newNode->Data = newData;
	newNode->Parent = NULL;

	return newNode;
}

void DS_DestroySet( DisjointSet* set )
{
	free( set );
}
