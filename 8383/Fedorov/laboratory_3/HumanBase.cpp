#include "HumanBase.h"
#include "globalconst.h"
#include "HumanFactory.h"


HumanBase::HumanBase(GameField* field, int x, int y, Event::Relation relation)
 : Base(HUMAN_BASE_HP, HUMAN_BASE_LIMIT)
 {
  race = Event::HUMANITY;
  character = HUMAN_BASE_VIEW;
  factory_ = new HumanFactory;
  setPosition(field, x, y);
 }

HumanBase::~HumanBase(){
    if (factory_)
        delete factory_;
}
