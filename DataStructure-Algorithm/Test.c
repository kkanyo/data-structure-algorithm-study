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

void TestOpenAddressingHashTable()
{
	OAHashTable* ht = OAHT_CreateHashTable( 11 );

	OAHT_Set( &ht, ( void* ) "MSFT", ( void* ) "Microsoft Corporation" );
	OAHT_Set( &ht, ( void* ) "JAVA", ( void* ) "Sun Microsystems" );
	OAHT_Set( &ht, ( void* ) "REDH", ( void* ) "Red Hat Linux" );
	OAHT_Set( &ht, ( void* ) "APAC", ( void* ) "Apache Org" );
	OAHT_Set( &ht, ( void* ) "ZYMZZ", ( void* ) "Unisys Ops Check" );
	OAHT_Set( &ht, ( void* ) "IBM", ( void* ) "IBM Ltd." );
	OAHT_Set( &ht, ( void* ) "ORCL", ( void* ) "Oracle Corporation" );
	OAHT_Set( &ht, ( void* ) "CSCO", ( void* ) "Cisco Systems, Inc" );
	OAHT_Set( &ht, ( void* ) "GOOG", ( void* ) "Google Inc." );
	OAHT_Set( &ht, ( void* ) "YHOO", ( void* ) "Yahoo! inc." );
	OAHT_Set( &ht, ( void* ) "NOVL", ( void* ) "Novell inc." );

	printf( "\n" );
	printf( "Key:%s, Value:%s\n", "MSFT", ( char* ) OAHT_Get( ht, ( void* ) "MSFT" ) );
	printf( "Key:%s, Value:%s\n", "REDH", ( char* ) OAHT_Get( ht, ( void* ) "REDH" ) );
	printf( "Key:%s, Value:%s\n", "APAC", ( char* ) OAHT_Get( ht, ( void* ) "APAC" ) );
	printf( "Key:%s, Value:%s\n", "ZYMZZ", ( char* ) OAHT_Get( ht, ( void* ) "ZYMZZ" ) );
	printf( "Key:%s, Value:%s\n", "JAVA", ( char* ) OAHT_Get( ht, ( void* ) "JAVA" ) );
	printf( "Key:%s, Value:%s\n", "IBM", ( char* ) OAHT_Get( ht, ( void* ) "IBM" ) );
	printf( "Key:%s, Value:%s\n", "ORCL", ( char* ) OAHT_Get( ht, ( void* ) "ORCL" ) );
	printf( "Key:%s, Value:%s\n", "CSCO", ( char* ) OAHT_Get( ht, ( void* ) "CSCO" ) );
	printf( "Key:%s, Value:%s\n", "GOOG", ( char* ) OAHT_Get( ht, ( void* ) "GOOG" ) );
	printf( "Key:%s, Value:%s\n", "YHOO", ( char* ) OAHT_Get( ht, ( void* ) "YHOO" ) );
	printf( "Key:%s, Value:%s\n", "NOVL", ( char* ) OAHT_Get( ht, ( void* ) "NOVL" ) );

	OAHT_DestroyHashTable( ht );
}

void TestGraph()
{
	Graph* graph = CreateGraph();
	if ( graph == NULL )
	{
		printf( "Graph creation failed.\n" );
		return;
	}

	Vertex* v1 = CreateVertex( ( void* ) '1' );
	Vertex* v2 = CreateVertex( ( void* ) '2' );
	Vertex* v3 = CreateVertex( ( void* ) '3' );
	Vertex* v4 = CreateVertex( ( void* ) '4' );
	Vertex* v5 = CreateVertex( ( void* ) '5' );

	AddVertex( graph, v1 );
	AddVertex( graph, v2 );
	AddVertex( graph, v3 );
	AddVertex( graph, v4 );
	AddVertex( graph, v5 );

	AddEdge( v1, CreateEdge( v1, v2, 0 ) );
	AddEdge( v1, CreateEdge( v1, v3, 0 ) );
	AddEdge( v1, CreateEdge( v1, v4, 0 ) );
	AddEdge( v1, CreateEdge( v1, v5, 0 ) );

	AddEdge( v2, CreateEdge( v2, v1, 0 ) );
	AddEdge( v2, CreateEdge( v2, v3, 0 ) );
	AddEdge( v2, CreateEdge( v2, v5, 0 ) );

	AddEdge( v3, CreateEdge( v3, v1, 0 ) );
	AddEdge( v3, CreateEdge( v3, v2, 0 ) );

	AddEdge( v4, CreateEdge( v4, v1, 0 ) );
	AddEdge( v4, CreateEdge( v4, v5, 0 ) );

	AddEdge( v5, CreateEdge( v5, v1, 0 ) );
	AddEdge( v5, CreateEdge( v5, v2, 0 ) );
	AddEdge( v5, CreateEdge( v5, v4, 0 ) );

	PrintGraph( graph );

	DestroyGraph( graph );
}
