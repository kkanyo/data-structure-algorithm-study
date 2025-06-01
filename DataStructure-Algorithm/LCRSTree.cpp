#include "LCRSTree.h"

LCRSNode* LCRS_CreateNode( ElementType newData )
{
    LCRSNode* newNode = ( LCRSNode* ) malloc( sizeof( LCRSNode ) );
    if ( newNode == nullptr )
    {
        return nullptr;
    }

    newNode->LeftChild = nullptr;
    newNode->RightSibling = nullptr;
    newNode->Data = newData;

    return newNode;
}

void LCRS_DestroyNode( LCRSNode* node )
{
    free( node );
}

void LCRS_DestroyTree( LCRSNode* root )
{
    if ( root->RightSibling != nullptr )
    {
        LCRS_DestroyTree( root->RightSibling );
    }

    if ( root->LeftChild != nullptr )
    {
        LCRS_DestroyTree( root->LeftChild );
    }

    root->LeftChild = nullptr;
    root->RightSibling = nullptr;

    LCRS_DestroyNode( root );
}

void LCRS_AddChildNode( LCRSNode* parentNode, LCRSNode* childNode )
{
    if ( parentNode->LeftChild == nullptr )
    {
        parentNode->LeftChild = childNode;
    }
    else
    {
        LCRSNode* tempNode = parentNode->LeftChild;
        while ( tempNode->RightSibling != nullptr )
        {
            tempNode = tempNode->RightSibling;
        }

        tempNode->RightSibling = childNode;
    }
}

void LCRS_PrintTree( LCRSNode* node, int depth )
{
    for ( int i = 0; i < depth - 1; i++ )
    {
        printf( "   " );
    }

    if ( depth > 0 )
    {
        printf( "+--" );
    }

    printf( "%c\n", node->Data );

    if ( node->LeftChild != nullptr )
    {
        LCRS_PrintTree( node->LeftChild, depth + 1 );
    }

    if ( node->RightSibling != nullptr )
    {
        LCRS_PrintTree( node->RightSibling, depth );
    }
}

void LCRS_PrintNodeAtLevel( int level )
{

}
