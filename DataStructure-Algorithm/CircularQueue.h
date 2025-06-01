#pragma once

#include <cstdio>
#include <cstdlib>

typedef int ElementType;

struct Node
{
	ElementType Data;
};

struct CircularQueue
{
	int Capacity;
	int Front;
	int Rear;

	Node* Nodes;
};

void CQ_CreateQueue( CircularQueue** queue, int capacity );
void CQ_DestroyQueue( CircularQueue* queue );
void CQ_Enqueue( CircularQueue* queue, ElementType data );
ElementType CQ_Dequeue( CircularQueue* queue );
int CQ_GetSize( CircularQueue* queue );
int CQ_IsEmpty( CircularQueue* queue );
int CQ_IsFull( CircularQueue* queue );
