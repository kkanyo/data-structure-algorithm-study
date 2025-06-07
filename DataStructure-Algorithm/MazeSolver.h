#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1024
#define INIT_VALUE -1

#define START	'S'
#define GOAL	'G'
#define WAY		' '
#define WALL	'#'
#define MARKED	'+'

enum DIRECTION
{
	NORTH,
	SOUTH,
	EAST,
	WEST
};

enum RESULT
{
	FAIL,
	SUCCEED
};

typedef struct Position
{
	int X;
	int Y;
} Position;

typedef struct MazeInfo
{
	size_t ColumnSize;
	size_t RowSize;

	char** Data;
} MazeInfo;

int Solve( MazeInfo* maze );
int MoveTo( MazeInfo* maze, Position* current );
int GetNextStep( MazeInfo* maze, Position* current, int direction, Position* next );
int GetMaze( char* filePath, MazeInfo* maze );
