#include "MazeSolver.h"

int Solve( MazeInfo* maze )
{
    if ( maze == NULL )
    {
        return FAIL;
    }

    int startFound = FAIL;
    int result = FAIL;
    Position start = { 0, 0 };

    for ( int i = 0; i < maze->RowSize; i++ )
    {
        for ( int j = 0; j < maze->ColumnSize; j++ )
        {
            if ( maze->Data[i][j] == START )
            {
                start.X = j;    // Column
				start.Y = i;    // Row
                startFound = SUCCEED;
                break;
            }
        }
    }

    // 시작 지점을 찾기 못한 경우 실패 처리한다.
	if ( startFound == FAIL )
	{
		printf( "Start position not found in the maze.\n" );
		return FAIL;
	}

    if ( MoveTo( maze, &start ) )
    {
        result = SUCCEED;
    }

	maze->Data[start.Y][start.X] = START;

    return result;
}

int MoveTo( MazeInfo* maze, Position* current )
{
    if ( maze == NULL || current == NULL )
    {
        return FAIL;
    }

    int dirs[] = { NORTH, SOUTH, EAST, WEST };
	Position next = { 0, 0 };

    if ( maze->Data[current->Y][current->X] == GOAL )
    {
        return SUCCEED;
    }

    maze->Data[current->Y][current->X] = MARKED;

    for ( int i = 0; i < 4; i++ )
    {
        // 다음 이동 가능한 방향을 확인하고, 이동 가능하면 이동한다.
        if ( GetNextStep( maze, current, dirs[i], &next ) == FAIL )
        {
            continue;
        }

        if ( MoveTo( maze, &next ) == SUCCEED )
        {
            return SUCCEED;
        }
    }

    // 모든 방향이 FAIL을 반환했으므로 이 위치는 해가 아니다.
	maze->Data[current->Y][current->X] = WAY;

    return FAIL;
}

int GetNextStep( MazeInfo* maze, Position* current, int direction, Position* next )
{
    if ( maze == NULL || current == NULL || next == NULL )
    {
        return FAIL;
    }

    switch ( direction )
    {
    case NORTH:
        next->X = current->X;
        next->Y = current->Y - 1;

        if ( next->Y == -1 )
        {
            return FAIL;
        }
        break;
    case SOUTH:
        next->X = current->X;
        next->Y = current->Y + 1;

        if ( next->Y == maze->RowSize )
        {
            return FAIL;
        }
        break;
    case EAST:
        next->X = current->X + 1;
        next->Y = current->Y;

        if ( next->X == maze->ColumnSize )
        {
            return FAIL;
        }
        break;
    case WEST:
        next->X = current->X - 1;
        next->Y = current->Y;

        if ( next->X == -1 )
        {
            return FAIL;
        }
        break;
    }

    if ( maze->Data[next->Y][next->X] == WALL )
    {
        return FAIL;
    }

    if ( maze->Data[next->Y][next->X] == MARKED )
    {
        return FAIL;
    }

    return SUCCEED;
}

int GetMaze( char* filePath, MazeInfo* maze )
{
    if ( filePath == NULL || maze == NULL )
    {
        return FAIL;
    }

    size_t rowSize = 0;
    size_t columnSize = INIT_VALUE;

    FILE* fp = fopen(filePath, "r");
    if ( fp == NULL )
    {
        printf( "Cannot open file:%s\n", filePath );
        return FAIL;
    }

    char buffer[MAX_BUFFER] = { "" };

    while ( fgets( buffer, MAX_BUFFER, fp ) != NULL )
    {
        rowSize++;

        if ( columnSize == INIT_VALUE )
        {
            columnSize = strlen( buffer ) - 1;
        }
        else if ( columnSize != strlen( buffer ) - 1 )
        {
            printf( "Maze data in file:%s is not valid.\n", filePath );
            fclose( fp );
            return FAIL;
        }
    }

    maze->RowSize = rowSize;
    maze->ColumnSize = columnSize;
    maze->Data = ( char** ) malloc( rowSize * sizeof( char* ) );

    for ( int i = 0; i < rowSize; i++ )
    {
        maze->Data[i] = ( char* ) malloc( columnSize * sizeof( char ) );
    }

    rewind( fp );

    for ( int i = 0; i < rowSize; i++ )
    {
        fgets( buffer, MAX_BUFFER, fp );

        for ( int j = 0; j < columnSize; j++ )
        {
            maze->Data[i][j] = buffer[j];
        }
    }

    fclose( fp );

    return SUCCEED;
}
