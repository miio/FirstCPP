//
//  Player.cpp
//  FirstCPP
//
//  Created by miio mitani on 2013/04/20.
//  Copyright (c) 2013年 miio mitani. All rights reserved.
//

#include "Player.h"

Player::Player() {
    _hpMax = 200;
    _hp = _hpMax;
    _attack = 30;
    _defence = 20;
    _speed = 15;
}

void Player::selectAttack() {
    if (_dist(_gen) >= 5) {
        _isRangeAttack = true;
    } else {
        _isRangeAttack = false;
    }
}

bool Player::isRangeAttack() {
    return _isRangeAttack;
}
