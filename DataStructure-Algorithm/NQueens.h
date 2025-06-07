#pragma once

#include <stdio.h>
#include <stdlib.h>

void FindSolutionForQueen( int columns[], int row, int numberOfQueens, int* solutionCount );
int IsThreatened( int columns[], int newRow );
void PrintSolution( int columns[], int numberOfQueens );