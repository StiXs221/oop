//
// Created by Mila on 23.02.2020.
//

#ifndef UNTITLED_MAGICIAN_H
#define UNTITLED_MAGICIAN_H


#include "Artillerist.h"

class Magician: public Artillerist {

public:
    Magician();

    ObjectInterface* copy() override;
    void whatYouName() override;

};


#endif //UNTITLED_MAGICIAN_H
