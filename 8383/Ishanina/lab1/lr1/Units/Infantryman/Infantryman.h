//
// Created by Mila on 23.02.2020.
//

#ifndef UNTITLED_INFANTRYMAN_H
#define UNTITLED_INFANTRYMAN_H


#include "../Unit.h"

class Infantryman: public Unit{
protected:
    void whatYouName() override = 0;
    ObjectInterface* copy() override = 0;


};


#endif //UNTITLED_INFANTRYMAN_H
