#include "UnitFa�tory.h"
#include "Shooters.h"
#include "Infantary.h"
#include "Mechanisms.h"

int UnitFa�tory::id = -1;

IUnit* UnitFa�tory::createUnit(Units unitType, int team)
{
	id++;
	IUnit* createdUnit = nullptr;
	switch (unitType)
	{
	case Units::ARCHER:
		createdUnit = new Archer(id, team);
		break;
	case Units::CROSSBOWMAN:
		createdUnit = new Crossbowman(id, team);
		break;
	case Units::SWORDSMAN:
		createdUnit = new Swordsman(id, team);
		break;
	case Units::SPEARMAN:
		createdUnit = new Spearman(id, team);
		break;
	case Units::BALLISTA:
		createdUnit = new Ballista(id, team);
		break;
	default:
		createdUnit = new Catapult(id, team);
		break;
	}
	return createdUnit;
}
