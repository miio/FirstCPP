//
//  GameObject.h
//  FirstCPP
//
//  Created by miio mitani on 2013/04/21.
//  Copyright (c) 2013年 miio mitani. All rights reserved.
//

#ifndef __FirstCPP__GameObject__
#define __FirstCPP__GameObject__

#include <iostream>
#include <Boost/random.hpp>

class GameObject {
public:
    GameObject();
    bool isActive();
    bool isDie();
    int attack();
    int getHp();
    void getDamage(int damage);
protected:
    boost::random::mt19937 _gen;
    boost::random::uniform_int_distribution<> _dist;
    bool _isActive = true;
    bool _isDie = false;
    int _hp;
    int _attack;
    int _defence;
    int _speed;
    int _hpMax;
    int _last_damage;
};
#endif /* defined(__FirstCPP__GameObject__) */
