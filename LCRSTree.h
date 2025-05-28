#pragma once

#include <cstdio>
#include <cstdlib>

typedef char ElementType;

struct LCRSNode
{
	LCRSNode* LeftChild;
	LCRSNode* RightSibling;

	ElementType Data;
};

LCRSNode* LCRS_CreateNode( ElementType newData );
void LCRS_DestroyNode( LCRSNode* node );
void LCRS_DestroyTree( LCRSNode* root );

void LCRS_AddChildNode( LCRSNode* parentNode, LCRSNode* childNode );
void LCRS_PrintTree( LCRSNode* node, int depth );
void LCRS_PrintNodeAtLevel( int level );