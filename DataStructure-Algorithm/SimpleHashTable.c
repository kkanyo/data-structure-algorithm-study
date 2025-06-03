#include "SimpleHashTable.h"

SimpleHashTable* SHT_Create( int tableSize )
{
	if ( tableSize <= 0 )
	{
		printf( "Invalid table size: %d\n", tableSize );
		return NULL; // 에러 처리
	}

	SimpleHashTable* ht = ( SimpleHashTable* ) malloc( sizeof( SimpleHashTable ) );
	if ( ht == NULL )
	{
		printf( "Memory allocation failed for SimpleHashTable.\n" );
		return NULL;
	}

	ht->TableSize = tableSize;
	ht->Table = ( SimpleHashNode* ) malloc( sizeof( SimpleHashNode ) * ht->TableSize );
	if ( ht->Table == NULL )
	{
		printf( "Memory allocation failed for hash table.\n" );
		free( ht );
		return NULL;
	}

	return ht;
}

void SHT_DestroyHashTable( SimpleHashTable* ht )
{
	if ( ht == NULL )
	{
		return;
	}

	free( ht->Table );
	free( ht );
}

void SHT_Set( SimpleHashTable* ht, KeyType key, ValueType value )
{
	int address = SHT_Hash( key, ht->TableSize );
	if ( address < 0 || address >= ht->TableSize )
	{
		printf( "Hash address out of bounds: %d\n", address );
		return;
	}

	ht->Table[address].Key = key;
	ht->Table[address].Value = value;
}

ValueType SHT_Get( SimpleHashTable* ht, KeyType key )
{
	int address = SHT_Hash( key, ht->TableSize );
	if ( address < 0 || address >= ht->TableSize )
	{
		printf( "Hash address out of bounds: %d\n", address );
		return -1; // 다른 에러 값을 반환할 수 있다.
	}

	return ht->Table[address].Value;
}

int SHT_Hash( KeyType key, int tableSize )
{
	return key % tableSize;
}



	