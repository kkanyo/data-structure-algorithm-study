#pragma once

#include <cstdio>
#include <cstdlib>

typedef int ElementType;

struct BSTNode
{
	BSTNode* Left;
	BSTNode* Right;

	ElementType Data;
};

BSTNode* BST_CreateNode( ElementType newData );
void BST_DestroyNode( BSTNode* node );
void BST_DestroyTree( BSTNode* tree );

BSTNode* BST_SearchNode( BSTNode* tree, ElementType target );
BSTNode* BST_SearchMinNode( BSTNode* tree );
void BST_InsertNode( BSTNode* tree, BSTNode* child );
BSTNode* BST_RemoveNode( BSTNode* tree, BSTNode* parent, ElementType target );
void BST_InorderPrintTree( BSTNode* node );