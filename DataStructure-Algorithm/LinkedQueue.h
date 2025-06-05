#pragma once

#include <stdio.h>
#include <stdlib.h>

#include "common.h"

typedef struct LinkedQueue
{
	LinkedNode* Front;
	LinkedNode* Rear;
	int Count;
} LinkedQueue;

void LQ_CreateQueue( LinkedQueue** queue );
void LQ_DestroyQueue( LinkedQueue* queue );

LinkedNode* LQ_CreateNode( ElementType data );
void LQ_DestroyNode( LinkedNode* node );

void LQ_Enqueue( LinkedQueue* queue, LinkedNode* node );
LinkedNode* LQ_Dequeue( LinkedQueue* queue );

int LQ_IsEmpty( LinkedQueue* queue );