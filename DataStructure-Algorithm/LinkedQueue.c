#include "LinkedQueue.h"

void LQ_CreateQueue( LinkedQueue** queue )
{
	*queue = ( LinkedQueue* ) malloc( sizeof( LinkedQueue ) );
	if ( *queue == NULL )
	{
		fprintf( stderr, "Memory allocation failed for LinkedQueue.\n" );
		return;
	}
	( *queue )->Front = NULL;
	( *queue )->Rear = NULL;
	( *queue )->Count = 0;
}

void LQ_DestroyQueue( LinkedQueue* queue )
{
	if ( queue == NULL )
	{
		return;
	}

	while ( !LQ_IsEmpty( queue ) )
	{
		LinkedNode* popped = LQ_Dequeue( queue );
		LQ_DestroyNode( popped );
	}

	free( queue );
}

LinkedNode* LQ_CreateNode( ElementType data )
{
	LinkedNode* newNode = ( LinkedNode* ) malloc( sizeof( LinkedNode ) );
	if ( newNode == NULL )
	{
		fprintf( stderr, "Memory allocation failed for LinkedNode.\n" );
		return NULL;
	}

	newNode->Data = data;
	newNode->Next = NULL;
		
	return newNode;
}

void LQ_DestroyNode( LinkedNode* node )
{
	free( node );
}

void LQ_Enqueue( LinkedQueue* queue, LinkedNode* node )
{
	if ( queue == NULL || node == NULL )
	{
		fprintf( stderr, "Invalid queue or node for enqueue.\n" );
		return;
	}

	if ( queue->Rear == NULL )
	{
		queue->Front = node;
		queue->Rear = node;
	}
	else
	{
		queue->Rear->Next = node;
		queue->Rear = node;
	}

	queue->Count++;
}

LinkedNode* LQ_Dequeue( LinkedQueue* queue )
{
	if ( queue == NULL || queue->Front == NULL )
	{
		fprintf( stderr, "Queue is empty or not initialized.\n" );
		return NULL;
	}

	LinkedNode* popped = queue->Front;
	if ( queue->Front->Next == NULL )
	{
		queue->Front = NULL;
		queue->Rear = NULL;
	}
	else
	{
		queue->Front = queue->Front->Next;
	}

	queue->Count--;

	return popped;
}

int LQ_IsEmpty( LinkedQueue* queue )
{
	if ( queue == NULL )
	{
		fprintf( stderr, "Queue is not initialized.\n" );
		return 1; // Consider it empty if not initialized
	}

	return queue->Front == NULL;
}
