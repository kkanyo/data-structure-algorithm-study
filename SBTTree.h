#pragma once

#include <cstdio>
#include <cstdlib>

typedef char ElementType;

struct SBTNode
{
	SBTNode* Left;
	SBTNode* Right;

	ElementType Data;
};

SBTNode* SBT_CreateNode( ElementType newData );
void SBT_DestroyNode( SBTNode* node );
void SBT_DestroyTree( SBTNode* root );

void SBT_PreorderPrintTree( SBTNode* node );
void SBT_InorderPrintTree( SBTNode* node );
void SBT_PostorderPrintTree( SBTNode* node );


