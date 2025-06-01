#include "Heap.h"

Heap* Heap_Create( int initialSize )
{
	Heap* newHeap = ( Heap* ) malloc( sizeof( Heap ) );
	if ( newHeap == NULL ) 
	{
		printf( "Heap alloc failed!\n" );
		return NULL;
	}
	
	newHeap->Capacity = initialSize;
	newHeap->UsedSize = 0;
	newHeap->Nodes = ( HeapNode* ) malloc( sizeof( HeapNode ) * newHeap->Capacity );

	printf( "size : %I64u\n", sizeof( HeapNode ) );

	return newHeap;
}

void Heap_Destroy( Heap* heap )
{
	free( heap->Nodes );
	free( heap );
}

int heap_realloc( Heap* heap )
{
	if ( heap == NULL )
	{
		printf( "Heap is NULL\n" );
		return 0;
	}

	int newCapacity = 0;

	if ( heap->UsedSize >= heap->Capacity )
	{
		newCapacity = heap->Capacity * 2;
	}
	else if ( heap->UsedSize < ( heap->Capacity / 2 ) )
	{
		newCapacity = heap->Capacity / 2;
	}
	else
	{
		printf( "No need to reallocate, current size: %d, capacity: %d\n", heap->UsedSize, heap->Capacity );
		return 1;
	}

	HeapNode* temp = ( HeapNode* ) realloc( heap->Nodes, sizeof( HeapNode ) * newCapacity );
	if ( heap->Nodes == NULL )
	{
		printf( "Heap realloc failed!\n" );
		return 0;
	}

	heap->Capacity = newCapacity;
	heap->Nodes = temp;

	return 1;
}

void Heap_Insert( Heap* heap, ElementType newData )
{
	if ( heap == NULL )
	{
		printf( "Heap is NULL\n" );
		return;
	}
	
	int curPos = heap->UsedSize;
	int parnetPos = Heap_GetParent( curPos );

	heap->UsedSize++;

	if ( !heap_realloc( heap ) )
	{
		return;
	}

	heap->Nodes[curPos].Data = newData;

	// �θ� ��庸�� ������ �θ� ���� ��ȯ
	while ( curPos > 0 && heap->Nodes[curPos].Data < heap->Nodes[parnetPos].Data )
	{
		Heap_SwapNodes( heap, curPos, parnetPos );

		curPos = parnetPos;
		parnetPos = Heap_GetParent( curPos );
		if ( parnetPos < 0 )
		{
			printf( "Parent position is invalid after swap.\n" );
			return;
		}
	}
}

void Heap_DeleteMin( Heap* heap, HeapNode* root )
{
	if ( heap == NULL )
	{
		printf( "Heap is NULL\n" );
		return;
	}

	if ( heap->UsedSize == 0 )
	{
		printf( "Heap is empty.\n" );
		return;
	}

	int parentPos = 0;
	int leftChildPos = 0;
	int rightChildPos = 0;

	// root�� �ּڰ��� �����Ѵ�.
	memcpy( root, &heap->Nodes[0], sizeof( HeapNode ) );
	memset( &heap->Nodes[0], 0, sizeof( HeapNode ) );

	// ���� ù ��° ��ҿ� ������ ����� ���� �����Ѵ�.
	heap->UsedSize--;
	Heap_SwapNodes( heap, 0, heap->UsedSize );

	leftChildPos = Heap_GetLeftChild( 0 );
	if ( leftChildPos < 0 )
	{
		printf( "Left child position is invalid.\n" );
		return;
	}
	rightChildPos = leftChildPos + 1;

	// �� ���� �Ӽ��� ������ ������ �ڽ� ������ ��ȯ�� �ݺ��Ѵ�.
	while ( 1 )
	{
		int selectedChild = 0;
		
		// �ڽ��� ���� ��� ������ �����Ѵ�.
		if ( leftChildPos >= heap->UsedSize )
		{
			break;
		}

		if ( rightChildPos >= heap->UsedSize )
		{
			selectedChild = leftChildPos;
		}
		else
		{
			// �ڽ��� �� �� �ִ� ���, �� ���� �ڽ��� �����Ѵ�.
			if ( heap->Nodes[leftChildPos].Data > heap->Nodes[rightChildPos].Data )
			{
				selectedChild = rightChildPos;
			}
			else
			{
				selectedChild = leftChildPos;
			}
		}

		if ( heap->Nodes[selectedChild].Data < heap->Nodes[parentPos].Data )
		{
			Heap_SwapNodes( heap, parentPos, selectedChild );
			parentPos = selectedChild;

			leftChildPos = Heap_GetLeftChild( parentPos );
			if ( leftChildPos < 0 )
			{
				printf( "Left child position is invalid after swap.\n" );
				return;
			}
			rightChildPos = leftChildPos + 1;
		}
		else
		{
			break;
		}

		if ( !heap_realloc( heap ) )
		{
			printf( "Heap reallocation failed during deletion.\n" );
			return;
		}
	}
}

int Heap_GetParent( int index )
{
	if (index < 0)
	{
		printf( "Index must be non-negative to get parent.\n" );
		return -1;
	}

	return ( index - 1 ) / 2;
}

int Heap_GetLeftChild( int index )
{
	if ( index < 0 )
	{
		printf( "Index must be non-negative to get left child.\n" );
		return -1;
	}

	return (2 * index) + 1;
}

void Heap_SwapNodes( Heap* heap, int index1, int index2 )
{
	int copySize = sizeof( HeapNode );
	HeapNode* tmp = ( HeapNode* ) malloc( copySize );
	if ( tmp == NULL )
	{
		printf( "Memory allocation failed for swapping nodes.\n" );
		return;
	}

	memcpy( tmp, &heap->Nodes[index1], copySize );
	memcpy( &heap->Nodes[index1], &heap->Nodes[index2], copySize );
	memcpy( &heap->Nodes[index2], tmp, copySize );

	free( tmp );
}

void Heap_PrintNdoes( Heap* heap )
{
	for ( int i = 0; i < heap->UsedSize; i++ )
	{
		printf( "%d ", heap->Nodes[i].Data );
	}
	printf( "\n" );
}