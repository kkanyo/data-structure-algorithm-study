#pragma once

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct HeapNode
{
	ElementType Data;
} HeapNode;

typedef struct Heap
{
	HeapNode* Nodes;
	int Capacity;
	int UsedSize;
} Heap;

Heap* Heap_Create( int initialSize );
void Heap_Destroy( Heap* heap );

int heap_realloc( Heap* heap );

void Heap_Insert( Heap* heap, ElementType newData );
void Heap_DeleteMin( Heap* heap, HeapNode* root );

int Heap_GetParent( int index );
int Heap_GetLeftChild( int index );

void Heap_SwapNodes( Heap* heap, int index1, int index2 );

void Heap_PrintNdoes( Heap* heap );