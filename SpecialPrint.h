//SPECIAL PRINT FUNCTIONS FOR "Game.h"//
#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <Windows.h>
//SPECIAL PRINT FOR WINNER//
void WinPrint(char p) {
	string line;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << endl << endl;
	if (p == 'R') {
		ifstream myfile("rwon.txt");
		SetConsoleTextAttribute(hConsole, 12);
		if (myfile.is_open())
		{
			while (getline(myfile, line)) cout << line << '\n';
			myfile.close();
		}
		else cout << endl << "RED WON!!!" << endl;
	}
	else if (p == 'B') {
		ifstream myfile("bwon.txt");
		SetConsoleTextAttribute(hConsole, 9);
		if (myfile.is_open())
		{
			while (getline(myfile, line)) cout << line << '\n';
			myfile.close();
		}
		else cout << endl << "BULE WON!!!" << endl;
	}
	SetConsoleTextAttribute(hConsole, 7);
	cout << endl << endl;
}
//SPECIAL PRINT FOR EACH TURN//
void TurnPrint(char p) {
	string line;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << endl << endl;
	if (p == 'R') {
		ifstream myfile("rturn.txt");
		SetConsoleTextAttribute(hConsole, 12);
		if (myfile.is_open())
		{
			while (getline(myfile, line)) cout << line << '\n';
			myfile.close();
		}
		else cout << endl << "RED TURN! ";
	}
	else if (p == 'B') {
		ifstream myfile("bturn.txt");
		SetConsoleTextAttribute(hConsole, 9);
		if (myfile.is_open())
		{
			while (getline(myfile, line)) cout << line << '\n';
			myfile.close();
		}
		else cout << endl << "BULE TURN! ";
	}
	cout << endl << "Enter the collumn :";
	SetConsoleTextAttribute(hConsole, 7);
}
