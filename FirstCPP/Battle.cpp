//
//  Battle.cpp
//  FirstCPP
//
//  Created by miio mitani on 2013/04/20.
//  Copyright (c) 2013年 miio mitani. All rights reserved.
//

#include "Battle.h"
#include <boost/shared_ptr.hpp>
#include <boost/random.hpp>
#include <boost/shared_array.hpp>
#include <boost/foreach.hpp> 

Battle::Battle(boost::shared_ptr<Player> player){
    boost::random::mt19937 gen(static_cast<unsigned int>(time(0)));
    boost::random::uniform_int_distribution<> dist(1,9);
    _gen = gen;
    _dist = dist;
    _player = player;
}

bool Battle::encount(){

    if (_dist(_gen) > 5 and false == _player->isDie()) {
        for (int i=0;i < _dist(_gen); i++) {
            _enemies.push_back(boost::shared_ptr<Enemy>(new Enemy()));
        }
        return true;
    }
    return false;
}

void Battle::execute(){
    bool isTurnPlayer = false;
    while(1) {
        if (isTurnPlayer) {
            this->playerTurn();
             // 次のターンへ
            isTurnPlayer = false;
        } else {
            this->enemyTurn();
            // 次のターンへ
            isTurnPlayer = true;
        }
    
        // 自分が死ぬか敵がいなくなったら終わり
         if (_player->isDie() or _enemies.size() <= 0) {
            break;
         }
    }
}

void Battle::playerTurn() {
    // 攻撃する
    _player->selectAttack();
    if (_player->isRangeAttack()) {
        // 範囲攻撃なら全員に攻撃
        for(std::vector<boost::shared_ptr<Enemy>>::iterator it=_enemies.begin(); it!=_enemies.end(); ) {
            this->attackToEnemy(it);
        }
    } else {
        // 通常攻撃なら先頭要素に攻撃
        this->attackToEnemy(_enemies.begin());
    }

}

void Battle::attackToEnemy(std::vector<boost::shared_ptr<Enemy>>::iterator it) {
    boost::shared_ptr<Enemy> enemy = *it;
    enemy->getDamage(_player->attack());
    if (enemy->isDie()) {
        _enemies.erase(it);
        std::cout << "敵を倒した 敵の残り数" << _enemies.size() << "\n";
    } else {
        std::cout << enemy->getHp() << " HP 敵の体力が残っている\n";
    }
}

void Battle::enemyTurn() {
    // 敵配列を回して攻撃判定
    BOOST_FOREACH( boost::shared_ptr<Enemy> enemy, _enemies) {
        _player->getDamage(enemy->attack());
        if (_player->isDie()) {
        std::cout << "敵の攻撃によって倒されてしまった...! \n";
            break;
        } else {
        std::cout << "敵の攻撃 プレーヤの残HP :" << _player->getHp() << "\n";
        }
    }
    
}
