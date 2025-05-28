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
	RBTNode* removed = nullptr;		// 실제 삭제될 노드
	RBTNode* successor = nullptr;	// 대체 노드
	RBTNode* target = RBT_SearchNode( *root, data );
	
	if ( target == nullptr || target == Nil )
	{
		return nullptr;
	}

	if ( target->Left == Nil || target->Right == Nil )
	{
		// 자식이 한쪽만 있거나 없는 경우 자신이 삭제되고 자식을 연결해주면 된다.
		removed = target;
	}
	else
	{
		// 오른쪽 하위 트리에서 최솟값 노드로 대체한다. (최솟값 노드가 삭제 된다.)
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

	// 삭제 노드가 검은색인 경우 규칙을 만족하기 위해 재구성한다.
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

			// 삼촌 노드가 빨간색인 경우
			if ( uncle->Color == RBTNode::RED )
			{
				newNode->Parent->Color = RBTNode::BLACK;
				uncle->Color = RBTNode::BLACK;
				newNode->Parent->Parent->Color = RBTNode::RED;

				newNode = newNode->Parent->Parent;
			}
			// 삼촌 노드가 검은색인 경우
			else
			{
				// 새로 삽입한 노드가 부모 노드와 다른 방향인 경우
				if ( newNode == newNode->Parent->Right )
				{
					newNode = newNode->Parent;
					RBT_RotateLeft( root, newNode );
				}

				// 새로 삽입한 노드가 부모 노드와 같은 방향인 경우
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

	// 뿌리 노드는 반드시 검은색이어야 한다.
	( *root )->Color = RBTNode::BLACK;
}

void RBT_RebuildAfterRemove( RBTNode** root, RBTNode* successor )
{
	// 뿌리 노드이거나 빨간색 노드로 넘어가면 종료
	while ( successor->Parent != nullptr && successor->Color == RBTNode::BLACK )
	{
		if ( successor == successor->Parent->Left )
		{
			RBTNode* sibling = successor->Parent->Right;

			// 형제 노드가 빨간색인 경우
			if ( sibling->Color == RBTNode::RED )
			{
				sibling->Color = RBTNode::BLACK;
				successor->Parent->Color = RBTNode::RED;
				RBT_RotateLeft( root, successor->Parent );
			}
			else
			{
				// 형제 노드가 블랙이고,
				// 형제 노드의 왼쪽, 오른쪽 자식이 모두 블랙인 경우
				if ( sibling->Left->Color == RBTNode::BLACK && 
					sibling->Right->Color == RBTNode::BLACK )
				{
					sibling->Color = RBTNode::RED;
					successor = successor->Parent;
				}
				else
				{
					// 이중 블랙 노드와 같은 방향의 형제 노드의 자식이 레드인 경우
					if ( sibling->Left->Color == RBTNode::RED )
					{
						sibling->Color = RBTNode::RED;
						sibling->Left->Color = RBTNode::BLACK;
						
						RBT_RotateRight( root, sibling );
						sibling = successor->Parent->Right;
					}

					// 이중 블랙 노드와 다른 방향의 형제 노드의 자식이 레드인 경우
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

	// 오른쪽 자식 노드의 왼쪽 자식 노드를 부모 노드와 연결
	if ( rightChild->Left != Nil )
	{
		rightChild->Left->Parent = parent;
	}

	// 오른쪽 자식 노드와 부모 노드의 위치 변경
	if ( parent->Parent == nullptr )
	{
		*root = rightChild;
	}
	else
	{
		// 부모 노드의 부모 노드와 오른쪽 자식 노드 연결
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

	// 왼쪽 자식 노드의 오른쪽 자식 노드를 부모 노드와 연결
	parent->Left = leftChild->Right;

	if ( leftChild->Right != nullptr )
	{
		leftChild->Right->Parent = parent;
	}

	// 부모 노드와 왼쪽 자식 노드의 위치 변경
	leftChild->Parent = parent->Parent;

	// 뿌리 노드인 경우
	if ( parent->Parent == nullptr )
	{
		*root = leftChild;
	}
	else
	{	 
		// 부모 노드가 왼쪽 자식 노드인 경우
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
