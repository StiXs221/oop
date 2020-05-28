//#pragma once
#ifndef LANDSCAPE_H
#define LANDSCAPE_H

//#include "Field.h"
#include "Warrior.h"

using namespace std;

enum Landscape_ID { Forest_ID = 0, BurningEarth_ID, UnknownLand_ID };

class Landscape {
public:
	Landscape() = default;
	virtual ~Landscape() = default;
	virtual string getLandscapeType() = 0;
	virtual string effectOfLndscp(Warrior w) = 0;
	virtual bool canWalk2timesPerTurn(Warrior w) = 0;
	Landscape* create(Landscape_ID id);     //��������� �����
};

class Forest : public Landscape {      //� ���� ����� ������ �� 2� ���������� ������ �� ���
public:
	string getLandscapeType();
	string effectOfLndscp(Warrior w);
	bool canWalk2timesPerTurn(Warrior w);
};

class BurningEarth : public Landscape {  //����������� �����. ����� ������ 2 ���� �� 1 ���
public:
	string getLandscapeType();
	string effectOfLndscp(Warrior w);
	bool canWalk2timesPerTurn(Warrior w);
};

class UnknownLand : public Landscape {  //����������� �����. ������������ ����� ����� (���������� ����� 0)
public:
	string getLandscapeType();
	string effectOfLndscp(Warrior w);
	bool canWalk2timesPerTurn(Warrior w);
};

#endif