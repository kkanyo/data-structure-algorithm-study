#include "GraphTraversal.h"

void DFS( Vertex* vertex )
{
	printf( "%lld ", (long long) vertex->Data );

	vertex->Visited = VISITED;

	Edge* edge = vertex->AdjacencyList;
	while ( edge != NULL )
	{
		// 현재 정점을 기준으로 방문하지 않은 정점을 찾아서 DFS를 수행
		if ( edge->Target != NULL && edge->Target->Visited == NOTVISITED )
		{
			DFS( edge->Target );
		}

		// 다음 인접 정점으로 이동
		edge = edge->Next;
	}
}

void BFS( Vertex* vertex, LinkedQueue* queue )
{
	Edge* edge = NULL;
	LinkedNode* popped = NULL;

	printf( "%lld ", ( long long ) vertex->Data );

	vertex->Visited = VISITED;

	// 시작 정점을 큐에 삽입한다
	LQ_Enqueue( queue, LQ_CreateNode( vertex ) );

	// 큐가 비어있으면 탐색 종료
	while ( !LQ_IsEmpty( queue ) )
	{
		popped = LQ_Dequeue( queue );

		vertex = ( Vertex* ) popped->Data;
		edge = vertex->AdjacencyList;

		// 같은 깊이의 정점들을 모두 방문한다
		while ( edge != NULL )
		{
			vertex = edge->Target;

			if (vertex != NULL && vertex->Visited == NOTVISITED )
			{
				printf( "%lld ", ( long long ) vertex->Data );
				vertex->Visited = VISITED;

				// 방문한 정점을 큐에 삽입한다
				LQ_Enqueue( queue, LQ_CreateNode( vertex ) );
			}

			edge = edge->Next;
		}
	}
}
