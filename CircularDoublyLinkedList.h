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

Node* CDLL_CreateNode( ElementType newData );
void CDLL_DestroyNode( Node* node );
void CDLL_AppendNode( Node** head, Node* newNode );
void CDLL_InsertAfter( Node* current, Node* newNode );
void CDLL_RemoveNode( Node** head, Node* remove );
Node* CDLL_GetNodeAt( Node* head, int location );
int CDLL_GetNodeCount( Node* head );