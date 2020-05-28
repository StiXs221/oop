#include "StrongZomby.h"



StrongZomby::StrongZomby()
{
	attackBehavior = std::shared_ptr<AttackBehavior>(new StrongNearAttack());
	weapon = std::shared_ptr<Weapon>(new StrongArm());
	type = UnitType::STRONG_ZOMBY;
}

StrongZomby::StrongZomby(int hp, int maxHP, int ownArmor, int ownDamage, bool visability, int level, int landDamage, int landDefence, std::shared_ptr<std::shared_ptr<ObserverInterface>[]> observers, int observerSize, int observerCount, int coordX, int coordY, std::shared_ptr<Mediator> mediator, size_t lastStep)
:FatZomby(hp, maxHP, ownArmor, ownDamage, visability, level, landDamage, landDefence, observers, observerSize, observerCount, coordX, coordY, mediator, lastStep){
	attackBehavior = std::shared_ptr<AttackBehavior>(new StrongNearAttack());
	weapon = std::shared_ptr<Weapon>(new StrongArm());
	type = UnitType::STRONG_ZOMBY;
}

StrongZomby::StrongZomby(int x, int y, int level):FatZomby(x, y, level) {
	attackBehavior = std::shared_ptr<AttackBehavior>(new StrongNearAttack());
	weapon = std::shared_ptr<Weapon>(new StrongArm());
	type = UnitType::STRONG_ZOMBY;
}

StrongZomby::StrongZomby(const StrongZomby & other):FatZomby(other)
{
}

StrongZomby::StrongZomby(StrongZomby && other): FatZomby(other)
{
}

StrongZomby& StrongZomby::operator=(const StrongZomby & other)
{
	this->hp = other.hp;
	this->maxHP = other.maxHP;
	this->ownArmor = other.ownArmor;
	this->ownDamage = other.ownDamage;
	this->visability = other.visability;
	this->level = other.level;
	this->landDamage = other.landDamage;
	this->landDefence = other.landDefence;

	this->weapon = std::shared_ptr<Weapon>(new Weapon(*other.weapon));
	this->armor = std::shared_ptr<Armor>(new Armor(*other.armor));
	this->moveBehavior = std::shared_ptr<MoveBehavior>(new MoveBehavior(*other.moveBehavior));
	this->attackBehavior = std::shared_ptr<AttackBehavior>(new AttackBehavior(*other.attackBehavior));

	this->observerSize = 0;
	this->observerCount = 0;
	this->coordX = other.coordX;
	this->coordY = other.coordY;

	return *this;
}

StrongZomby & StrongZomby::operator=(StrongZomby && other)
{
	if (&other == this) {
		return *this;
	}

	this->hp = other.hp;
	this->maxHP = other.maxHP;
	this->ownArmor = other.ownArmor;
	this->ownDamage = other.ownDamage;
	this->visability = other.visability;
	this->level = other.level;
	this->landDamage = other.landDamage;
	this->landDefence = other.landDefence;

	this->weapon = std::shared_ptr<Weapon>(new Weapon(*other.weapon));
	this->armor = std::shared_ptr<Armor>(new Armor(*other.armor));
	this->moveBehavior = std::shared_ptr<MoveBehavior>(new MoveBehavior(*other.moveBehavior));
	this->attackBehavior = std::shared_ptr<AttackBehavior>(new AttackBehavior(*other.attackBehavior));

	this->observerSize = 0;
	this->observerCount = 0;
	this->coordX = other.coordX;
	this->coordY = other.coordY;

	return *this;
}


StrongZomby::~StrongZomby() {

}

char StrongZomby::getChar()
{
	return 'O';
}


std::string StrongZomby::getPath() {
    return "strongZomby.png";
}
