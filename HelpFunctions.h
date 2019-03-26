//ADDITIONAL FUNCTIONS FOR "Board.h" METHODS//
//EACH FUNCTION CHECKS EITHER ROWS, COLUMNS OR DIAGONALS FOR STREAK OF 4//
#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;
bool CheckRow(int rowN, char p, char** m, int c) {
	int i, count = 0;
	for (i = 0; i < c; i++) {
		if (m[rowN][i] == p) {
			count++;
			if (count == 4) return true;
		}
		else count = 0;
	}
	return false;
}
bool CheckCol(int colN, char p, char** m, int r) {
	int i, count = 0;
	for (i = r - 1; i >= 0; i--) {
		if (m[i][colN - 1] == p) count++;
		else count = 0;
		if (count == 4) return true;
		}
	return false;
}
bool CheckDiagonal(int rowN, int colN, char p, char** m, int r, int c) {
	int i = 0, j = 0, count = 0;
	colN--;
	if (rowN > 2 && colN > 2) {
		i = rowN - 3;
		j = colN - 3;
	}
	else { 
		if (rowN < colN) j = colN - rowN;
		else if (rowN > colN) i = rowN - colN;
	}
	while (i < r && j < c) {
		if (m[i][j] == p) count++;
		else count = 0;
		if (count == 4) return true;
		i++;
		j++;
	}
	count = 0;
	if (rowN + 3 >= r) i = r - 1;
	else i = rowN + 3;
	if (colN > 2) j = colN - 3;
	else j = 0;
	while (i >= 0 && j < c) {
		if (m[i][j] == p) count++;
		else count = 0;
		if (count == 4) return true;
		i--;
		j++;
	}
	return false;
}
