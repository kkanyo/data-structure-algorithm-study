#include "ExpressionTree.h"

void ET_BuildExpressionTree( char* postfixExpression, SBTNode** node )
{
	int len = strlen( postfixExpression );
	char token = postfixExpression[len - 1];
	postfixExpression[len - 1] = '\0';

	switch ( token )
	{
	case '+':
	case '-':
	case '*':
	case '/':
		( *node ) = SBT_CreateNode( token );
		ET_BuildExpressionTree( postfixExpression, &( *node )->Right );
		ET_BuildExpressionTree( postfixExpression, &( *node )->Left );
		break;
	default:
		( *node ) = SBT_CreateNode( token );
		break;
	}
}

double ET_Evaluate( SBTNode* tree )
{
	char temp[2];

	double left = 0;
	double right = 0;
	double result = 0;

	if ( tree == nullptr )
	{
		return 0.0;
	}

	switch ( tree->Data )
	{
	case '+':
	case '-':
	case '*':
	case '/':
		left = ET_Evaluate( tree->Left );
		right = ET_Evaluate( tree->Right );

		if ( tree->Data == '+' )
		{
			result = left + right;
		}
		else if ( tree->Data == '-' )
		{
			result = left - right;
		}
		else if ( tree->Data == '*' )
		{
			result = left * right;
		}
		else if ( tree->Data == '/' )
		{
			result = left / right;
		}

		break;
	default:
		memset( temp, 0, sizeof( temp ) );
		temp[0] = tree->Data;
		result = atof( temp );
		break;
	}

	return result;
}
