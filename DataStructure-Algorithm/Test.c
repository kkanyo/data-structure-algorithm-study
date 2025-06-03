#include "Test.h"

void TestHeap()
{
	Heap* heap = Heap_Create( 3 );
	if ( heap == NULL )
	{
		printf( "Heap creation failed.\n" );
		return -1;
	}

	HeapNode delNode;

	Heap_DeleteMin( heap, &delNode );
	Heap_Insert( heap, 10 );
	Heap_PrintNdoes( heap );

	Heap_DeleteMin( heap, &delNode );
	Heap_PrintNdoes( heap );

	Heap_Insert( heap, 20 );
	Heap_Insert( heap, 5 );
	Heap_Insert( heap, 15 );
	Heap_PrintNdoes( heap );

	Heap_Insert( heap, 30 );
	Heap_Insert( heap, 25 );
	Heap_Insert( heap, 35 );
	Heap_Insert( heap, 10 );
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

	SHT_Set( ht, 418, 32114 );
	SHT_Set( ht, 9, 514 );
	SHT_Set( ht, 27, 8917 );
	SHT_Set( ht, 1031, 286 );

	printf( "Value for key %d: %d\n", 418, SHT_Get( ht, 418 ) );
	printf( "Value for key %d: %d\n", 9, SHT_Get( ht, 9 ) );
	printf( "Value for key %d: %d\n", 27, SHT_Get( ht, 27 ) );
	printf( "Value for key %d: %d\n", 1031, SHT_Get( ht, 1031 ) );

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
	printf( "Key:%s, Value:%s\n", "MSFT", CHT_Get( ht, "MSFT" ) );
	printf( "Key:%s, Value:%s\n", "AMZN", CHT_Get( ht, "AMZN" ) );
	printf( "Key:%s, Value:%s\n", "TSLA", CHT_Get( ht, "TSLA" ) );
	printf( "Key:%s, Value:%s\n", "NFLX", CHT_Get( ht, "NFLX" ) );
	printf( "Key:%s, Value:%s\n", "AAPL", CHT_Get( ht, "AAPL" ) );
	printf( "Key:%s, Value:%s\n", "AMD", CHT_Get( ht, "AMD" ) );
	printf( "Key:%s, Value:%s\n", "NVDA", CHT_Get( ht, "NVDA" ) );
	printf( "Key:%s, Value:%s\n", "GOOG", CHT_Get( ht, "GOOG" ) );
	printf( "Key:%s, Value:%s\n", "INTC", CHT_Get( ht, "INTC" ) );
	printf( "Key:%s, Value:%s\n", "CSCO", CHT_Get( ht, "CSCO" ) );
	printf( "Key:%s, Value:%s\n", "META", CHT_Get( ht, "META" ) );
	printf( "Key:%s, Value:%s\n", "IBM", CHT_Get( ht, "IBM" ) );
	printf( "Key:%s, Value:%s\n", "ORCL", CHT_Get( ht, "ORCL" ) );
	printf( "Key:%s, Value:%s\n", "ADBE", CHT_Get( ht, "ADBE" ) );
	printf( "Key:%s, Value:%s\n", "JAVA", CHT_Get( ht, "JAVA" ) );

	CHT_DestroyHashTable( ht );
}
