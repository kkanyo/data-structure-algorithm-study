#include "CircularDoublyLinkedList.h"

Node* CDLL_CreateNode( ElementType newData )
{
    Node* newNode = ( Node* ) malloc( sizeof( Node ) );

    if ( newNode != nullptr )
    {
        newNode->Data = newData;
        newNode->PrevNode = nullptr;
        newNode->NextNode = nullptr;
    }

    return newNode;
}

void CDLL_DestroyNode( Node* node )
{
    free( node );
}

void CDLL_AppendNode( Node** head, Node* newNode )
{
    if ( newNode == nullptr )
    {
        return;
    }

    if ( *head == nullptr )
    {
        *head = newNode;
        ( *head )->NextNode = *head;
        ( *head )->PrevNode = *head;
    }
    else
    {
        Node* tail = ( *head )->PrevNode;

        tail->NextNode->PrevNode = newNode;
        tail->NextNode = newNode;

        newNode->PrevNode = tail;
        newNode->NextNode = *head;
    }
}

void CDLL_InsertAfter( Node* current, Node* newNode )
{
    if ( current == nullptr || newNode == nullptr )
    {
        return;
    }

    newNode->PrevNode = current;
    newNode->NextNode = current->NextNode;

    if ( current->NextNode != nullptr )
    {
        current->NextNode->PrevNode = newNode;
    }
    current->NextNode = newNode;
}

void CDLL_RemoveNode( Node** head, Node* remove )
{
    if ( *head == remove )
    {
        *head = remove->NextNode;
    }

    remove->NextNode->PrevNode = remove->PrevNode;
    remove->PrevNode->NextNode = remove->NextNode;

    remove->PrevNode = nullptr;
    remove->NextNode = nullptr;
}

Node* CDLL_GetNodeAt( Node* head, int location )
{
    Node* current = head;
    while ( current != nullptr && ( --location ) >= 0 )
    {
        current = current->NextNode;
    }

    return current;
}

int CDLL_GetNodeCount( Node* head )
{
    int count = 0;
    Node* current = head;

    while ( current != nullptr ) {
        count++;
        current = current->NextNode;

        if ( current == head ) {
            break;
        }
    }

    return count;
}
