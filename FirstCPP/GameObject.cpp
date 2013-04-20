//
//  GameObject.cpp
//  FirstCPP
//
//  Created by miio mitani on 2013/04/21.
//  Copyright (c) 2013年 miio mitani. All rights reserved.
//

#include "GameObject.h"
GameObject::GameObject() {
    boost::random::mt19937 gen(static_cast<unsigned int>(time(0)));
    boost::random::uniform_int_distribution<> dist(1,9);
    _gen = gen;
    _dist = dist;
}
int GameObject::attack() {
    if (_hpMax/2 <= _hp) {
        return _attack;
    }
    return _attack * (_hpMax + 1 - _hp);
}

void GameObject::getDamage(int damage)
{
    int calc_damage = damage - (_defence) + _dist(_gen);
    if (calc_damage > 0) {
        _hp -= calc_damage;
    }
    
    // 死亡判定
    if (_hp <= 0) {
        _hp = 0;
        _isDie = true;
    }
}

int GameObject::getHp() {
    return _hp;
}

bool GameObject::isDie() {
    return _isDie;
}