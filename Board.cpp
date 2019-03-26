#pragma once
#include "Board.h"
#include "HelpFunctions.h"
#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;
Board::Board():row(6),col(7){
	int i, j;
	mat = new char*[row];
	for (i = 0; i < row; i++) {
		mat[i] = new char[col];
		for (j = 0; j < col; j++)
			mat[i][j] = ' ';
	}
}
Board::Board(int row, int col) {
	int i, j;
	if (row >= 6 && col >= 7) {
		this->row = row;
		this->col = col;
	}
	else {
		cout << "Illegal board size input! (Minimum 6X7). Default size setted" << endl;
		this->row = 6;
		this->col = 7;
	}
		mat = new char*[this->row];
		for (i = 0; i < this->row; i++) {
			mat[i] = new char[this->col];
			for (j = 0; j < this->col; j++) {
				mat[i][j] = ' ';
			}
		}
	}
void Board::Print() {
	int i, j, k;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	for (i = 1; i <= col; i++) {
		cout << "|";
		if (i < 10) cout << " ";
		cout << i << " ";
	}
	cout << "|" << endl;
	for (i = 0; i < row; i++) {
		for (k = 0; k < col; k++) cout << "____";
		cout << endl;
		for (j = 0; j < col; j++) {
				cout << "|";
				if (mat[i][j] == ' ') cout << "   ";
				if (mat[i][j] == 'R') {
					SetConsoleTextAttribute(hConsole, 12);
					cout << " " << (char)254 << " ";
				}
				if (mat[i][j] == 'B') {
					SetConsoleTextAttribute(hConsole, 9);
					cout << " " << (char)254 << " ";
				}
				SetConsoleTextAttribute(hConsole, 7);
		}
		cout << "|" << endl;
	}
	for (k = 0; k < col; k++) cout << "____";
	cout << endl;
}
int Board::PlacePlayer(int colN, char p) {
	int i = row - 1;
	while (colN > col || mat[0][colN - 1] != ' ') {
		cout << "The columns is either full or does not exist! Please enter the column again:" << endl;//INPUT CHECK
		cin >> colN;
	}
	colN--;
	while (i >= 0) {
		if (mat[i][colN] != ' ') i--;
		else {
				mat[i][colN] = p;
				i = -1;
			}
		}
	return colN + 1;
	}	
bool Board::Winner(int rowN, int colN, char p) {
	return (CheckRow(rowN,p,mat,col) || CheckCol(colN,p,mat,row) || CheckDiagonal(rowN,colN,p,mat,row,col));
}
int Board::GetHigh(int c) {
	int i;
	for (i = row - 1; i >= 0; i--) if (mat[i][c - 1] == ' ') return i + 1;
		return 0;
}
Board::~Board(){
	delete[] mat;
	mat = NULL;
}
