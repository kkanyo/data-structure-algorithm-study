//void TestLinkedList() {
//	int i = 0;
//	int count = 0;
//	Node* list = NULL;
//	Node* current = NULL;
//	Node* newNode = NULL;
//
//	for ( i = 0; i < 5; i++ )
//	{
//		newNode = SLL_CreateNode( i );
//		SLL_AppendNode( &list, newNode );
//	}
//
//	newNode = SLL_CreateNode( -1 );
//	SLL_InsertNewHead( &list, newNode );
//
//	newNode = SLL_CreateNode( -2 );
//	SLL_InsertNewHead( &list, newNode );
//
//	// print list
//	count = SLL_GetNodeCount( list );
//	for ( i = 0; i < count; i++ )
//	{
//		current = SLL_GetNodeAt( list, i );
//		printf( "List[%d] : %d\n", i, current->Data );
//	}
//
//	printf( "\nInserting 3000 after [2]...\n\n" );
//
//	current = SLL_GetNodeAt( list, 2 );
//	newNode = SLL_CreateNode( 3000 );
//
//	SLL_InsertAfter( current, newNode );
//
//	// print list
//	count = SLL_GetNodeCount( list );
//	for ( i = 0; i < count; i++ )
//	{
//		current = SLL_GetNodeAt( list, i );
//		printf( "List[%d] : %d\n", i, current->Data );
//	}
//
//	printf( "\nInserting 3000 before [2]...\n\n" );
//
//	current = SLL_GetNodeAt( list, 2 );
//	newNode = SLL_CreateNode( 1000 );
//
//	SLL_InsertBefore( &list, current, newNode );
//
//	// print list
//	count = SLL_GetNodeCount( list );
//	for ( i = 0; i < count; i++ )
//	{
//		current = SLL_GetNodeAt( list, i );
//		printf( "List[%d] : %d\n", i, current->Data );
//	}
//
//	// remove all node from memory
//	printf( "\nDestroying List...\n" );
//
//	for ( i = 0; i < count; i++ )
//	{
//		current = SLL_GetNodeAt( list, 0 );
//
//		if ( current != NULL )
//		{
//			//SLL_RemoveNode( &list, current );
//			//SLL_DestroyNode( current );
//		}
//	}
//
//	SLL_DestroyAllNodes( &list );
//}
//
//void TestDoublyLinkedList() {
//	int i = 0;
//	int count = 0;
//	Node* list = NULL;
//	Node* newNode = NULL;
//	Node* current = NULL;
//
//	for ( i = 0; i < 5; i++ )
//	{
//		newNode = DLL_CreateNode( i );
//		DLL_AppendNode( &list, newNode );
//	}
//
//	count = DLL_GetNodeCount( list );
//	for ( i = 0; i < count; i++ )
//	{
//		current = DLL_GetNodeAt( list, i );
//		printf( "List[%d] : %d\n", i, current->Data );
//	}
//
//	printf( "\nInserting 3000 after [2]...\n" );
//
//	current = DLL_GetNodeAt( list, 2 );
//	DLL_InsertAfter( current, DLL_CreateNode( 3000 ) );
//
//	count = DLL_GetNodeCount( list );
//	for ( i = 0; i < count; i++ )
//	{
//		current = DLL_GetNodeAt( list, i );
//		printf( "List[%d] : %d\n", i, current->Data );
//	}
//
//
//	printf( "\nInserting 1000 after tail...\n" );
//
//	current = DLL_GetNodeAt( list, count - 1 );
//	DLL_InsertAfter( current, DLL_CreateNode( 1000 ) );
//
//	count = DLL_GetNodeCount( list );
//	for ( i = 0; i < count; i++ )
//	{
//		current = DLL_GetNodeAt( list, i );
//		printf( "List[%d] : %d\n", i, current->Data );
//	}
//
//	printf( "\n" );
//	PrintReverse( list );
//
//	printf( "\nDestroying List...\n" );
//
//	count = DLL_GetNodeCount( list );
//
//	for ( i = 0; i < count; i++ )
//	{
//		current = DLL_GetNodeAt( list, 0 );
//
//		if ( current != NULL )
//		{
//			DLL_RemoveNode( &list, current );
//			DLL_DestroyNode( current );
//		}
//	}
//
//	return 0;
//}

//void TestCircularDoublyLinkedList()
//{
//	int i = 0;
//	int count = 0;
//	Node* list = NULL;
//	Node* current = NULL;
//
//	for ( i = 0; i < 5; i++ )
//	{
//		CDLL_AppendNode( &list, CDLL_CreateNode( i ) );
//	}
//
//	count = CDLL_GetNodeCount( list );
//	for ( i = 0; i < count; i++ )
//	{
//		current = CDLL_GetNodeAt( list, i );
//		printf( "List[%d] : %d\n", i, current->Data );
//	}
//
//	printf( "Inserting 3000 after [2]...\n\n" );
//
//	current = CDLL_GetNodeAt( list, 2 );
//	CDLL_InsertAfter( current, CDLL_CreateNode( 3000 ) );
//
//	count = CDLL_GetNodeCount( list );
//	for ( i = 0; i < count; i++ )
//	{
//		current = CDLL_GetNodeAt( list, i );
//		printf( "List[%d] : %d\n", i, current->Data );
//	}
//
//	printf( "Removing Node at 2...\n" );
//	current = CDLL_GetNodeAt( list, 2 );
//	CDLL_RemoveNode( &list, current );
//	CDLL_DestroyNode( current );
//
//	count = CDLL_GetNodeCount( list );
//	for ( i = 0; i < count; i++ )
//	{
//		current = CDLL_GetNodeAt( list, i );
//		printf( "List[%d] : %d\n", i, current->Data );
//	}
//
//	printf( "Inserting 1000 after tail ...\n" );
//
//	CDLL_InsertAfter( list->PrevNode, CDLL_CreateNode( 1000 ) );
//
//	count = CDLL_GetNodeCount( list );
//	for ( i = 0; i < count; i++ )
//	{
//		current = CDLL_GetNodeAt( list, i );
//		printf( "List[%d] : %d\n", i, current->Data );
//	}
//
//	printf( "Removing Head ...\n" );
//
//	current = list;
//	CDLL_RemoveNode( &list, list );
//	CDLL_DestroyNode( current );
//
//	count = CDLL_GetNodeCount( list );
//	for ( i = 0; i < count; i++ )
//	{
//		current = CDLL_GetNodeAt( list, i );
//		printf( "List[%d] : %d\n", i, current->Data );
//	}
//
//	count = CDLL_GetNodeCount( list );
//	for ( i = 0; i < count + 2; i++ )
//	{
//		if ( i == 0 )
//		{
//			current = list;
//		}
//		else
//		{
//			current = current->NextNode;
//		}
//
//		printf( "List[%d] : %d\n", i, current->Data );
//	}
//
//	printf( "\nDestroying List...\n" );
//
//	for ( i = 0; i < count; i++ )
//	{
//		current = CDLL_GetNodeAt( list, 0 );
//
//		if ( current != NULL )
//		{
//			CDLL_RemoveNode( &list, current );
//			CDLL_DestroyNode( current );
//		}
//	}
//}