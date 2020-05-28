//#pragma once
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <iomanip>
//#include "Warrior.h"
//#include "Orcs.h"
//#include "Men.h"
//#include "Elfs.h"
#include "Field.h"
#include "Iterator.h"
#include "Base.h"
//#include "Landscape.h"
//#include "NeutralObject.h"

using namespace std;

class Game {
public:
	Game();
	~Game() = default;
	int scan(int& numOfOrcs, int& numOfMens, int& numOfElfs, int& G);      //���������� ���������� ������ � ������� ����
	void unitMove(Field& f, string character);       //������� � ���� f ���� character
	bool addUnit(Field& f);
	void delUnit(Field& f);
};

#endif