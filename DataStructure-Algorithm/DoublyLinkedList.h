#pragma once

#include <cstdio>
#include <cstdlib>

typedef int ElementType;

typedef struct TagNode
{
	ElementType Data;
	struct TagNode* PrevNode;
	struct TagNode* NextNode;
} Node;

Node* DLL_CreateNode( ElementType newData );
void DLL_DestroyNode( Node* node );
void DLL_AppendNode( Node** head, Node* newNode );
void DLL_InsertAfter( Node* current, Node* newNode );
void DLL_RemoveNode( Node** head, Node* remove );
Node* DLL_GetNodeAt( Node* head, int location );
int DLL_GetNodeCount( Node* head );
void PrintReverse( Node* head );