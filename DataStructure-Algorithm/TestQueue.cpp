//
//void TestCircularQueue()
//{
//	CircularQueue* queue = nullptr;
//
//	CQ_CreateQueue( &queue, 5 );
//	printf( "Is empty?: %s\n", CQ_IsEmpty( queue ) ? "true" : "false" );
//	printf( "Is full?: %s\n", CQ_IsFull( queue ) ? "true" : "false" );
//
//	CQ_Enqueue( queue, 1 );
//	CQ_Enqueue( queue, 2 );
//	CQ_Enqueue( queue, 3 );
//	CQ_Enqueue( queue, 4 );
//
//	printf( "Is empty?: %s\n", CQ_IsEmpty( queue ) ? "true" : "false" );
//	printf( "Is full?: %s\n", CQ_IsFull( queue ) ? "true" : "false" );
//
//	CQ_Enqueue( queue, 5 );
//	printf( "Is empty?: %s\n", CQ_IsEmpty( queue ) ? "true" : "false" );
//	printf( "Is full?: %s\n", CQ_IsFull( queue ) ? "true" : "false" );
//
//	CQ_Enqueue( queue, 5 );
//	printf( "Is empty?: %s\n", CQ_IsEmpty( queue ) ? "true" : "false" );
//	printf( "Is full?: %s\n", CQ_IsFull( queue ) ? "true" : "false" );
//
//	printf( "dequeue: %d\n", CQ_Dequeue( queue ) );
//	printf( "Is empty?: %s\n", CQ_IsEmpty( queue ) ? "true" : "false" );
//	printf( "Is full?: %s\n", CQ_IsFull( queue ) ? "true" : "false" );
//
//	printf( "dequeue: %d\n", CQ_Dequeue( queue ) );
//	printf( "dequeue: %d\n", CQ_Dequeue( queue ) );
//	printf( "dequeue: %d\n", CQ_Dequeue( queue ) );
//	printf( "dequeue: %d\n", CQ_Dequeue( queue ) );
//	printf( "Is empty?: %s\n", CQ_IsEmpty( queue ) ? "true" : "false" );
//	printf( "Is full?: %s\n", CQ_IsFull( queue ) ? "true" : "false" );
//
//	CQ_Enqueue( queue, 1 );
//	printf( "dequeue: %d\n", CQ_Dequeue( queue ) );
//	printf( "Is empty?: %s\n", CQ_IsEmpty( queue ) ? "true" : "false" );
//	printf( "Is full?: %s\n", CQ_IsFull( queue ) ? "true" : "false" );
//
//	printf( "dequeue: %d\n", CQ_Dequeue( queue ) );
//	printf( "Is empty?: %s\n", CQ_IsEmpty( queue ) ? "true" : "false" );
//	printf( "Is full?: %s\n", CQ_IsFull( queue ) ? "true" : "false" );
//
//}
//
//void LinkedQueue()
//{
//	LinkedQueue<const char*>* queue = new LinkedQueue<const char*>();
//
//	printf( "is empty?: %s\n", queue->IsEmpty() ? "true" : "false" );
//	queue->Enqueue( "abc" );
//	queue->Enqueue( "def" );
//	queue->Enqueue( "hij" );
//	queue->Enqueue( "klm" );
//	printf( "is empty?: %s\n", queue->IsEmpty() ? "true" : "false" );
//
//	printf( "count: %d, queue: %s\n", queue->GetSize(), queue->Dequeue() );
//	printf( "count: %d, queue: %s\n", queue->GetSize(), queue->Dequeue() );
//	printf( "count: %d, queue: %s\n", queue->GetSize(), queue->Dequeue() );
//	printf( "count: %d, queue: %s\n", queue->GetSize(), queue->Dequeue() );
//	printf( "count: %d, queue: %s\n", queue->GetSize(), queue->Dequeue() );
//	printf( "is empty?: %s\n", queue->IsEmpty() ? "true" : "false" );
//
//	queue->Enqueue( "abc" );
//	printf( "is empty?: %s\n", queue->IsEmpty() ? "true" : "false" );
//	printf( "count: %d, queue: %s\n", queue->GetSize(), queue->Dequeue() );
//	printf( "is empty?: %s\n", queue->IsEmpty() ? "true" : "false" );
//
//	return 0;
//}