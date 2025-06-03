#include "PriorityQueue.h"

PriorityQueue* PQ_Create( int initialSize )
{
	PriorityQueue* newPQ = ( PriorityQueue* ) malloc( sizeof( PriorityQueue ) );
	if ( !newPQ )
	{
		printf( "Memory allocation failed for PriorityQueue.\n" );
		return NULL;
	}

	newPQ->Capacity = initialSize;
	newPQ->UsedSize = 0;
	newPQ->Nodes = ( PQNode* ) malloc( sizeof( PQNode ) * newPQ->Capacity );

	return newPQ;
}

void PQ_Destroy( PriorityQueue* pq )
{
	if ( pq )
	{
		if ( pq->Nodes )
		{
			free( pq->Nodes );
			pq->Nodes = NULL;
		}
		free( pq );
		pq = NULL;
	}
}

void PQ_Enqueue( PriorityQueue* pq, PQNode newData )
{
	if ( pq == NULL )
	{
		printf( "PriorityQueue is NULL\n" );
		return;
	}
	
	int curPos = pq->UsedSize;
	int parentPos = PQ_GetParent( curPos );

	if ( !PQ_Reallocate( pq ) )
	{
		printf( "PriorityQueue reallocation failed during enqueue.\n" );
		return;
	}

	pq->Nodes[curPos] = newData;

	while ( curPos > 0 && pq->Nodes[curPos].Priority < pq->Nodes[parentPos].Priority )
	{
		PQ_SwapNodes( pq, curPos, parentPos );

		curPos = parentPos;
		parentPos = PQ_GetParent( curPos );
	}

	pq->UsedSize++;
}

void PQ_Dequeue( PriorityQueue* pq, PQNode* root )
{
	int parentPos = 0;
	int leftChildPos = PQ_GetLeftChild( parentPos );
	int rightChildPos = leftChildPos + 1;

	memcpy_s( root, sizeof( PQNode ), &pq->Nodes[0], sizeof( PQNode ) );
	memset( &pq->Nodes[0], 0, sizeof( PQNode ) );

	pq->UsedSize--;
	PQ_SwapNodes( pq, 0, pq->UsedSize );

	while ( 1 )
	{
		int selectedChildPos = 0;

		if ( leftChildPos >= pq->UsedSize )
		{
			break;
		}

		// 왼쪽 자식만 있는 경우
		if ( rightChildPos >= pq->UsedSize )
		{
			selectedChildPos = leftChildPos;
		}
		else
		{
			// 양쪽 자식이 있는 경우 작은 쪽을 교환 후보로 선택
			if ( pq->Nodes[leftChildPos].Priority > pq->Nodes[rightChildPos].Priority )
			{
				selectedChildPos = rightChildPos;
			}
			else
			{
				selectedChildPos = leftChildPos;
			}
		}

		// 자식이 부모보다 작으면 교환
		if ( pq->Nodes[selectedChildPos].Priority < pq->Nodes[parentPos].Priority )
		{
			PQ_SwapNodes( pq, parentPos, selectedChildPos );
			parentPos = selectedChildPos;
		}
		else
		{
			break;
		}

		leftChildPos = PQ_GetLeftChild( parentPos );
		rightChildPos = leftChildPos + 1;
	}

	PQ_Reallocate( pq );
}

int PQ_GetParent( int index )
{
	if (index <= 0)
	{
		printf( "Index must be greater than 0 to get parent.\n" );
		return -1;
	}
	return (int) ((index - 1) / 2);
}

int PQ_GetLeftChild( int index )
{
	if ( index < 0 )
	{
		printf( "Index must be non-negative to get left child.\n" );
		return -1;
	}

	return 2 * index + 1;
}

void PQ_SwapNodes( PriorityQueue* pq, int index1, int index2 )
{
	int copySize = sizeof( PQNode );
	PQNode* temp = ( PQNode* ) malloc( copySize );

	memcpy_s( temp, copySize, &pq->Nodes[index1], copySize );
	memcpy_s( &pq->Nodes[index1], copySize, &pq->Nodes[index2], copySize );
	memcpy_s( &pq->Nodes[index2], copySize, temp, copySize );

	free( temp );
}

int PQ_IsEmpty( PriorityQueue* pq )
{
	return pq->UsedSize == 0;
}

int PQ_Reallocate( PriorityQueue* pq )
{
	
	if ( pq == NULL )
	{
		printf( "PriorityQueue is NULL\n" );
		return 0;
	}

	int newCapacity = 0;

	if ( pq->UsedSize >= pq->Capacity )
	{
		newCapacity = pq->Capacity * 2;
	}
	else if ( pq->UsedSize < ( pq->Capacity / 2 ) )
	{
		newCapacity = pq->Capacity / 2;
	}
	else
	{
		return 1;
	}

	PQNode* temp = ( PQNode* ) realloc( pq->Nodes, sizeof( PQNode ) * newCapacity );
	if ( pq->Nodes == NULL )
	{
		printf( "PriorityQueue realloc failed!\n" );
		return 0;
	}

	pq->Capacity = newCapacity;
	pq->Nodes = temp;

	return 1;
}

void PQ_PrintNode( PQNode* node )
{
	if ( !node )
	{
		printf( "Node is NULL\n" );
		return;
	}

	printf( "Priority: %d, Data: %s\n", node->Priority, (char*)node->Data);
}