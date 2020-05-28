//
// Created by max on 31.03.20.
//

#ifndef OOP_UNITACTION_H
#define OOP_UNITACTION_H

#include "Field.h"
#include "Interaction.h"

class UnitAction {
public:
    UnitAction()
    {

    }
    ~UnitAction()
    {

    }
    void run(bool &check,Field* f);
    void showCharacteristics(Field* f,Unit* curr_unit);
    void attack(Field* f,Unit* curr_unit,bool &check,Interaction* inter);
    void repair(Field* f,Base* base, bool &check, Interaction* inter);
    void services(Field* f,Unit* unit, NeutralObject* object,Interaction* inter, bool &check);
};


#endif //OOP_UNITACTION_H
