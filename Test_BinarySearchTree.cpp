#include "BinarySearchTree.h"
#include "RedBlackTree.h"

static void PrintSearchResult( int searchTarget, BSTNode* result )
{
	if ( result != nullptr )
	{
		printf( "Found: %d \n", result->Data );
	}
	else
	{
		printf( "Not Found: %d\n", searchTarget );
	}
}

static int TestBinarySearchTree( )
{
	BSTNode* tree = BST_CreateNode( 123 );
	BSTNode* node = nullptr;

	BST_InsertNode( tree, BST_CreateNode( 22 ) );
	BST_InsertNode( tree, BST_CreateNode( 9918 ) );
	BST_InsertNode( tree, BST_CreateNode( 424 ) );
	BST_InsertNode( tree, BST_CreateNode( 17 ) );
	BST_InsertNode( tree, BST_CreateNode( 3 ) );

	BST_InsertNode( tree, BST_CreateNode( 98 ) );
	BST_InsertNode( tree, BST_CreateNode( 100 ) );
	BST_InsertNode( tree, BST_CreateNode( 34 ) );
	BST_InsertNode( tree, BST_CreateNode( 30 ) );
	BST_InsertNode( tree, BST_CreateNode( 36 ) );

	BST_InsertNode( tree, BST_CreateNode( 760 ) );
	BST_InsertNode( tree, BST_CreateNode( 317 ) );
	BST_InsertNode( tree, BST_CreateNode( 1 ) );

	int SearchTarget = 17;
	node = BST_SearchNode( tree, SearchTarget );
	PrintSearchResult( SearchTarget, node );

	SearchTarget = 117;
	node = BST_SearchNode( tree, SearchTarget );
	PrintSearchResult( SearchTarget, node );

	BST_InorderPrintTree( tree );
	printf( "\n" );

	printf( "Removing 98...\n" );

	node = BST_RemoveNode( tree, nullptr, 98 );
	//BST_DestroyNode( node );

	BST_InorderPrintTree( tree );
	printf( "\n" );

	printf( "Inserting 111...\n" );

	BST_InsertNode( tree, BST_CreateNode( 111 ) );
	BST_InorderPrintTree( tree );
	printf( "\n" );

	BST_DestroyTree( tree );

	return 0;
}

static void TestRedBlackTree()
{
	RedBlackTree* tree = new RedBlackTree();
	RBTNode* node = nullptr;

	while ( 1 )
	{
		int cmd = 0;
		int param = 0;
		char buffer[10];

		printf( "Enter command number :\n" );
		printf( "(1) Create a node\n" );
		printf( "(2) Remove a node\n" );
		printf( "(3) Search a Node\n" );
		printf( "(4) Display Tree\n" );
		printf( "(5) quit\n" );
		printf( "command number: " );

		fgets( buffer, sizeof( buffer ) - 1, stdin );
		int result = sscanf( buffer, "%d", &cmd );

		if ( cmd < 1 || cmd > 5 )
		{
			printf( "Invali command number.\n" );
			continue;
		}
		else if ( cmd == 4 )
		{
			tree->Print();
			printf( "\n" );
			continue;
		}
		else if ( cmd == 5 )
		{
			break;
		}

		printf( "Enter parameter (1~200) :\n" );

		fgets( buffer, sizeof( buffer ) - 1, stdin );
		result = sscanf( buffer, "%d", &param );
	
		if ( param < 1 || param > 200 )
		{
			printf( "Invalid parameter.%d\n", param );
			continue;
		}

		switch ( cmd )
		{
		case 1:
			tree->InsertNode( param );
			break;
		case 2:
			tree->RemoveNode( param );
			break;
		case 3:
			node = tree->SearchNode( param );

			if ( node == nullptr )
			{
				printf( "Not found node:%d\n", param );
			}
			else
			{
				printf( "Found node: %d(Color:%s)\n",
					node->Data, node->Color == Color::RED ? "RED" : "BLACK" );
			}
			break;
		}
		printf( "\n" );

	}
}