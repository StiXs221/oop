#include "SpitZomby.h"



SpitZomby::SpitZomby(int hp, int maxHP, int ownArmor, int ownDamage, bool visability, int level, int landDamage, int landDefence, std::shared_ptr<std::shared_ptr<ObserverInterface>[]> observers, int observerSize, int observerCount, int coordX, int coordY, std::shared_ptr<Mediator> mediator, size_t lastStep)
:ZombyUnit(hp, maxHP, ownArmor, ownDamage, visability, level, landDamage, landDefence, observers, observerSize, observerCount, coordX, coordY, mediator, lastStep){
	moveBehavior = std::shared_ptr<MoveBehavior>(new CommonMove());
	armor = std::shared_ptr <Armor>(new NoArmor());
}

SpitZomby::SpitZomby()
{
	hp = 100;
	maxHP = 100;
	moveBehavior = std::shared_ptr<MoveBehavior>(new CommonMove());
	armor = std::shared_ptr <Armor>(new NoArmor());
}

SpitZomby::SpitZomby(int x, int y, int level):ZombyUnit(x, y, level)
{
	hp = 100;
	maxHP = 100;
	moveBehavior = std::shared_ptr<MoveBehavior>(new CommonMove());
	armor = std::shared_ptr<Armor>(new NoArmor());
}

SpitZomby::SpitZomby(const SpitZomby & other):ZombyUnit(other)
{
}

SpitZomby::SpitZomby(SpitZomby && other):ZombyUnit(other)
{
}

SpitZomby& SpitZomby::operator=(const SpitZomby & other)
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

SpitZomby & SpitZomby::operator=(SpitZomby && other)
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


SpitZomby::~SpitZomby()
{
}

char SpitZomby::getChar()
{
	return 'U';
}
