#pragma once
#include "Game.h"
#include "Board.h"
#include <string>
#include "SpecialPrint.h"
using namespace std;
Game::Game(){ b = new Board; }
Game::Game(int x, int y) { b = new Board(x, y); }
void Game::Play() {
	int c, i;
	b->Print();
	for (i = 0; i < b->GetRows() * b->GetColumns(); i++) {
		if (i % 2 == 0) {
			TurnPrint('R');
			cin >> c;
			c = b->PlacePlayer(c,'R');
			b->Print();
			if (b->Winner(b->GetHigh(c), c, 'R') == true) {
				WinPrint('R');//SPECIAL WINNER PRINT
				break;
			}
		}
		else {
			TurnPrint('B');
			cin >> c;
			c = b->PlacePlayer(c,'B');
			b->Print();
			if (b->Winner(b->GetHigh(c), c, 'B') == true) {
				WinPrint('B');//SPECIAL WINNER PRINT
				break;
			}
		}
	}
	if (i == b->GetRows() * b->GetColumns()) cout << endl << "ITS A TIE!!!!!" << endl;
}
Game::~Game(){
	delete b;
}