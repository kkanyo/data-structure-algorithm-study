#include "Graph.h"

Graph* CreateGraph()
{
	Graph* graph = ( Graph* ) malloc( sizeof( Graph ) );
	if ( graph == NULL )
	{
		fprintf( stderr, "Memory allocation failed for graph.\n" );
		return NULL;
	}
	
	graph->Vertices = NULL;
	graph->VertexCount = 0;

	return graph;
}

void DestroyGraph( Graph* graph )
{
	if ( graph == NULL )
	{
		return;
	}

	while ( graph->Vertices != NULL )
	{
		Vertex* vertices = graph->Vertices->Next;
		DestroyVertex( graph->Vertices );
		graph->Vertices = vertices;
	}

	free( graph );
}

Vertex* CreateVertex( ElementType data )
{
	Vertex* vertex = ( Vertex* ) malloc( sizeof( Vertex ) );
	if ( vertex == NULL )
	{
		fprintf( stderr, "Memory allocation failed for vertex.\n" );
		return NULL;
	}

	vertex->Data = data;
	vertex->Visited = NOTVISITED;
	vertex->Index = -1; // 초기 인덱스 설정
	vertex->Next = NULL;
	vertex->AdjacencyList = NULL;

	return vertex;
}

void DestroyVertex( Vertex* vertex )
{
	if ( vertex == NULL )
	{
		return;
	}

	while ( vertex->AdjacencyList != NULL )
	{
		Edge* edges = vertex->AdjacencyList->Next;
		DestroyEdge( vertex->AdjacencyList );
		vertex->AdjacencyList = edges;
	}

	free( vertex );
}

Edge* CreateEdge( Vertex* from, Vertex* target, int weight )
{
	if (from == NULL || target == NULL)
	{
		fprintf( stderr, "Invalid vertices for edge creation.\n" );
		return NULL;
	}

	Edge* edge = ( Edge* ) malloc( sizeof( Edge ) );
	if ( edge == NULL )
	{
		fprintf( stderr, "Memory allocation failed for edge.\n" );
		return NULL;
	}

	edge->From = from;
	edge->Target = target;
	edge->Weight = weight;
	edge->Next = NULL;

	return edge;
}

void DestroyEdge( Edge* edge )
{
	free( edge );
}

void AddVertex( Graph* graph, Vertex* vertex )
{
	if ( graph == NULL || vertex == NULL )
	{
		fprintf( stderr, "Invalid graph or vertex for adding.\n" );
		return;
	}

	Vertex* vertexList = graph->Vertices;
	if ( vertexList == NULL )
	{
		graph->Vertices = vertex;
	}
	else
	{
		while ( vertexList->Next != NULL )
		{
			vertexList = vertexList->Next;
		}

		vertexList->Next = vertex;
	}

	vertex->Index = graph->VertexCount++;
}

void AddEdge( Vertex* vertex, Edge* edge )
{
	if ( vertex == NULL || edge == NULL )
	{
		fprintf( stderr, "Invalid vertex or edge for adding.\n" );
		return;
	}

	if ( vertex->AdjacencyList == NULL )
	{
		vertex->AdjacencyList = edge;
	}
	else
	{
		Edge* adjacencyList = vertex->AdjacencyList;
		
		while ( adjacencyList != NULL && adjacencyList->Next != NULL )
		{
			adjacencyList = adjacencyList->Next;
		}

		adjacencyList->Next = edge;
	}
}

void PrintGraph( Graph* graph )
{
	if ( graph == NULL )
	{
		fprintf( stderr, "Graph is NULL.\n" );
		return;
	}

	Vertex* vertex = graph->Vertices;
	Edge* edge = NULL;

	if ( vertex == NULL )
	{
		printf( "Graph is empty.\n" );
		return;
	}

	while ( vertex != NULL )
	{
		printf( "%c : ", ( char ) vertex->Data );

		if ( ( edge = vertex->AdjacencyList ) == NULL )
		{
			vertex = vertex->Next;
			printf( "\n" );
			continue;
		}

		while ( edge != NULL )
		{
			printf( "%c[%d] ", ( char ) edge->Target->Data, edge->Weight );
			edge = edge->Next;
		}

		printf( "\n" );

		vertex = vertex->Next;
	}

	printf( "\n" );
}
