#include "Heap.h"

static int TestHeap( void )
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

	return 0;
}