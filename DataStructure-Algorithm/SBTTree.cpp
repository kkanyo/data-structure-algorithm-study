#include "SBTTree.h"

SBTNode* SBT_CreateNode( ElementType newData )
{
    SBTNode* newNode = ( SBTNode* ) malloc( sizeof( SBTNode ) );
    if ( newNode == nullptr )
    {
        return nullptr;
    }

    newNode->Left = nullptr;
    newNode->Right = nullptr;
    newNode->Data = newData;

    return newNode;
}

void SBT_DestroyNode( SBTNode* node )
{
    free( node );
}

void SBT_DestroyTree( SBTNode* root )
{
    if ( root == nullptr )
    {
        return;
    }

    SBT_DestroyTree( root->Left );

    SBT_DestroyTree( root->Right );

    SBT_DestroyNode( root );
}

void SBT_PreorderPrintTree( SBTNode* node )
{
    if ( node == nullptr )
    {
        return;
    }

    printf( " %c", node->Data );

    SBT_PreorderPrintTree( node->Left );

    SBT_PreorderPrintTree( node->Right );
}

void SBT_InorderPrintTree( SBTNode* node )
{
    if ( node == nullptr )
    {
        return;
    }

    SBT_InorderPrintTree( node->Left );

    printf( " %c", node->Data );

    SBT_InorderPrintTree( node->Right );
}

void SBT_PostorderPrintTree( SBTNode* node )
{
    if ( node == nullptr )
    {
        return;
    }

    SBT_PostorderPrintTree( node->Left );

    SBT_PostorderPrintTree( node->Right );

    printf( " %c", node->Data );
}

