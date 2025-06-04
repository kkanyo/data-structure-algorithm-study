#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"

typedef struct ChainingNode {
	KeyType Key;
	ValueType Value;

	struct ChainingNode* Next;
} ChainingNode;

typedef ChainingNode* List;

typedef struct ChainingHashTable {
	int TableSize;
	List* Table;
} ChainingHashTable;

ChainingHashTable* CHT_CreateHashTable( int tableSize );
void CHT_DestroyHashTable( ChainingHashTable* ht );

ChainingNode* CHT_CreateNode( KeyType key, ValueType value );
void CHT_DestroyNode( ChainingNode* node );

void CHT_Set( ChainingHashTable* ht, KeyType key, ValueType value );
ValueType CHT_Get( ChainingHashTable* ht, KeyType key );

int CHT_Hash( KeyType key, size_t keyLength, int tableSize );
