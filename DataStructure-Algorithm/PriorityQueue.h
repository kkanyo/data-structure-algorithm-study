#pragma once

#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

typedef int PriorityType;

typedef struct PQNode
{
	PriorityType Priority;
	void* Data;
} PQNode;

typedef struct PriorityQueue
{
	PQNode* Nodes;
	int Capacity;
	int UsedSize;
} PriorityQueue;

PriorityQueue* PQ_Create( int initialSize );
void PQ_Destroy( PriorityQueue* pq );

void PQ_Enqueue( PriorityQueue* pq, PQNode newData );
void PQ_Dequeue( PriorityQueue* pq, PQNode* root );
int PQ_GetParent( int index );
int PQ_GetLeftChild( int index );
void PQ_SwapNodes( PriorityQueue* pq, int index1, int index2 );
int PQ_IsEmpty( PriorityQueue* pq );

int PQ_Reallocate( PriorityQueue* pq );

void PQ_PrintNode( PQNode* node );