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