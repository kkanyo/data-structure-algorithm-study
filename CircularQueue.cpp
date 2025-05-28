#include "CircularQueue.h"

void CQ_CreateQueue( CircularQueue** queue, int capacity )
{
	( *queue ) = ( CircularQueue* ) malloc( sizeof( CircularQueue ) );

	if ( *queue != nullptr )
	{
		( *queue )->Nodes = ( Node* ) malloc( sizeof( Node ) * ( capacity ) );

		( *queue )->Capacity = capacity;
		( *queue )->Front = 0;
		( *queue )->Rear = 0;
	}
}

void CQ_DestroyQueue( CircularQueue* queue )
{
	free( queue->Nodes );
	free( queue );
}

void CQ_Enqueue( CircularQueue* queue, ElementType data )
{
	if ( CQ_IsFull( queue ) )
	{
		return;
	}

	int position = 0;

	if ( queue->Rear == queue->Capacity)
	{
		position = queue->Rear;
		queue->Rear = 0;
	}
	else
	{
		position = queue->Rear++;
	}

	queue->Nodes[position].Data = data;
}

ElementType CQ_Dequeue( CircularQueue* queue )
{
	//if ( CQ_IsEmpty( queue ) )
	//{
	//	return 0; ???
	//}

	int position = queue->Front;

	if ( queue->Front == queue->Capacity )
	{
		queue->Front = 0;
	}
	else
	{
		queue->Front++;
	}

	return queue->Nodes[position].Data;
}

int CQ_GetSize( CircularQueue* queue )
{
	if ( queue->Front <= queue->Rear )
	{
		return queue->Rear - queue->Front;
	}
	else
	{
		return queue->Rear + ( queue->Capacity - queue->Front ) + 1;
	}
}

int CQ_IsEmpty( CircularQueue* queue )
{
	return queue->Front == queue->Rear;
}

int CQ_IsFull( CircularQueue* queue )
{
	if ( queue->Front < queue->Rear )
	{
		return ( queue->Rear - queue->Front ) == queue->Capacity;
	}
	else
	{
		return ( queue->Rear + 1 ) == queue->Front;
	}
}