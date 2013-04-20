//
//  Battle.h
//  FirstCPP
//
//  Created by miio mitani on 2013/04/20.
//  Copyright (c) 2013年 miio mitani. All rights reserved.
//

#ifndef __FirstCPP__Battle__
#define __FirstCPP__Battle__

#include <iostream>
#include "Enemy.h"
#include "Player.h"
#include <boost/random.hpp>
#include <boost/shared_array.hpp>

class Battle {
public:
    Battle(boost::shared_ptr<Player> player);
    bool encount();
    void execute();

private:
    void playerTurn();
    void attackToEnemy(std::vector<boost::shared_ptr<Enemy>>::iterator enemy);
    void enemyTurn();
    std::vector<boost::shared_ptr<Enemy>> _enemies;
    boost::shared_ptr<Player> _player;
    boost::random::mt19937 _gen;
    boost::random::uniform_int_distribution<> _dist;
};

#endif /* defined(__FirstCPP__Battle__) */
