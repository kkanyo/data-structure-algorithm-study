//void LCRSTree()
//{
//	LCRSNode* root = LCRS_CreateNode( 'A' );
//	LCRSNode* b = LCRS_CreateNode( 'B' );
//	LCRSNode* d = LCRS_CreateNode( 'D' );
//	LCRSNode* g = LCRS_CreateNode( 'G' );
//	LCRSNode* i = LCRS_CreateNode( 'I' );
//	LCRSNode* j = LCRS_CreateNode( 'J' );
//
//	LCRS_AddChildNode( root, b );
//	LCRS_AddChildNode( b, LCRS_CreateNode( 'C' ) );
//	LCRS_AddChildNode( b, d );
//	LCRS_AddChildNode( d, LCRS_CreateNode( 'E' ) );
//	LCRS_AddChildNode( d, LCRS_CreateNode( 'F' ) );
//
//	LCRS_AddChildNode( root, g );
//	LCRS_AddChildNode( g, LCRS_CreateNode( 'H' ) );
//
//	LCRS_AddChildNode( root, i );
//	LCRS_AddChildNode( i, j );
//	LCRS_AddChildNode( j, LCRS_CreateNode( 'K' ) );
//
//	LCRS_PrintTree( root, 0 );
//
//	LCRS_DestroyTree( root );
//
//	return 0;
//}

//void SBTTree()
//{
//	SBTNode* A = SBT_CreateNode( 'A' );
//	SBTNode* B = SBT_CreateNode( 'B' );
//	SBTNode* C = SBT_CreateNode( 'C' );
//	SBTNode* D = SBT_CreateNode( 'D' );
//	SBTNode* E = SBT_CreateNode( 'E' );
//	SBTNode* F = SBT_CreateNode( 'F' );
//	SBTNode* G = SBT_CreateNode( 'G' );
//
//	A->Left = B;
//	B->Left = C;
//	B->Right = D;
//
//	A->Right = E;
//	E->Left = F;
//	E->Right = G;
//
//	printf( "Preorder ...\n" );
//	SBT_PreorderPrintTree( A );
//	printf( "\n\n" );
//
//	printf( "Inorder ...\n" );
//	SBT_InorderPrintTree( A );
//	printf( "\n\n" );
//
//	printf( "Postorder ...\n" );
//	SBT_PostorderPrintTree( A );
//	printf( "\n\n" );
//
//	SBT_DestroyTree( A );
//}

//void ETTree()
//{
//	SBTNode* root = nullptr;
//
//	char postfixExpression[20] = "71*52-/";
//	ET_BuildExpressionTree( postfixExpression, &root );
//
//	printf( "Preorder ...\n" );
//	SBT_PreorderPrintTree( root );
//	printf( "\n\n" );
//
//	printf( "Inorder ...\n" );
//	SBT_InorderPrintTree( root );
//	printf( "\n\n" );
//
//	printf( "Postorder ...\n" );
//	SBT_PostorderPrintTree( root );
//	printf( "\n" );
//
//	printf( "Evaulation Result : %f \n", ET_Evaluate( root ) );
//
//	SBT_DestroyTree( root );
//
//}

//void DisJointSet()
//{
//
//	int a = 1, b = 2, c = 3, d = 4;
//	DisjointSet* set1 = DS_MakeSet( &a );
//	DisjointSet* set2 = DS_MakeSet( &b );
//	DisjointSet* set3 = DS_MakeSet( &c );
//	DisjointSet* set4 = DS_MakeSet( &d );
//
//	printf( "Set1 == Set2 ; %d\n", DS_FindSet( set1 ) == DS_FindSet( set2 ) );
//
//	DS_UnionSet( set1, set3 );
//	printf( "Set1 == Set3 ; %d\n", DS_FindSet( set1 ) == DS_FindSet( set3 ) );
//
//	DS_UnionSet( set1, set4 );
//	printf( "Set1 == Set4 ; %d\n", DS_FindSet( set1 ) == DS_FindSet( set4 ) );
//
//	return 0;
//}