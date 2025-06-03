#include "Chaining.h"

ChainingHashTable* CHT_CreateHashTable( int tableSize )
{
	ChainingHashTable* ht = ( ChainingHashTable* ) malloc( sizeof( ChainingHashTable ) );
	if ( ht == NULL ) {
		fprintf( stderr, "Memory allocation failed for hash table.\n" );
		return NULL;
	}

	ht->TableSize = tableSize;
	ht->Table = ( List* ) malloc( sizeof( List ) * tableSize );
	if ( ht->Table == NULL ) {
		fprintf( stderr, "Memory allocation failed for hash table table.\n" );
		free( ht );
		return NULL;
	}

	memset( ht->Table, 0, sizeof( List ) * tableSize );

	return ht;
}

void CHT_DestroyHashTable( ChainingHashTable* ht )
{
	for ( int i = 0; i < ht->TableSize; i++ )
	{
		CHT_DestroyNode( ht->Table[i] );
	}

	free( ht->Table );
	free( ht );
}

ChainingNode* CHT_CreateNode( CKeyType key, CValueType value )
{
	ChainingNode* node = ( ChainingNode* ) malloc( sizeof( ChainingNode ) );
	if ( node == NULL ) {
		fprintf( stderr, "Memory allocation failed for node.\n" );
		return NULL;
	}
	
	node->Key = key;
	node->Value = value;
	node->Next = NULL;

	return node;
}

void CHT_DestroyNode( ChainingNode* node )
{
	if ( node == NULL )
	{
		return;
	}

	free( node );
}

void CHT_Set( ChainingHashTable* ht, CKeyType key, CValueType value )
{
	int address = CHT_Hash( key, strlen( key ), ht->TableSize );
	ChainingNode* newNode = CHT_CreateNode( key, value );
	if ( newNode == NULL ) {
		fprintf( stderr, "Failed to create a new node.\n" );
		return;
	}

	if ( ht->Table[address] == NULL )
	{
		ht->Table[address] = newNode;
	}
	else
	{
		newNode->Next = ht->Table[address];
		ht->Table[address] = newNode;

		printf( "Collision detected: Key(%s), Address(%d)\n", key, address );
	}
}

CValueType CHT_Get( ChainingHashTable* ht, CKeyType key )
{
	int address = CHT_Hash( key, strlen( key ), ht->TableSize );

	List list = ht->Table[address];

	if ( list == NULL )
	{
		return NULL;
	}

	while ( strcmp( list->Key, key ) != 0 && list->Next != NULL )
	{
		list = list->Next;
	}

	return list->Value;
}

int CHT_Hash( CKeyType key, int keyLength, int tableSize )
{
	int hashValue = 0;
	
	for ( int i = 0; i < keyLength; i++ )
	{
		hashValue = (hashValue << 3) + key[i];
	}

	return hashValue % tableSize;
}


