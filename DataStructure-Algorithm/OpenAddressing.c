#include "OpenAddressing.h"

OAHashTable* OAHT_CreateHashTable( int TableSize )
{
	OAHashTable* ht = ( OAHashTable* ) malloc( sizeof( OAHashTable ) );
	if ( ht == NULL )
	{
		fprintf( stderr, "Memory allocation failed for hash table.\n" );
		return NULL;
	}

	ht->OccupiedCount = 0;
	ht->TableSize = TableSize;
	ht->Table = ( OAHTNode* ) malloc( sizeof( OAHTNode ) * ht->TableSize );
	if ( ht->Table == NULL )
	{
		fprintf( stderr, "Memory allocation failed for hash table nodes.\n" );
		free( ht );
		return NULL;
	}
	
	memset( ht->Table, 0, sizeof( OAHTNode ) * ht->TableSize );

	return ht;
}

void OAHT_DestroyHashTable( OAHashTable* ht )
{
	if ( ht == NULL )
	{
		return;
	}

	for ( int i = 0; i < ht->TableSize; i++ )
	{	
		OAHT_DestroyNode( &ht->Table[i] );
	}

	free( ht->Table );
	free( ht );
}

void OAHT_DestroyNode( OAHTNode* node )
{
	if ( node == NULL || node->Status == EMPTY )
	{
		return;
	}
}

void OAHT_Set( OAHashTable** ht, KeyType key, ValueType value )
{
	if ( *ht == NULL )
	{
		return;
	}

	if ( ( *ht )->OccupiedCount * 2 > ( *ht )->TableSize )
	{
		OAHT_Rehash( ht );
	}

	size_t keyLen = strlen(key);
	int address = OAHT_Hash( key, keyLen, ( *ht )->TableSize );
	int stepSize = OAHT_Hash2( key, keyLen, ( *ht )->TableSize );

	while ( ( *ht )->Table[address].Status != EMPTY &&
		strcmp( ( *ht )->Table[address].Key, key ) != 0 )
	{
		printf( "Collision occured! : Key(%s), Address(%d), StepSize(%d)n",
			( char* ) key, address, stepSize );
		address = ( address + stepSize ) % ( *ht )->TableSize;
	}

	( *ht )->Table[address].Key = key;


	( *ht )->Table[address].Value = value;
	( *ht )->Table[address].Status = OCCUPIED;
	( *ht )->OccupiedCount++;

	printf( "Key(%s) entered at address(%d)\n", ( char* ) key, address );
}

ValueType OAHT_Get( OAHashTable* ht, KeyType key )
{
	if ( ht == NULL )
	{
		return NULL;
	}

	size_t keyLen = strlen( key );
	int address = OAHT_Hash( key, keyLen, ht->TableSize );
	int stepSize = OAHT_Hash2( key, keyLen, ht->TableSize );

	while ( ht->Table[address].Status != EMPTY &&
		strcmp( ht->Table[address].Key, key ) != 0 )
	{
		address = ( address + stepSize ) % ht->TableSize;
	}

	return ht->Table[address].Value;
}

int OAHT_Hash( KeyType key, size_t keyLength, int tableSize )
{
	int hashValue = 0;

	for ( size_t i = 0; i < keyLength; i++ )
	{
		hashValue = ( hashValue << 3 ) + ( ( char* ) key )[i];
	}

	return hashValue % tableSize;
}

int OAHT_Hash2( KeyType key, size_t keyLength, int tableSize )
{
	int hashValue = 0;

	for ( size_t i = 0; i < keyLength; i++ )
	{
		hashValue = ( hashValue << 2 ) + ( ( char* ) key )[i];
	}

	return hashValue % ( tableSize - 3 ) + 1;
}

void OAHT_Rehash( OAHashTable** ht )
{
	OAHTNode* oldTable = ( *ht )->Table;

	OAHashTable* newHT = OAHT_CreateHashTable( ( *ht )->TableSize * 2 );

	printf( "Rehashed. New table size is :%d\n\n", newHT->TableSize );

	for ( int i = 0; i < ( *ht )->TableSize; i++ )
	{
		if ( oldTable[i].Status == OCCUPIED )
		{
			OAHT_Set( &newHT, oldTable[i].Key, oldTable[i].Value );
		}
	}

	OAHT_DestroyHashTable( *ht );

	*ht = newHT;
}
