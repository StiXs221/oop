//
//  Bush.hpp
//  Game_2
//
//  Created by Владислав  Степанов on 27.03.2020.
//  Copyright © 2020 Владислав  Степанов. All rights reserved.
//

#ifndef Bush_hpp
#define Bush_hpp

#include "Landscape.hpp"
class Unit;

class Bush: public Landscape{
    
    char getName () override;
};

#endif /* Bush_hpp */
