#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LCSTable
{
	int** Data;
} LCSTable;

int LCS( char* str1, char* str2, int x, int y, LCSTable* table );
void LCS_TraceBack( char* str1, char* str2, int x, int y, LCSTable* table, char* LCS );
void LCS_PrintTable( LCSTable* table, char* str1, char* str2, size_t length1, size_t length2 );