#pragma once

#include <stdio.h>
#include <stdlib.h>

#include "common.h"

typedef struct SimpleHashNode
{
	KeyType Key;
	ValueType Value;
} SimpleHashNode;

typedef struct SimpleHashTable
{
	int TableSize;
	SimpleHashNode* Table;
} SimpleHashTable;

SimpleHashTable* SHT_Create( int tableSize );
void SHT_DestroyHashTable( SimpleHashTable* ht );

void SHT_Set( SimpleHashTable* ht, KeyType key, ValueType value );
ValueType SHT_Get( SimpleHashTable* ht, KeyType key );

int SHT_Hash( KeyType key, int tableSize );

