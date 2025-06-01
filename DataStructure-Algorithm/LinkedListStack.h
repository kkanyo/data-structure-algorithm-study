#pragma once

#include <cstdio>
#include <cstring>
#include <cstdlib>

typedef struct TagNode
{
	char* Data;
	struct TagNode* NextNode;
} Node;

typedef struct TagLinkedListStack
{
	Node* List;
	Node* Top;
} LinkedListStack;

void LLS_CreateStack( LinkedListStack** stack );
void LLS_DestroyStack( LinkedListStack* stack );

Node* LLS_CreateNode( const char* newData );
void LLS_DestroyNode( Node* node );

void LLS_Push( LinkedListStack* stack, Node* newNode );
Node* LLS_Pop( LinkedListStack* stack );

Node* LLS_Top( LinkedListStack* stack );
int LLS_GetSize( LinkedListStack* stack );
int LLS_IsEmpty( LinkedListStack* stack );