#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"

typedef struct OAHTNode
{
	KeyType Key;
	ValueType Value;

	enum ElementStatus Status;
} OAHTNode;

typedef struct OAHashTable
{
	int OccupiedCount;
	int TableSize;

	OAHTNode* Table;
} OAHashTable;

OAHashTable* OAHT_CreateHashTable( int tableSize );
void OAHT_DestroyHashTable( OAHashTable* ht );
void OAHT_DestroyNode( OAHTNode* node );

void OAHT_Set( OAHashTable** ht, KeyType key, ValueType value );
ValueType OAHT_Get( OAHashTable* ht, KeyType key );

int OAHT_Hash( KeyType key, size_t keyLength, int tableSize );
int OAHT_Hash2( KeyType key, size_t keyLength, int tableSize );
void OAHT_Rehash( OAHashTable** ht );

