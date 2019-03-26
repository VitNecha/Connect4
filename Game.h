#pragma once
#include <iostream>
#include <string>
#include "Board.h"
class Game
{
private:
	Board* b = NULL;
public:
	Game();//DEFAULT CONTRUCTOR
	Game(int,int);//PRE-SET CONSTRUCTOR
	void Play();//PLAY FUNCTION
	friend void WinPrint(char);//A SPECIAL PRINT FOR THE GAME (ADDITIONAL FUNCTION)
	friend void TurnPrint(char);//A SPECIAL PRINT FOR THE GAME (ADDITIONAL FUNCTION)
	~Game();
};

