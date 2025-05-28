#include <cstring>
#include "RedBlackTree.h"

RBTNode* Nil;

void RBT_DestroyTree( RBTNode* root )
{
	if ( root == nullptr || root == Nil )
	{
		return;
	}

	if ( root->Right != nullptr )
	{
		RBT_DestroyTree( root->Right );
	}

	if ( root->Left != nullptr )
	{
		RBT_DestroyTree( root->Left );
	}

	root->Parent = nullptr;
	root->Left = nullptr;
	root->Right = nullptr;

	RBT_DestroyNode( root );
}

RBTNode* RBT_CreateNode( ElementType newData )
{

	RBTNode* newNode = ( RBTNode* ) malloc( sizeof( RBTNode ) );
	if ( newNode == nullptr )
	{
		return nullptr;
	}

	newNode->Parent = nullptr;
	newNode->Left = nullptr;
	newNode->Right = nullptr;
	newNode->Data = newData;
	newNode->Color = RBTNode::BLACK;

	return newNode;
}

void RBT_DestroyNode( RBTNode* node )
{
	free( node );
}

RBTNode* RBT_SearchNode( RBTNode* root, ElementType target )
{
	if ( root == nullptr || root == Nil )
	{
		return nullptr;
	}

	if ( root->Data > target )
	{
		return RBT_SearchNode( root->Left, target );
	}
	else if ( root->Data < target )
	{
		return RBT_SearchNode( root->Right, target );
	}
	else
	{
		return root;
	}
}

RBTNode* RBT_SearchMinNode( RBTNode* root )
{
	if ( root == nullptr || root == Nil )
	{
		return nullptr;
	}

	if ( root->Left == Nil )
	{
		return root;
	}
	else
	{
		return RBT_SearchMinNode( root->Left );
	}
}

void RBT_InsertNode( RBTNode** root, RBTNode* newNode )
{
	RBT_InsertNodeHelper( root, newNode );

	newNode->Color = RBTNode::RED;
	newNode->Left = Nil;
	newNode->Right = Nil;

	RBT_RebuildAfterInsert( root, newNode );
}

void RBT_InsertNodeHelper( RBTNode** root, RBTNode* newNode )
{
	if ( *root == nullptr || *root == Nil )
	{
		*root = newNode;
		return;
	}

	if ( ( *root )->Data < newNode->Data )
	{
		if ( ( *root )->Right == Nil )
		{
			( *root )->Right = newNode;
			newNode->Parent = *root;
		}
		else
		{
			RBT_InsertNodeHelper( &( *root )->Right, newNode );
		}
	}
	else if ( ( *root )->Data > newNode->Data )
	{
		if ( ( *root )->Left == Nil )
		{
			( *root )->Left = newNode;
			newNode->Parent = *root;
		}
		else
		{
			RBT_InsertNodeHelper( &( *root )->Left, newNode );
		}
	}
}

RBTNode* RBT_RemoveNode( RBTNode** root, ElementType data )
{
	RBTNode* removed = nullptr;		// ���� ������ ���
	RBTNode* successor = nullptr;	// ��ü ���
	RBTNode* target = RBT_SearchNode( *root, data );
	
	if ( target == nullptr || target == Nil )
	{
		return nullptr;
	}

	if ( target->Left == Nil || target->Right == Nil )
	{
		// �ڽ��� ���ʸ� �ְų� ���� ��� �ڽ��� �����ǰ� �ڽ��� �������ָ� �ȴ�.
		removed = target;
	}
	else
	{
		// ������ ���� Ʈ������ �ּڰ� ���� ��ü�Ѵ�. (�ּڰ� ��尡 ���� �ȴ�.)
		removed = RBT_SearchMinNode( target->Right );
		target->Data = removed->Data;
	}

	if ( removed->Left != Nil )
	{
		successor = removed->Left;
	}
	else
	{
		successor = removed->Right;
	}
	successor->Parent = removed->Parent;

	if ( removed->Parent == nullptr )
	{
		*root = successor;
	}
	else
	{
		if ( removed == removed->Parent->Left )
		{
			removed->Parent->Left = successor;
		}
		else
		{
			removed->Parent->Right = successor;
		}
	}

	// ���� ��尡 �������� ��� ��Ģ�� �����ϱ� ���� �籸���Ѵ�.
	if ( removed->Color == RBTNode::BLACK )
	{
		RBT_RebuildAfterRemove( root, successor );
	}

	return removed;
}

void RBT_RebuildAfterInsert( RBTNode** root, RBTNode* newNode )
{
	while ( newNode != *root && newNode->Parent->Color == RBTNode::RED )
	{
		if ( newNode->Parent == newNode->Parent->Parent->Left )
		{
			RBTNode* uncle = newNode->Parent->Parent->Right;

			// ���� ��尡 �������� ���
			if ( uncle->Color == RBTNode::RED )
			{
				newNode->Parent->Color = RBTNode::BLACK;
				uncle->Color = RBTNode::BLACK;
				newNode->Parent->Parent->Color = RBTNode::RED;

				newNode = newNode->Parent->Parent;
			}
			// ���� ��尡 �������� ���
			else
			{
				// ���� ������ ��尡 �θ� ���� �ٸ� ������ ���
				if ( newNode == newNode->Parent->Right )
				{
					newNode = newNode->Parent;
					RBT_RotateLeft( root, newNode );
				}

				// ���� ������ ��尡 �θ� ���� ���� ������ ���
				newNode->Parent->Color = RBTNode::BLACK;
				newNode->Parent->Parent->Color = RBTNode::RED;

				RBT_RotateRight( root, newNode->Parent->Parent );
			}
		}
		else
		{
			RBTNode* uncle = newNode->Parent->Parent->Left;
			if ( uncle->Color == RBTNode::RED )
			{
				newNode->Parent->Color = RBTNode::BLACK;
				uncle->Color = RBTNode::BLACK;
				newNode->Parent->Parent->Color = RBTNode::RED;

				newNode = newNode->Parent->Parent;
			}
			else
			{
				if ( newNode == newNode->Parent->Left )
				{
					newNode = newNode->Parent;
					RBT_RotateRight( root, newNode );
				}

				newNode->Parent->Color = RBTNode::BLACK;
				newNode->Parent->Parent->Color = RBTNode::RED;

				RBT_RotateLeft( root, newNode->Parent->Parent );
			}
		}
	}

	// �Ѹ� ���� �ݵ�� �������̾�� �Ѵ�.
	( *root )->Color = RBTNode::BLACK;
}

void RBT_RebuildAfterRemove( RBTNode** root, RBTNode* successor )
{
	// �Ѹ� ����̰ų� ������ ���� �Ѿ�� ����
	while ( successor->Parent != nullptr && successor->Color == RBTNode::BLACK )
	{
		if ( successor == successor->Parent->Left )
		{
			RBTNode* sibling = successor->Parent->Right;

			// ���� ��尡 �������� ���
			if ( sibling->Color == RBTNode::RED )
			{
				sibling->Color = RBTNode::BLACK;
				successor->Parent->Color = RBTNode::RED;
				RBT_RotateLeft( root, successor->Parent );
			}
			else
			{
				// ���� ��尡 ���̰�,
				// ���� ����� ����, ������ �ڽ��� ��� ���� ���
				if ( sibling->Left->Color == RBTNode::BLACK && 
					sibling->Right->Color == RBTNode::BLACK )
				{
					sibling->Color = RBTNode::RED;
					successor = successor->Parent;
				}
				else
				{
					// ���� �� ���� ���� ������ ���� ����� �ڽ��� ������ ���
					if ( sibling->Left->Color == RBTNode::RED )
					{
						sibling->Color = RBTNode::RED;
						sibling->Left->Color = RBTNode::BLACK;
						
						RBT_RotateRight( root, sibling );
						sibling = successor->Parent->Right;
					}

					// ���� �� ���� �ٸ� ������ ���� ����� �ڽ��� ������ ���
					sibling->Color = successor->Parent->Color;
					successor->Parent->Color = RBTNode::BLACK;
					sibling->Right->Color = RBTNode::BLACK;

					RBT_RotateLeft( root, successor->Parent );
					successor = *root;
				}
			}
		}
		else
		{
			RBTNode* sibling = successor->Parent->Left;

			if ( sibling->Color == RBTNode::RED )
			{
				sibling->Color = RBTNode::BLACK;
				successor->Parent->Color = RBTNode::RED;
				
				RBT_RotateRight( root, successor->Parent );
			}
			else
			{
				if ( sibling->Left->Color == RBTNode::BLACK &&
					sibling->Right->Color == RBTNode::BLACK )
				{
					sibling->Color = RBTNode::RED;
					successor = successor->Parent;
				}
				else
				{
					if ( sibling->Right->Color == RBTNode::RED )
					{
						sibling->Right->Color = RBTNode::BLACK;
						sibling->Color = RBTNode::RED;

						RBT_RotateLeft( root, sibling );
						sibling = successor->Parent->Left;
					}

					sibling->Color = successor->Parent->Color;
					successor->Parent->Color = RBTNode::BLACK;
					sibling->Left->Color = RBTNode::BLACK;
					RBT_RotateRight( root, successor->Parent );
					successor = *root;
				}
			}
		}
	}

	successor->Color = RBTNode::BLACK;
}

void RBT_PrintTree( RBTNode* node, int depth, int blackCount )
{
	char c = 'X';
	int v = -1;
	char cnt[100];

	if ( node == nullptr || node == Nil )
	{
		return;
	}

	if ( node->Color == RBTNode::BLACK )
	{
		blackCount++;
	}

	if ( node->Parent != NULL )
	{
		v = node->Parent->Data;

		if ( node->Parent->Left == node )
		{
			c = 'L';
		}
		else
		{
			c = 'R';
		}
	}

	if ( node->Left == Nil && node->Right == Nil )
	{
		sprintf( cnt, "---------- %d", blackCount );
	}
	else
	{
		strncpy( cnt, "", sizeof( cnt ) );
	}

	for ( int i = 0; i < depth; i++ )
	{
		printf( "  " );
	}

	printf( "%d %s [%c,%d] %s\n", node->Data,
		node->Color == RBTNode::RED ? "RED" : "BLACK", c, v, cnt );

	RBT_PrintTree( node->Left, depth + 1, blackCount );
	RBT_PrintTree( node->Right, depth + 1, blackCount );
}

void RBT_RotateLeft( RBTNode** root, RBTNode* parent )
{
	RBTNode* rightChild = parent->Right;

	parent->Right = rightChild->Left;

	// ������ �ڽ� ����� ���� �ڽ� ��带 �θ� ���� ����
	if ( rightChild->Left != Nil )
	{
		rightChild->Left->Parent = parent;
	}

	// ������ �ڽ� ���� �θ� ����� ��ġ ����
	if ( parent->Parent == nullptr )
	{
		*root = rightChild;
	}
	else
	{
		// �θ� ����� �θ� ���� ������ �ڽ� ��� ����
		if ( parent == parent->Parent->Left )
		{
			parent->Parent->Left = rightChild;
		}
		else
		{
			parent->Parent->Right = rightChild;
		}
	}

	rightChild->Left = parent;
	parent->Parent = rightChild;
}

void RBT_RotateRight( RBTNode** root, RBTNode* parent )
{
	RBTNode* leftChild = parent->Left;

	// ���� �ڽ� ����� ������ �ڽ� ��带 �θ� ���� ����
	parent->Left = leftChild->Right;

	if ( leftChild->Right != nullptr )
	{
		leftChild->Right->Parent = parent;
	}

	// �θ� ���� ���� �ڽ� ����� ��ġ ����
	leftChild->Parent = parent->Parent;

	// �Ѹ� ����� ���
	if ( parent->Parent == nullptr )
	{
		*root = leftChild;
	}
	else
	{	 
		// �θ� ��尡 ���� �ڽ� ����� ���
		if ( parent == parent->Parent->Left )
		{
			parent->Parent->Left = leftChild;
		}
		else
		{
			parent->Parent->Right = leftChild;
		}
	}

	leftChild->Right = parent;
	parent->Parent = leftChild;
}
