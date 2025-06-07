#pragma once

// �ؽ� ���̺� ����� ����
enum ElementStatus
{
	EMPTY = 0,
	OCCUPIED = 1,
};

enum VisitMode
{
	VISITED,
	NOTVISITED
};

typedef void* ElementType;

typedef void* KeyType;
typedef void* ValueType;

typedef struct LinkedNode
{
	ElementType Data;
	struct LinkedNode* Next;
} LinkedNode;

int Compare( const void* a, const void* b );
