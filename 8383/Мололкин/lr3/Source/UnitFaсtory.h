#pragma once
#include "IUnit.h"
#include "Infantary.h"
#include "Mechanisms.h"
#include "Shooters.h"

class Archer;
class Crossbowman;
class Ballista;
class Catapult;
class Spearman;
class Swordsman;

class UnitFa�tory
{
private:
	static int id;
public:
	UnitFa�tory() = default;
	static IUnit* createUnit(Units unitType, int team);
};
