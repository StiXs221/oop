#include "UnitFa�tory.h"
#include "Shooters.h"
#include "Infantary.h"
#include "Mechanisms.h"

int UnitFa�tory::id = -1;

IUnit* UnitFa�tory::createUnit(Units unitType)
{
	id++;
	IUnit* createdUnit = nullptr;
	switch (unitType)
	{
	case Units::ARCHER:
		createdUnit = new Archer(id);
		break;
	case Units::CROSSBOWMAN:
		createdUnit = new Crossbowman(id);
		break;
	case Units::SWORDSMAN:
		createdUnit = new Swordsman(id);
		break;
	case Units::SPEARMAN:
		createdUnit = new Spearman(id);
		break;
	case Units::BALLISTA:
		createdUnit = new Ballista(id);
		break;
	case Units::CATAPULT:
		createdUnit = new Catapult(id);
		break;
	}
	return createdUnit;
}
