#pragma once

#include <stdio.h>
#include <stdlib.h>

#include "common.h"

typedef struct Vertex
{
	ElementType Data;
	int Visited;				// �׷��� ��ȸ �˰��򿡼��� �湮 ����
	int Index;					// ������ �ε���

	struct Vertex* Next;		// ���� ������ ����Ű�� ������
	struct Edge* AdjacencyList;	// ���� ����Ʈ�� ����Ű�� ������
} Vertex;

typedef struct Edge
{
	int Weight;			// ������ ����ġ
	struct Edge* Next;	// ���� ������ ����Ű�� ������
	Vertex* From;		// ���� ����
	Vertex* Target;		// ���� ����
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