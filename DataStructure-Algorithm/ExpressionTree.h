#pragma once

#include <cstring>
#include "SBTTree.h"

void ET_BuildExpressionTree( char* postfixExpression, SBTNode** node );
double ET_Evaluate( SBTNode* tree );