/*
WORK NUMBER 2 - TASK 2
ID: 324359926
NAME: VITALY NECHAYUK
CAMPUS: BEER SHEVA
*/
/* 
---TO ENABLE THE SPECIAL PRINTING PLEASE ADD ALL THE .TXT FILES (rwon.txt, bwon.txt,...) TO THE SOLUTION FOLDER AFTER THE FIRST BUILD ---
---OTHERWISE, THE SOLUTION WILL USE DEFAULT PRINTING---
*/
#pragma once
#include <iostream>
#include "Game.h"
using namespace std;
int main()
{
	int n1, n2;
	cout << "Enter the size of the board (6X7 Minimum)" << endl << "Number of rows:";
	cin >> n1;
	cout << "Number of columns:";
	cin >> n2;
	Game g(n1, n2);
	cout << "Let's play!" << endl;
	g.Play();
	return 0;
}
