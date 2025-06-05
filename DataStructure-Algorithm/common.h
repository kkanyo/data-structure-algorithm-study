#pragma once

// 해시 테이블 요소의 상태
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

