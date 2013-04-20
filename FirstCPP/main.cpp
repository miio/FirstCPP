//
//  main.cpp
//  FirstCPP
//
//  Created by miio mitani on 2013/04/20.
//  Copyright (c) 2013年 miio mitani. All rights reserved.
//

#include <iostream>
#include <boost/shared_ptr.hpp>
#include "Battle.h"
#include "Player.h"

int main(int argc, const char * argv[])
{

    boost::shared_ptr<Player> player(new Player);
    boost::shared_ptr<Battle> battle(new Battle(player));
        
    for (int i=0; i < 10; i++) {
        bool isEncount = battle->encount();
        if (isEncount) {
            std::cout << "戦闘開始\n";
            battle->execute();
        } else {
            std::cout << "敵はいなかった\n";
        }
    }

    
    
    return 0;
}

