#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* CKeyType;
typedef char* CValueType;

typedef struct Node {
	CKeyType Key;
	CValueType Value;

	struct Node* Next;
} ChainingNode;

typedef ChainingNode* List;

typedef struct HashTable {
	int TableSize;
	List* Table;
} ChainingHashTable;

ChainingHashTable* CHT_CreateHashTable( int tableSize );
void CHT_DestroyHashTable( ChainingHashTable* ht );

ChainingNode* CHT_CreateNode( CKeyType key, CValueType value );
void CHT_DestroyNode( ChainingNode* node );

void CHT_Set( ChainingHashTable* ht, CKeyType key, CValueType value );
CValueType CHT_Get( ChainingHashTable* ht, CKeyType key );

int CHT_Hash( CKeyType key, int keyLength, int tableSize );
