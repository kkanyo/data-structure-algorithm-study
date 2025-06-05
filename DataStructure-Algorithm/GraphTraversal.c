#include "GraphTraversal.h"

void DFS( Vertex* vertex )
{
	printf( "%lld ", (long long) vertex->Data );

	vertex->Visited = VISITED;

	Edge* edge = vertex->AdjacencyList;
	while ( edge != NULL )
	{
		// ���� ������ �������� �湮���� ���� ������ ã�Ƽ� DFS�� ����
		if ( edge->Target != NULL && edge->Target->Visited == NOTVISITED )
		{
			DFS( edge->Target );
		}

		// ���� ���� �������� �̵�
		edge = edge->Next;
	}
}

void BFS( Vertex* vertex, LinkedQueue* queue )
{
	Edge* edge = NULL;
	LinkedNode* popped = NULL;

	printf( "%lld ", ( long long ) vertex->Data );

	vertex->Visited = VISITED;

	// ���� ������ ť�� �����Ѵ�
	LQ_Enqueue( queue, LQ_CreateNode( vertex ) );

	// ť�� ��������� Ž�� ����
	while ( !LQ_IsEmpty( queue ) )
	{
		popped = LQ_Dequeue( queue );

		vertex = ( Vertex* ) popped->Data;
		edge = vertex->AdjacencyList;

		// ���� ������ �������� ��� �湮�Ѵ�
		while ( edge != NULL )
		{
			vertex = edge->Target;

			if (vertex != NULL && vertex->Visited == NOTVISITED )
			{
				printf( "%lld ", ( long long ) vertex->Data );
				vertex->Visited = VISITED;

				// �湮�� ������ ť�� �����Ѵ�
				LQ_Enqueue( queue, LQ_CreateNode( vertex ) );
			}

			edge = edge->Next;
		}
	}
}
