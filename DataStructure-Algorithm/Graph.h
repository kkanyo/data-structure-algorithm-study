#pragma once

#include <stdio.h>
#include <stdlib.h>

#include "common.h"

typedef struct Vertex
{
	ElementType Data;
	int Visited;				// 그래프 순회 알고리즘에서의 방문 여부
	int Index;					// 정점의 인덱스

	struct Vertex* Next;		// 다음 정점을 가리키는 포인터
	struct Edge* AdjacencyList;	// 인접 리스트를 가리키는 포인터
} Vertex;

typedef struct Edge
{
	int Weight;			// 간선의 가중치
	struct Edge* Next;	// 다음 간선을 가리키는 포인터
	Vertex* From;		// 시작 정점
	Vertex* Target;		// 도착 정점
} Edge;

typedef struct Graph
{
	Vertex* Vertices;
	int VertexCount;
} Graph;

Graph* CreateGraph();
void DestroyGraph( Graph* graph );

Vertex* CreateVertex( ElementType data );
void DestroyVertex( Vertex* vertex );

Edge* CreateEdge( Vertex* from, Vertex* target, int weight );
void DestroyEdge( Edge* edge );

void AddVertex( Graph* graph, Vertex* vertex );
void AddEdge( Vertex* vertex, Edge* edge );

void PrintGraph( Graph* graph );