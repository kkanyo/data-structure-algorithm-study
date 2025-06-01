#pragma once

#include <cstdio>
#include <cstdlib>

struct DisjointSet
{
	struct DisjointSet* Parent;
	void* Data;
};

void DS_UnionSet( DisjointSet* set1, DisjointSet* set2 );
DisjointSet* DS_FindSet( DisjointSet* set );
DisjointSet* DS_MakeSet( void* newData );
void DS_DestroySet( DisjointSet* set );