#pragma once

#include <cstdlib>

typedef int ElementType;

typedef struct TagNode
{
	ElementType Data;
} Node;

typedef struct TagArrayStack
{
	int Capacity;
	int Top;
	Node* Nodes;
} ArrayStack;

void AS_CreateStack( ArrayStack** stack, int capacity );
void AS_DestroyStack( ArrayStack* stack );
void AS_Push( ArrayStack* stack, ElementType data );
ElementType AS_Pop( ArrayStack* stack );
ElementType AS_Top( ArrayStack* stack );
int AS_GetSize( ArrayStack* stack );
int AS_IsEmpty( ArrayStack* stack );
int AS_IsFull( ArrayStack* stack );