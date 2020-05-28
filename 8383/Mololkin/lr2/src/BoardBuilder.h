#pragma once
#include "GameBoard.h"
#include "IUnit.h"
#include "UnitFa�tory.h"
#include "Base.h"

class BoardBuilder
{
public:
	static GameBoard* createBoard();
	static GameBoard* createBoard(int length, int width);
	static void printBoard(GameBoard* board);
	static void showExamples();
};

