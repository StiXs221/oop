#include "stdafx.h"
#include "GameObjects.h"
#include <math.h>
#include <iostream>
/*
######################################
����� � ����� ������� ������ Object
######################################
*/

Object::Object(){}

Object::Object(const Object& copy) {
	X_CORD = copy.X_CORD;
	Y_CORD = copy.Y_CORD;
	ObjectFactions = copy.ObjectFactions;
	Type = copy.Type;
}

Object::~Object() {}

Object& Object::operator=(const Object& copy) {
	if (&copy == this) {
		return *this;
	}

	X_CORD = copy.X_CORD;
	Y_CORD = copy.Y_CORD;
	ObjectFactions = copy.ObjectFactions;
	Type = copy.Type;

	return *this;
}


int Object::getX() {
	return X_CORD;
}
int Object::getY() {
	return Y_CORD;
}

Factions Object::getFaction() {
	return ObjectFactions;
}
ObjectTypes Object::getType() {
	return Type;
}

void Object::setX(int x) {

	if (x >= 0) {

		X_CORD = x;

	}
	else {
		/*������� ������*/
	}
}
void Object::setY(int y) {

	if (y >= 0) {

		Y_CORD = y;

	}
	else {
		/*������� ������*/
	}
}

void Object::setFactions(Factions f) {
	ObjectFactions = f;
}

void Object::setType(ObjectTypes t) {
	Type = t;
}

/*
######################################
����� � ����� ������� ������ BaseUnite
######################################
*/


BaseUnit::BaseUnit(int x, int y, Factions f){

	X_CORD = x;
	Y_CORD = y;
	ObjectFactions = f;
	Type = ObjectTypes::Unit;
	MaxHp = 1;
	Hp = 1;
	Damage = 0;
	AttackDistance = 0;
	MoveDistance = 0;
	Armor = 0;
	Job = Jobs::Standing;
}

BaseUnit::BaseUnit(const BaseUnit& copy) {
	X_CORD = copy.X_CORD;
	Y_CORD = copy.Y_CORD;
	ObjectFactions = copy.ObjectFactions;
	MaxHp = copy.MaxHp;
	Hp = copy.Hp;
	Damage = copy.Damage;
	AttackDistance = copy.AttackDistance;
	MoveDistance = copy.MoveDistance;
	Armor = copy.Armor;
	Job = copy.Job;
	Type = copy.Type;
}

BaseUnit::BaseUnit(){}

BaseUnit::~BaseUnit(){}

BaseUnit& BaseUnit::operator=(const BaseUnit& copy) {
	if (&copy == this) {
		return *this;
	}

	X_CORD = copy.X_CORD;
	Y_CORD = copy.Y_CORD;
	ObjectFactions = copy.ObjectFactions;
	MaxHp = copy.MaxHp;
	Hp = copy.Hp;
	Damage = copy.Damage;
	AttackDistance = copy.AttackDistance;
	MoveDistance = copy.MoveDistance;
	Armor = copy.Armor;
	Job = copy.Job;
	Type = copy.Type;

	return *this;
}

void BaseUnit::Move(int x, int y) {
	if (abs(x - this->getX()) <= this->MoveDistance &&
		abs(y - this->getY()) <= this->MoveDistance) {

		/*�� ������ ������� ������*/

		this->setX(x);

		/*�� ������ ������� ������*/

		this->setY(y);
	}
}

void BaseUnit::GetDamage(int damage) {

	int IncomingDamage = damage - Armor;

	if (IncomingDamage <= 0) {

		IncomingDamage = 0;

	}

	Hp -= IncomingDamage;
}

void BaseUnit::Attack(std::shared_ptr<BaseUnit> target) {
	if (target->getFaction() != getFaction() &&
		target->getType() != ObjectTypes::NonPlayableStructure) {

		if (abs(target->getX() - getX()) <= AttackDistance &&
			abs(target->getY() - getY()) <= AttackDistance) {

			target->GetDamage(Damage);

		}
		else {
			/*������� ������ "������� ������!"*/
		}

	}
	else {
		/*������� ������ "�� ������ ���� ��������?"*/
	}
}

void BaseUnit::printStatistic() {
	std::cout << X_CORD << " " << Y_CORD << " " << int(Type) << " " << int(ObjectFactions) <<" "<< Hp << "/" << MaxHp  << std::endl;
}

/*
###############################################
����� � ����� ������� �������� Cavalry � Knight
###############################################
*/

Cavalry::Cavalry(int x, int y, Factions f)
{
	X_CORD = x;
	Y_CORD = y;
	ObjectFactions = f;
	Type = ObjectTypes::Unit;
	MaxHp = 100;
	Hp = MaxHp;
	Damage = 30;
	AttackDistance = 1;
	MoveDistance = 5;
	Armor = 10;
	Job = Jobs::Standing;
}

Cavalry::Cavalry(const Cavalry& copy) {
	X_CORD = copy.X_CORD;
	Y_CORD = copy.Y_CORD;
	ObjectFactions = copy.ObjectFactions;
	MaxHp = copy.MaxHp;
	Hp = copy.Hp;
	Damage = copy.Damage;
	AttackDistance = copy.AttackDistance;
	MoveDistance = copy.MoveDistance;
	Armor = copy.Armor;
	Job = copy.Job;
	Type = copy.Type;
}

Cavalry::~Cavalry()
{

}

Cavalry& Cavalry::operator=(const Cavalry& copy) {
	if (&copy == this) {
		return *this;
	}

	X_CORD = copy.X_CORD;
	Y_CORD = copy.Y_CORD;
	ObjectFactions = copy.ObjectFactions;
	MaxHp = copy.MaxHp;
	Hp = copy.Hp;
	Damage = copy.Damage;
	AttackDistance = copy.AttackDistance;
	MoveDistance = copy.MoveDistance;
	Armor = copy.Armor;
	Job = copy.Job;
	Type = copy.Type;

	return *this;
}

Knight::Knight(int x, int y, Factions f)
{
	X_CORD = x;
	Y_CORD = y;
	ObjectFactions = f;
	ObjectTypes::Unit;
	MaxHp = 200;
	Hp = MaxHp;
	Damage = 50;
	AttackDistance = 1;
	MoveDistance = 5;
	Armor = 20;
	Job = Jobs::Standing;
}

Knight::Knight(const Knight& copy) {
	X_CORD = copy.X_CORD;
	Y_CORD = copy.Y_CORD;
	ObjectFactions = copy.ObjectFactions;
	MaxHp = copy.MaxHp;
	Hp = copy.Hp;
	Damage = copy.Damage;
	AttackDistance = copy.AttackDistance;
	MoveDistance = copy.MoveDistance;
	Armor = copy.Armor;
	Job = copy.Job;
	Type = copy.Type;
}

Knight::~Knight()
{

}

Knight& Knight::operator=(const Knight& copy) {
	if (&copy == this) {
		return *this;
	}

	X_CORD = copy.X_CORD;
	Y_CORD = copy.Y_CORD;
	ObjectFactions = copy.ObjectFactions;
	MaxHp = copy.MaxHp;
	Hp = copy.Hp;
	Damage = copy.Damage;
	AttackDistance = copy.AttackDistance;
	MoveDistance = copy.MoveDistance;
	Armor = copy.Armor;
	Job = copy.Job;
	Type = copy.Type;

	return *this;
}

/*
###############################################
����� � ����� ������� �������� Cavalry � Knight
###############################################
*/

Warrior::Warrior(int x, int y, Factions f)
{
	X_CORD = x;
	Y_CORD = y;
	ObjectFactions = f;
	ObjectTypes::Unit;
	MaxHp = 150;
	Hp = MaxHp;
	Damage = 30;
	AttackDistance = 1;
	MoveDistance = 1;
	Armor = 30;
	Job = Jobs::Standing;
}

Warrior::Warrior(const Warrior& copy) {
	X_CORD = copy.X_CORD;
	Y_CORD = copy.Y_CORD;
	ObjectFactions = copy.ObjectFactions;
	MaxHp = copy.MaxHp;
	Hp = copy.Hp;
	Damage = copy.Damage;
	AttackDistance = copy.AttackDistance;
	MoveDistance = copy.MoveDistance;
	Armor = copy.Armor;
	Job = copy.Job;
	Type = copy.Type;
}

Warrior::~Warrior()
{

}

Warrior& Warrior::operator=(const Warrior& copy) {
	if (&copy == this) {
		return *this;
	}

	X_CORD = copy.X_CORD;
	Y_CORD = copy.Y_CORD;
	ObjectFactions = copy.ObjectFactions;
	MaxHp = copy.MaxHp;
	Hp = copy.Hp;
	Damage = copy.Damage;
	AttackDistance = copy.AttackDistance;
	MoveDistance = copy.MoveDistance;
	Armor = copy.Armor;
	Job = copy.Job;
	Type = copy.Type;

	return *this;
}

Piker::Piker(int x, int y, Factions f)
{
	X_CORD = x;
	Y_CORD = y;
	ObjectFactions = f;
	ObjectTypes::Unit;
	MaxHp = 200;
	Hp = MaxHp;
	Damage = 40;
	AttackDistance = 1;
	MoveDistance = 1;
	Armor = 45;
	Job = Jobs::Standing;

}

Piker::Piker(const Piker& copy) {
	X_CORD = copy.X_CORD;
	Y_CORD = copy.Y_CORD;
	ObjectFactions = copy.ObjectFactions;
	MaxHp = copy.MaxHp;
	Hp = copy.Hp;
	Damage = copy.Damage;
	AttackDistance = copy.AttackDistance;
	MoveDistance = copy.MoveDistance;
	Armor = copy.Armor;
	Job = copy.Job;
	Type = copy.Type;

}

Piker::~Piker()
{

}

Piker& Piker::operator=(const Piker& copy) {
	if (&copy == this) {
		return *this;
	}

	X_CORD = copy.X_CORD;
	Y_CORD = copy.Y_CORD;
	ObjectFactions = copy.ObjectFactions;
	MaxHp = copy.MaxHp;
	Hp = copy.Hp;
	Damage = copy.Damage;
	AttackDistance = copy.AttackDistance;
	MoveDistance = copy.MoveDistance;
	Armor = copy.Armor;
	Job = copy.Job;
	Type = copy.Type;

	return *this;
}

/*
###############################################
����� � ����� ������� �������� Cavalry � Knight
###############################################
*/

Archer::Archer(int x, int y, Factions f)
{
	X_CORD = x;
	Y_CORD = y;
	ObjectFactions = f;
	ObjectTypes::Unit;
	MaxHp = 60;
	Hp = MaxHp;
	Damage = 40;
	AttackDistance = 6;
	MoveDistance = 2;
	Armor = 5;
	Job = Jobs::Standing;
}

Archer::Archer(const Archer& copy) {
	X_CORD = copy.X_CORD;
	Y_CORD = copy.Y_CORD;
	ObjectFactions = copy.ObjectFactions;
	MaxHp = copy.MaxHp;
	Hp = copy.Hp;
	Damage = copy.Damage;
	AttackDistance = copy.AttackDistance;
	MoveDistance = copy.MoveDistance;
	Armor = copy.Armor;
	Job = copy.Job;
	Type = copy.Type;

}

Archer::~Archer()
{

}

Archer& Archer::operator=(const Archer& copy) {
	if (&copy == this) {
		return *this;
	}

	X_CORD = copy.X_CORD;
	Y_CORD = copy.Y_CORD;
	ObjectFactions = copy.ObjectFactions;
	MaxHp = copy.MaxHp;
	Hp = copy.Hp;
	Damage = copy.Damage;
	AttackDistance = copy.AttackDistance;
	MoveDistance = copy.MoveDistance;
	Armor = copy.Armor;
	Job = copy.Job;
	Type = copy.Type;

	return *this;
}

Arbalester::Arbalester(int x, int y, Factions f)
{
	X_CORD = x;
	Y_CORD = y;
	ObjectFactions = f;
	ObjectTypes::Unit;
	MaxHp = 70;
	Hp = MaxHp;
	Damage = 70;
	AttackDistance = 5;
	MoveDistance = 2;
	Armor = 10;
	Job = Jobs::Standing;
}

Arbalester::Arbalester(const Arbalester& copy) {
	X_CORD = copy.X_CORD;
	Y_CORD = copy.Y_CORD;
	ObjectFactions = copy.ObjectFactions;
	MaxHp = copy.MaxHp;
	Hp = copy.Hp;
	Damage = copy.Damage;
	AttackDistance = copy.AttackDistance;
	MoveDistance = copy.MoveDistance;
	Armor = copy.Armor;
	Job = copy.Job;
	Type = copy.Type;

}

Arbalester::~Arbalester()
{

}

Arbalester& Arbalester::operator=(const Arbalester& copy) {
	if (&copy == this) {
		return *this;
	}

	X_CORD = copy.X_CORD;
	Y_CORD = copy.Y_CORD;
	ObjectFactions = copy.ObjectFactions;
	MaxHp = copy.MaxHp;
	Hp = copy.Hp;
	Damage = copy.Damage;
	AttackDistance = copy.AttackDistance;
	MoveDistance = copy.MoveDistance;
	Armor = copy.Armor;
	Job = copy.Job;
	Type = copy.Type;

	return *this;
}