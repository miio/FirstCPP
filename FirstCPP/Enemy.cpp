//
//  Enemy.cpp
//  FirstCPP
//
//  Created by miio mitani on 2013/04/20.
//  Copyright (c) 2013年 miio mitani. All rights reserved.
//

#include "Enemy.h"

Enemy::Enemy() {
    _hpMax = 60;
    _hp = _hpMax;
    _attack = 20;
    _defence = 10;
    _speed = 5;
}