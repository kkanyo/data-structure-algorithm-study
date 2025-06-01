#include "DoublyLinkedList.h"

Node* DLL_CreateNode( ElementType newData )
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

void DLL_DestroyNode( Node* node )
{
    free( node );
}

void DLL_AppendNode( Node** head, Node* newNode )
{
    if ( newNode == nullptr )
    {
        return;
    }

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
        newNode->PrevNode = tail;
    }
}

void DLL_InsertAfter( Node* current, Node* newNode )
{
    if ( current == nullptr || newNode == nullptr ) {
        return;
    }


    if ( current->NextNode != nullptr )
    {
        current->NextNode->PrevNode = newNode;
        newNode->NextNode = current->NextNode;
    }

    newNode->PrevNode = current;
    current->NextNode = newNode;

    //newNode->NextNode = current->NextNode;
    //newNode->PrevNode = current;

    //if ( current->NextNode != nullptr )
    //{
    //    current->NextNode->PrevNode = newNode;
    //    current->NextNode = newNode;
    //}
}

void DLL_RemoveNode( Node** head, Node* remove )
{
    if ( *head == nullptr || remove == nullptr )
    {
        return;
    }

    if ( *head == remove )
    {
        *head = remove->NextNode;
        if ( *head != nullptr )
        {
            ( *head )->PrevNode = nullptr;
        }
    }
    else
    {
        if ( remove->PrevNode != nullptr ) {
            remove->PrevNode->NextNode = remove->NextNode;
        }

        if ( remove->NextNode != nullptr ) {
            remove->NextNode->PrevNode = remove->PrevNode;
        }
    }

    remove->PrevNode = nullptr;
    remove->NextNode = nullptr;
}

Node* DLL_GetNodeAt( Node* head, int location )
{
    Node* current = head;

    while ( current != nullptr && ( --location ) >= 0 )
    {
        current = current->NextNode;
    }

    return current;
}

int DLL_GetNodeCount( Node* head )
{
    Node* current = head;
    int count = 0;

    while ( current != nullptr ) {
        count++;
        current = current->NextNode;
    }

    return count;
}

void PrintReverse( Node* head )
{
    int count = DLL_GetNodeCount( head );
    
    Node* tail = DLL_GetNodeAt( head, count - 1 );
    
    while ( tail->PrevNode != nullptr )
    {
        printf( "List[%d] : %d\n", (--count), tail->Data);
        tail = tail->PrevNode;
    }
}

void PrintNode( Node* node )
{
    if ( node->PrevNode == nullptr )
    {
        printf( "Prev: nullptr" );
    }
    else
    {
        printf( "Prev: %d", node->PrevNode->Data );
        printf( "Current: %d", node->Data );
    }

    if ( node->NextNode == nullptr )
    {
        printf( "Next: nullptr\n" );
    }
    else
    {
        printf( "Next: %d\n", node->NextNode->Data );
    }
}
