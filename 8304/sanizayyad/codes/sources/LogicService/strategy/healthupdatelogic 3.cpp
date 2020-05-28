#include "healthupdatelogic.hpp"

void HealthUpdateLogic::updateUnit(std::shared_ptr<Unit> unit) const
{
    unit->makeDamage(-100);
    //supposed to be addtion
}


std::shared_ptr<StrategyPattern> HealthUpdateLogic::clone() const
{
    return std::make_shared<HealthUpdateLogic>();
}

