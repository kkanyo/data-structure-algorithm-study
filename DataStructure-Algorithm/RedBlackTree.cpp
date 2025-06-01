#include "RedBlackTree.h"

RedBlackTree::RedBlackTree()
{
	root = nullptr;
	
	nil = new RBTNode();
	nil->Parent = nullptr;
	nil->Left = nullptr;
	nil->Right = nullptr;
	nil->Color = Color::BLACK;
	nil->Data = 0; // Sentinel node does not hold valid data
}

RedBlackTree::~RedBlackTree()
{
	destroyTree( root );
	destroyNode( nil ); // Delete the sentinel node
}

RBTNode* RedBlackTree::SearchNode( ElementType target, RBTNode* root )
{
	if ( root == nullptr )
	{
		root = this->root;
	}

	if ( root == nil )
	{
		return nullptr;
	}

	if ( root->Data > target )
	{
		SearchNode( target, root->Left);
	}
	else if ( root->Data < target )
	{
		SearchNode( target, root->Right );
	}
	else
	{
		return root;
	}

	return nullptr;
}

RBTNode* RedBlackTree::SearchMinNode( RBTNode* root )
{
	if ( root == nullptr || root == nil )
	{
		return nullptr;
	}

	if ( root->Left != nil )
	{
		SearchMinNode( root->Left );
	}
	else
	{
		return root;
	}
	
	return nullptr;
}

void RedBlackTree::InsertNode( ElementType value )
{
	RBTNode* newNode = new RBTNode();
	newNode->Left = nil;
	newNode->Right = nil;
	newNode->Data = value;
	newNode->Color = Color::RED;

	insertNodeHelper( &root, newNode );

	rebuildAfterInsert( newNode );
}

void RedBlackTree::RemoveNode( ElementType value )
{
	RBTNode* remove = nullptr;
	RBTNode* successor = nullptr;
	RBTNode* target = SearchNode( value );
	
	if ( target == nullptr )
	{
		return;
	}

	// �ڽ��� �ϳ��ų� ������ ����
	if ( target->Left == nil || target->Right == nil )
	{
		remove = target;
	}
	else
	{
		// �ڽ��� ���� ���� ������ ������ ���� Ʈ���� �ּڰ� ���� ��ü�Ѵ�. (���� �����Ǵ� ���� ��ü�� ���)
		remove = SearchMinNode( target->Right );
		target->Data = remove->Data;
	}

	// ���� �ڽ��� ������
	if ( remove->Left != nil )
	{
		successor = remove->Left;
	}
	else
	{
		successor = remove->Right;
	}

	// ������ ���� ��ü ��带 ��ȯ�Ѵ�.
	successor->Parent = remove->Parent;
	
	if ( remove->Parent == nullptr )
	{
		this->root = successor;
	}
	else
	{
		if ( remove == remove->Parent->Left )
		{
			remove->Parent->Left = successor;
		}
		else
		{
			remove->Parent->Right = successor;
		}
	}

	// ������ ��尡 ���� ���, ��Ģ�� ���� �� �����Ƿ� ������ �����.
	if ( remove->Color == Color::BLACK )
	{
		rebuildAfterRemove( successor );
	}

	destroyNode( remove );
}

void RedBlackTree::Print( RBTNode* node, int depth, int blackCount )
{
	ElementType value = -1;
	char nodeType = 'P';
	char buffer[100];

	if ( node == nullptr )
	{
		node = root;
	}

	if ( node == nil )
	{
		return;
	}

	if ( node->Color == Color::BLACK )
	{
		blackCount++;
	}

	if ( node->Parent != nullptr )
	{
		value = node->Parent->Data;

		if ( node->Parent->Left == node )
		{
			nodeType = 'L';
		}
		else
		{
			nodeType = 'R';
		}
	}

	if ( node->Left == nil && node->Right == nil )
	{
		sprintf_s( buffer, "---------- %d", blackCount );
	}
	else
	{
		strncpy_s( buffer, "", sizeof( buffer ) );
	}

	for ( int i = 0; i < depth; i++ )
	{
		printf( "   " );
	}

	printf( "%d %s [%c, %d] %s\n", node->Data,
		node->Color == Color::RED ? "RED" : "BLACK",
		nodeType,
		value,
		buffer );

	Print( node->Left, depth + 1, blackCount );
	Print( node->Right, depth + 1, blackCount );

	depth = 0;
	blackCount = 0;
}

void RedBlackTree::rotateLeft( RBTNode* parent )
{
	if ( parent == nullptr )
	{
		return;
	}

	RBTNode* rightChild = parent->Right;
	if ( rightChild == nil )
	{
		// ������ �ڽ��� ������ ȸ���� �ʿ䰡 ����.
		return;
	}
	
	// ������ �ڽ� ����� ���� �ڽ� ��带 �θ� ����� ������ �ڽ����� �����Ѵ�.
	parent->Right = rightChild->Left;
	if ( rightChild->Left != nil ) {
		rightChild->Left->Parent = parent;
	}

	// ������ �ڽİ� �θ��� ��ġ�� ��ȯ�Ѵ�.
	rightChild->Parent = parent->Parent;
	if ( parent->Parent == nullptr )
	{
		root = rightChild;
	}
	else if ( parent == parent->Parent->Left )
	{
		parent->Parent->Left = rightChild;
	}
	else
	{
		parent->Parent->Right = rightChild;
	}
	
	rightChild->Left = parent;
	parent->Parent = rightChild;
}

void RedBlackTree::rotateRight( RBTNode* parent )
{
	if ( parent == nullptr )
	{
		return;
	}

	RBTNode* leftChild = parent->Left;
	if ( leftChild == nil )
	{
		// ���� �ڽ��� ������ ȸ���� �ʿ䰡 ����.
		return;
	}

	parent->Left = leftChild->Right;
	if ( leftChild->Right != nil ) {
		leftChild->Right->Parent = parent;
	}

	leftChild->Parent = parent->Parent;
	if ( parent->Parent == nullptr )
	{
		root = leftChild;
	}
	else if ( parent == parent->Parent->Left )
	{
		parent->Parent->Left = leftChild;
	}
	else
	{
		parent->Parent->Right = leftChild;
	}

	leftChild->Right = parent;
	parent->Parent = leftChild;
}

void RedBlackTree::insertNodeHelper( RBTNode** root, RBTNode* newNode )
{
	if ( newNode == nullptr )
	{
		return;
	}

	if ( *root == nullptr )
	{
		newNode->Parent = nullptr;
		*root = newNode;
	}
	else
	{
		if ( ( *root )->Data > newNode->Data )
		{
			if ( ( *root )->Left != nil )
			{
				insertNodeHelper( &( *root )->Left, newNode );
			}
			else
			{
				( *root )->Left = newNode;
				newNode->Parent = *root;
			}
		}
		else if ( ( *root )->Data < newNode->Data )
		{
			if ( ( *root )->Right != nil )
			{
				insertNodeHelper( &( *root )->Right, newNode );
			}
			else
			{
				( *root )->Right = newNode;
				newNode->Parent = *root;
			}
		}
	}
}

void RedBlackTree::rebuildAfterInsert( RBTNode* newNode )
{
	bool isLeftParent = false;
	bool isLeft = false;
	RBTNode* uncle = nullptr;

	while ( newNode->Parent != nullptr && newNode->Parent->Color == Color::RED )
	{
		if ( newNode->Parent->Parent == nullptr )
		{
			return;
		}

		isLeftParent =
			newNode->Parent == newNode->Parent->Parent->Left ? true : false ;

		uncle = isLeftParent ?
			newNode->Parent->Parent->Right : newNode->Parent->Parent->Left;

		if ( uncle->Color == Color::RED )
		{
			newNode->Parent->Color = Color::BLACK;
			uncle->Color = Color::BLACK;
			newNode->Parent->Parent->Color = Color::RED;

			newNode = newNode->Parent->Parent;
		}
		else
		{
			isLeft = newNode == newNode->Parent->Left ? true : false;

			// ���Ե� ���� �θ� ��尡 �ݴ� ������ ���
			if ( isLeft != isLeftParent )
			{
				isLeft ? rotateRight( newNode->Parent ) : rotateLeft( newNode->Parent );
				newNode = newNode->Parent;
			}

			// ���Ե� ���� �θ� ��尡 ���� ������ ���
			newNode->Parent->Color = Color::BLACK;
			newNode->Parent->Parent->Color = Color::RED;
			isLeft ? rotateRight( newNode->Parent->Parent ) : rotateLeft( newNode->Parent->Parent );
		}
	}

	root->Color = Color::BLACK;
}

void RedBlackTree::rebuildAfterRemove( RBTNode* successor )
{
	bool isLeft = false;
	RBTNode* sibling = nullptr;

	while ( successor->Parent != nullptr && successor->Color == Color::BLACK )
	{
		isLeft = successor == successor->Parent->Left ? true : false;
		
		sibling = isLeft ? successor->Parent->Right : successor->Parent->Left;

		// ���� ��尡 ������ ��� (���� �� ������ ���� ������, ���� ��尡 �� ���� �ٲ��.)
		if ( sibling->Color == Color::RED )
		{
			sibling->Color = Color::BLACK;
			successor->Parent->Color = Color::RED;
			rotateLeft( successor->Parent );
		}
		else
		{
			// ���� ����� ���� �ڽ��� ��� ���� ���
			if ( sibling->Left->Color == Color::BLACK &&
				sibling->Right->Color == Color::BLACK )
			{
				sibling->Color = Color::RED;
				successor = successor->Parent;	// �θ� ��忡�� ���� �� ������ �ѱ��.
			}
			else
			{
				// ���� �� ���� ���� ������ �ڽ��� ������ ���
				if ( ( isLeft ? sibling->Left->Color == Color::RED :
					sibling->Right->Color == Color::RED ) )
				{
					sibling->Color = Color::RED;
					
					if ( isLeft )
					{
						sibling->Left->Color = Color::BLACK;
						rotateRight( sibling );
						sibling = successor->Parent->Right;
					}
					else
					{
						sibling->Right->Color = Color::BLACK;
						rotateLeft( sibling );
						sibling = successor->Parent->Left;
					}
				}

				// ���� �� ���� �ݴ� ������ �ڽ��� ������ ���
				sibling->Color = successor->Parent->Color;
				successor->Parent->Color = Color::BLACK;

				if ( isLeft )
				{
					sibling->Right->Color = Color::BLACK;
					rotateLeft( successor->Parent );
				}
				else
				{
					sibling->Left->Color = Color::BLACK;
					rotateRight( successor->Parent );
				}
				successor = root;
			}
		}
	}

	successor->Color = Color::BLACK;
}

void RedBlackTree::destroyNode( RBTNode* node )
{
	delete( node );
}

void RedBlackTree::destroyTree( RBTNode* root )
{
	if ( root == nullptr || root == nil )
	{
		return;
	}

	if ( root->Left != nil )
	{
		destroyTree( root->Left );
	}

	if ( root->Right != nil )
	{
		destroyTree( root->Right );
	}

	destroyNode( root );
}
