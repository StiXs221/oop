#include "ShrineStrategy.h"
void ShrineStrategy::applyEffect(Unit*& target) {
	target->setHp(target->getHp() + 5);
}

void ShrineStrategy::removeEffect(Unit*& target) {
	//� ��� ���
}
void ShrineStrategy::applyEffectForTimur(Unit& target) {
	target.setHp(target.getHp() + 5);
}

void ShrineStrategy::removeEffectForTimur(Unit& target) {

}