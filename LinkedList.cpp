#include "LinkedList.h"

Node* SLL_CreateNode( ElementType newData )
{
	Node* newNode = ( Node* ) malloc( sizeof( Node ) );

	if ( newNode != nullptr )
	{
		newNode->Data = newData;
		newNode->NextNode = nullptr;
	}
	
	return newNode;
}

void SLL_DestroyNode( Node* node )
{
	free( node );
}

void SLL_DestroyAllNodes( Node** list )
{
	Node* current = *list;
	while ( current->NextNode != nullptr )
	{
		Node* destroyNode = current;
		current = current->NextNode;

		free( destroyNode );
	}
}

void SLL_AppendNode( Node** head, Node* newNode )
{
	if ( *head == nullptr )
	{
		*head = newNode;
	}
	else
	{
		Node* tail = *head;
		while ( tail->NextNode != nullptr )
		{
			tail = tail->NextNode;
		}
		tail->NextNode = newNode;
	}
}

void SLL_InsertAfter( Node* current, Node* newNode )
{
	if ( current == nullptr )
	{
		return;
	}

	newNode->NextNode = current->NextNode;
	current->NextNode = newNode;
}

void SLL_InsertBefore( Node** head, Node* current, Node* newHead )
{
	if ( current == nullptr )
	{
		return;
	}

	if ( *head == nullptr || *head == current )
	{
		SLL_InsertNewHead( head, newHead );
	}
	else
	{
		Node* oldHead = *head;
		while ( oldHead->NextNode != current )
		{
			oldHead = oldHead->NextNode;
		}

		if ( oldHead == nullptr ) {
			return;
		}

		newHead->NextNode = current;
		oldHead->NextNode = newHead;
	}
}

void SLL_InsertNewHead( Node** head, Node* newHead )
{
	if ( *head == nullptr )
	{
		*head = newHead;
	}
	else
	{
		newHead->NextNode = *head;
		*head = newHead;
	}
}

void SLL_RemoveNode( Node** head, Node* remove )
{
	if ( *head == remove ) {
		*head = remove->NextNode;
	}
	else
	{
		Node* current = *head;
		while ( current->NextNode != nullptr && current->NextNode != remove )
		{
			current = current->NextNode;
		}

		if ( current != nullptr )
		{
			current->NextNode = remove->NextNode;
		}
	}
}

Node* SLL_GetNodeAt( Node* head, int location )
{
	Node* current = head;

	while ( current != nullptr && ( --location ) >= 0 )
	{
		current = current->NextNode;
	}

	return current;
}

int SLL_GetNodeCount( Node* head )
{
	int count = 0;
	Node* current = head;

	while ( current->NextNode != nullptr ) {
		current = current->NextNode;
		count++;
	}

	return count;
}
