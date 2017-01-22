//
//  main.cpp
//  TicTacToeRevised
//
//  Created by Jonathan Quach on 12/31/16.
//  Copyright © 2016 QuachLabs. All rights reserved.
//

#include "TTTBoard.h"
#include "Player.h"
#include "Game.h"

#include <iostream>
#include <vector>

struct AImove;
using namespace std;
int main(int argc, const char * argv[]) {
    srand((int)time(0));
    Game g;
   
    
   // g.playVersusHardAI();
    
    g.menu();
    //g.playerVSplayer();
    
   // g.playVersusEasyAI();
   // g.playVersusMediumAI();
    cout<<"Hello world"<<endl;
    return 0;
}
