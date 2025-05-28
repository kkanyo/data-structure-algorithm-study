
//void TestArrayStack()
//{
//	ArrayStack* stack = NULL;
//
//	AS_CreateStack( &stack, 10 );
//
//	AS_Push( stack, 3 );
//	AS_Push( stack, 37 );
//	AS_Push( stack, 11 );
//	AS_Push( stack, 12 );
//
//	printf( "Capacity: %d, Size: %d, Top: %d\n\n", stack->Capacity, AS_GetSize( stack ), stack->Top );
//
//	for ( int i = 0; i < 4; i++ )
//	{
//		if ( AS_IsEmpty( stack ) )
//		{
//			break;
//		}
//
//		printf( "Popped: %d, ", AS_Pop( stack ) );
//
//		if ( !AS_IsEmpty( stack ) )
//		{
//			printf( "Current Top: %d\n", AS_Top( stack ) );
//		}
//		else
//		{
//			printf( "Stack is empty.\n" );
//		}
//	}
//
//	for ( int i = 0; i < 11; i++ )
//	{
//		if ( AS_IsFull( stack ) )
//		{
//			printf( "Stack is full.\n" );
//			break;
//		}
//
//		AS_Push( stack, i );
//	}
//
//	AS_DestroyStack( stack );
//
//}
//
//void TestLinkedListStack() {
//	int count = 0;
//
//	Node* popped = nullptr;
//	LinkedListStack* stack = nullptr;
//
//	LLS_CreateStack( &stack );
//
//	LLS_Push( stack, LLS_CreateNode( "abc" ) );
//	LLS_Push( stack, LLS_CreateNode( "def" ) );
//	LLS_Push( stack, LLS_CreateNode( "efg" ) );
//	LLS_Push( stack, LLS_CreateNode( "hij" ) );
//
//	count = LLS_GetSize( stack );
//	printf( "Size: %d, Top: %s\n\n", count, LLS_Top( stack )->Data );
//
//	for ( int i = 0; i < count; i++ )
//	{
//		if ( LLS_IsEmpty( stack ) )
//		{
//			break;
//		}
//
//		popped = LLS_Pop( stack );
//
//		printf( "Popped: %s, ", popped->Data );
//
//		LLS_DestroyNode( popped );
//
//		if ( !LLS_IsEmpty( stack ) )
//		{
//			printf( "Current Top: %s\n", LLS_Top( stack )->Data );
//		}
//		else
//		{
//			printf( "Stack is empty.\n" );
//		}
//	}
//
//	LLS_DestroyStack( stack );
//
//}