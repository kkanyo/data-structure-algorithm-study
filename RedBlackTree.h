#pragma once

#include <cstdio>
#include <cstdlib>

typedef int ElementType;

struct RBTNode
{
	RBTNode* Parent;
	RBTNode* Left;
	RBTNode* Right;

	enum { RED, BLACK} Color;
	
	ElementType Data;
};

extern RBTNode* Nil;

void RBT_DestroyTree( RBTNode* root );

RBTNode* RBT_CreateNode( ElementType newData );
void RBT_DestroyNode( RBTNode* node );

RBTNode* RBT_SearchNode( RBTNode* root, ElementType target );
RBTNode* RBT_SearchMinNode( RBTNode* root );
void RBT_InsertNode( RBTNode** root, RBTNode* newNode );
void RBT_InsertNodeHelper( RBTNode** root, RBTNode* newNode );
RBTNode* RBT_RemoveNode( RBTNode** root, ElementType target );
void RBT_RebuildAfterInsert( RBTNode** root, RBTNode* newNode );
void RBT_RebuildAfterRemove( RBTNode** root, RBTNode* successor );

void RBT_PrintTree( RBTNode* node, int depth, int blackCount );
void RBT_RotateLeft( RBTNode** root, RBTNode* parent );
void RBT_RotateRight( RBTNode** root, RBTNode* parent );