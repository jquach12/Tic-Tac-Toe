//
//  move.cpp
//  TicTacToeRevised
//
//  Created by Jonathan Quach on 1/7/17.
//  Copyright © 2017 QuachLabs. All rights reserved.
//

#include <stdio.h>
#include "Move.h"

Move::Move(){}

Move::Move(int score){
    m_scoreForMoving = score;
}
