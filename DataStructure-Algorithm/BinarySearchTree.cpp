#include "BinarySearchTree.h"

BSTNode* BST_CreateNode( ElementType newData )
{
    BSTNode* newNode = ( BSTNode* ) malloc( sizeof( BSTNode ) );
    if ( newNode == nullptr )
    {
        return nullptr;
    }

    newNode->Left = nullptr;
    newNode->Right = nullptr;
    newNode->Data = newData;

    return newNode;
}

void BST_DestroyNode( BSTNode* node )
{
    free( node );
}

void BST_DestroyTree( BSTNode* tree )
{
    if ( tree->Left != nullptr )
    {
        BST_DestroyTree( tree->Left );
    }

    if ( tree->Right != nullptr )
    {
        BST_DestroyTree( tree->Right );
    }

    tree->Left = nullptr;
    tree->Right = nullptr;

    BST_DestroyNode( tree );
}

BSTNode* BST_SearchNode( BSTNode* tree, ElementType target )
{
    if ( tree == nullptr )
    {
        return nullptr;
    }

    if ( tree->Data > target )
    {
        return BST_SearchNode( tree->Left, target );
    }

    if ( tree->Data < target )
    {
        return BST_SearchNode( tree->Right, target );
    }

    return tree;
}

BSTNode* BST_SearchMinNode( BSTNode* tree )
{
    if ( tree == nullptr )
    {
        return nullptr;
    }

    if ( tree->Left == nullptr )
    {
        return tree;
    }

    return BST_SearchMinNode( tree->Left );
}

void BST_InsertNode( BSTNode* tree, BSTNode* child )
{
    if ( tree == nullptr )
    {
        return;
    }

    if ( tree->Data > child->Data )
    {
        if ( tree->Left == nullptr )
        {
            tree->Left = child;
        }
        else
        {
            BST_InsertNode( tree->Left, child );
        }
    }
    else if ( tree->Data < child->Data )
    {
        if ( tree->Right == nullptr )
        {
            tree->Right = child;
        }
        else
        {
            BST_InsertNode( tree->Right, child );
        }
    }

    return;
}

BSTNode* BST_RemoveNode( BSTNode* tree, BSTNode* parent, ElementType target )
{
    BSTNode* removed = nullptr;

    if ( tree == nullptr )
    {
        return nullptr;
    }

    if ( tree->Data > target )
    {
        removed = BST_RemoveNode( tree->Left, tree, target );
    }
    else if ( tree->Data < target )
    {
        removed = BST_RemoveNode( tree->Right, tree, target );
    }
    else
    {
        removed = tree;

        if ( tree->Left == nullptr && tree->Right == nullptr )
        {
            if ( parent->Left == tree )
            {
                parent->Left = nullptr;
            }
            else
            {
                parent->Right = nullptr;
            }
        }
        else
        {
            if ( tree->Left != nullptr && tree->Right != nullptr )
            {
                BSTNode* minNode = BST_SearchMinNode( tree->Right );
                minNode = BST_RemoveNode( tree, nullptr, minNode->Data );
                tree->Data = minNode->Data;
            }
            else
            {
                BSTNode* temp = nullptr;

                if ( tree->Left != nullptr )
                {
                    temp = tree->Left;
                }
                else
                {
                    temp = tree->Right;
                }

                if ( parent->Left == tree )
                {
                    parent->Left = temp;
                }
                else
                {
                    parent->Right = temp;
                }
            }
        }
    }

    //BST_DestroyNode( removed );

    return removed;
}

void BST_InorderPrintTree( BSTNode* node )
{
    if ( node == nullptr )
    {
        return;
    }

    BST_InorderPrintTree( node->Left );

    printf( "%d ", node->Data );

    BST_InorderPrintTree( node->Right );
}
