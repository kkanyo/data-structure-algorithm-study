//#define _CRT_SECURE_NO_WARNINGS

#include "LinkedListStack.h"

void LLS_CreateStack( LinkedListStack** stack )
{
	( *stack ) = ( LinkedListStack* ) malloc( sizeof( LinkedListStack ) );

	if ( *stack != nullptr )
	{
		( *stack )->List = nullptr;
		( *stack )->Top = nullptr;
	}
}

void LLS_DestroyStack( LinkedListStack* stack )
{
	while ( !LLS_IsEmpty( stack ) )
	{
		Node* popped = LLS_Pop( stack );
		LLS_DestroyNode( popped );
	}

	free( stack );
}

Node* LLS_CreateNode( const char* newData )
{
	Node* newNode = ( Node* ) malloc( sizeof( Node ) );
	if ( newNode != nullptr ) {
		newNode->Data = ( char* ) malloc( strlen( newData ) + 1 );

		if ( newNode->Data != nullptr ) {
			strcpy_s( newNode->Data, strlen(newData) + 1, newData);
		}

		newNode->NextNode = nullptr;
	}
	return newNode;
}

void LLS_DestroyNode( Node* node )
{
	free( node->Data );
	free( node );
}

void LLS_Push( LinkedListStack* stack, Node* newNode )
{
	if ( stack->List == nullptr )
	{
		stack->List = newNode;
	}
	else
	{
		stack->Top->NextNode = newNode;
	}

	stack->Top = newNode;
}

Node* LLS_Pop( LinkedListStack* stack )
{
	Node* prevTop = stack->Top;
	
	if ( stack->List == stack->Top )
	{
		stack->List = nullptr;
		stack->Top = nullptr;
	}
	else
	{
		Node* newTop = stack->List;
		while ( newTop->NextNode != stack->Top )
		{
			newTop = newTop->NextNode;
		}

		stack->Top = newTop;
		newTop->NextNode = nullptr;
	}

	return prevTop;
}

Node* LLS_Top( LinkedListStack* stack )
{
	if ( stack == nullptr )
	{
		return nullptr;
	}

	return stack->Top;
}

int LLS_GetSize( LinkedListStack* stack )
{
	int count = 0;
	Node* current = stack->List;
	
	while ( current != nullptr )
	{
		count++;
		current = current->NextNode;
	}

	return count;
}

int LLS_IsEmpty( LinkedListStack* stack )
{
	return stack == nullptr || stack->List == nullptr;
}
