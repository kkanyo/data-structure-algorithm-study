#include "Test.h"

void TestHeap()
{
	Heap* heap = Heap_Create( 3 );
	if ( heap == NULL )
	{
		printf( "Heap creation failed.\n" );
		return;
	}

	HeapNode delNode;

	Heap_DeleteMin( heap, &delNode );
	Heap_Insert( heap, ( void* ) 10 );
	Heap_PrintNdoes( heap );

	Heap_DeleteMin( heap, &delNode );
	Heap_PrintNdoes( heap );

	Heap_Insert( heap, ( void* ) 20 );
	Heap_Insert( heap, ( void* ) 5 );
	Heap_Insert( heap, ( void* ) 15 );
	Heap_PrintNdoes( heap );

	Heap_Insert( heap, ( void* ) 30 );
	Heap_Insert( heap, ( void* ) 25 );
	Heap_Insert( heap, ( void* ) 35 );
	Heap_Insert( heap, ( void* ) 10 );
	Heap_PrintNdoes( heap );

	Heap_DeleteMin( heap, &delNode );
	Heap_PrintNdoes( heap );

	Heap_DeleteMin( heap, &delNode );
	Heap_PrintNdoes( heap );

	Heap_DeleteMin( heap, &delNode );
	Heap_PrintNdoes( heap );

	Heap_DeleteMin( heap, &delNode );
	Heap_PrintNdoes( heap );
}

void TestPriorityQueue()
{
	PriorityQueue* pq = PQ_Create( 3 );
	PQNode popped;

	PQNode nodes[7] =
	{
		{34, ( void* ) "코딩"},
		{12, ( void* ) "알고리즘"},
		{87, ( void* ) "자료구조"},
		{45, ( void* ) "프로그래밍"},
		{35, ( void* ) "테스트"},
		{66, ( void* ) "디버깅"},
	};

	PQ_Enqueue( pq, nodes[0] );
	PQ_Enqueue( pq, nodes[1] );
	PQ_Enqueue( pq, nodes[2] );
	PQ_Enqueue( pq, nodes[3] );
	PQ_Enqueue( pq, nodes[4] );
	PQ_Enqueue( pq, nodes[5] );

	printf( "Number of elements in the priority queue: %d\n", pq->UsedSize );
	while ( !PQ_IsEmpty( pq ) )
	{
		PQ_Dequeue( pq, &popped );
		PQ_PrintNode( &popped );
	}

	PQ_Destroy( pq );
}

void TestSimpleHashTable()
{
	SimpleHashTable* ht = SHT_Create( 193 );
	if ( ht == NULL )
	{
		printf( "Hash table creation failed.\n" );
		return;
	}

	SHT_Set( ht, ( void* ) 418, ( void* ) 32114 );
	SHT_Set( ht, ( void* ) 9, ( void* ) 514 );
	SHT_Set( ht, ( void* ) 27, ( void* ) 8917 );
	SHT_Set( ht, ( void* ) 1031, ( void* ) 286 );

	printf( "Value for key %d: %lld\n", 418, ( long long )SHT_Get( ht, ( void* ) 418 ) );
	printf( "Value for key %d: %lld\n", 9, ( long long )SHT_Get( ht, ( void* ) 9 ) );
	printf( "Value for key %d: %lld\n", 27, ( long long )SHT_Get( ht, ( void* ) 27 ) );
	printf( "Value for key %d: %lld\n", 1031, ( long long )SHT_Get( ht, ( void* ) 1031 ) );

	SHT_DestroyHashTable( ht );
}

void TestChainingHashTable()
{
	ChainingHashTable* ht = CHT_CreateHashTable( 12289 );
	
	CHT_Set( ht, "MSFT", "Microsoft Corporation" );
	CHT_Set( ht, "JAVA", "Sun Microsystems" );
	CHT_Set( ht, "GOOG", "Google Inc." );
	CHT_Set( ht, "AMZN", "Amazon.com Inc." );
	CHT_Set( ht, "AAPL", "Apple Inc." );
	CHT_Set( ht, "TSLA", "Tesla Inc." );
	CHT_Set( ht, "META", "Meta Platforms Inc." );
	CHT_Set( ht, "NFLX", "Netflix Inc." );
	CHT_Set( ht, "NVDA", "NVIDIA Corporation" );
	CHT_Set( ht, "INTC", "Intel Corporation" );
	CHT_Set( ht, "AMD", "Advanced Micro Devices Inc." );
	CHT_Set( ht, "IBM", "International Business Machines Corporation" );
	CHT_Set( ht, "ORCL", "Oracle Corporation" );
	CHT_Set( ht, "CSCO", "Cisco Systems Inc." );
	CHT_Set( ht, "ADBE", "Adobe Inc." );

	printf( "\n" );
	printf( "Key:%s, Value:%s\n", "MSFT", ( char* )CHT_Get( ht, "MSFT" ) );
	printf( "Key:%s, Value:%s\n", "AMZN", ( char* )CHT_Get( ht, "AMZN" ) );
	printf( "Key:%s, Value:%s\n", "TSLA", ( char* )CHT_Get( ht, "TSLA" ) );
	printf( "Key:%s, Value:%s\n", "NFLX", ( char* )CHT_Get( ht, "NFLX" ) );
	printf( "Key:%s, Value:%s\n", "AAPL", ( char* )CHT_Get( ht, "AAPL" ) );
	printf( "Key:%s, Value:%s\n", "AMD", ( char* )CHT_Get( ht, "AMD" ) );
	printf( "Key:%s, Value:%s\n", "NVDA", ( char* )CHT_Get( ht, "NVDA" ) );
	printf( "Key:%s, Value:%s\n", "GOOG", ( char* )CHT_Get( ht, "GOOG" ) );
	printf( "Key:%s, Value:%s\n", "INTC", ( char* )CHT_Get( ht, "INTC" ) );
	printf( "Key:%s, Value:%s\n", "CSCO", ( char* )CHT_Get( ht, "CSCO" ) );
	printf( "Key:%s, Value:%s\n", "META", ( char* )CHT_Get( ht, "META" ) );
	printf( "Key:%s, Value:%s\n", "IBM", ( char* )CHT_Get( ht, "IBM" ) );
	printf( "Key:%s, Value:%s\n", "ORCL", ( char* )CHT_Get( ht, "ORCL" ) );
	printf( "Key:%s, Value:%s\n", "ADBE", ( char* )CHT_Get( ht, "ADBE" ) );
	printf( "Key:%s, Value:%s\n", "JAVA", ( char* )CHT_Get( ht, "JAVA" ) );

	CHT_DestroyHashTable( ht );
}
