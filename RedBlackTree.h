#pragma once

#include <cstdio>
#include <cstring>

typedef int ElementType;

enum class Color
{
	RED,
	BLACK
};

struct RBTNode
{
	ElementType Data;

	RBTNode* Parent;
	RBTNode* Left;
	RBTNode* Right;

	Color Color;
};

extern RBTNode* Nil;

class RedBlackTree
{
private:
	RBTNode* root;
	RBTNode* nil;	// Sentinel node for Red - Black Tree

	void rotateLeft( RBTNode* parent );
	void rotateRight( RBTNode* parent );
	void insertNodeHelper( RBTNode** root, RBTNode* newNode );
	void rebuildAfterInsert( RBTNode* newNode );
	void rebuildAfterRemove( RBTNode* successor );

	void destroyNode( RBTNode* node );
	void destroyTree( RBTNode* root );
public:
	RedBlackTree();
	~RedBlackTree();
	RBTNode* SearchNode( ElementType target, RBTNode* root = nullptr );
	RBTNode* SearchMinNode( RBTNode* root );
	 
	void InsertNode( ElementType value );
	void RemoveNode( ElementType target );

	void Print( RBTNode* node = nullptr, int depth = 0, int blackCount = 0 );
};

