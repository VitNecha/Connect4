#pragma once
#include <iostream>
using namespace std;
class Board {
private:
	int col, row; 
	char** mat = NULL;
public:
	Board();//DEFAULT CONSTRUCTOR
	Board(int row, int col);//PRE-SET CONSTRUCTOR
	void Print();//PRINT
	int GetColumns() { return col; };//NUMBER OF COLUMNS EXTRACTION
	int GetRows() { return row; };//NUMBER OF ROWS EXTRACTION
	int PlacePlayer(int colN, char p);//A PLAYER PLACEMENT METHOD
	bool Winner(int rowN, int colN, char p);//WINNER CHECK METHOD
	friend bool CheckRow(int rowN, char p, char** m, int c);//ADDITIONAL HELP FUNCTION (FOR WINNER) - ROW CHECK
	friend bool CheckCol(int colN, char p, char** m, int r);//ADDITIONAL HELP FUNCTION (FOR WINNER) - COLUMN CHECK
	friend bool CheckDiagonal(int rowN, int colN, char p, char** m, int r, int c);//ADDITIONAL HELP FUNCTION (FOR WINNER) - DIAGONAL CHECK
	int GetHigh(int c);//COLUMN'S "HEIGHT" EXTRACTION
	~Board();
};