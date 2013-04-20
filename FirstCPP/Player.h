//
//  Player.h
//  FirstCPP
//
//  Created by miio mitani on 2013/04/20.
//  Copyright (c) 2013年 miio mitani. All rights reserved.
//

#ifndef __FirstCPP__Player__
#define __FirstCPP__Player__

#include <iostream>
#include "GameObject.h"
#include <boost/random.hpp>

class Player : public GameObject {
public:
    Player();
    void selectAttack();
    bool isRangeAttack();
private:
    bool _isRangeAttack;

};
#endif /* defined(__FirstCPP__Player__) */
