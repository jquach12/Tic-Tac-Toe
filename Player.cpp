//
//  Player.cpp
//  TicTacToeRevised
//
//  Created by Jonathan Quach on 12/31/16.
//  Copyright © 2016 QuachLabs. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include "Player.h"
#include "TTTBoard.h"
using namespace std;

Player::Player()
    :m_score(0),m_isAI(false),m_human(0),m_computer(0)
{}
Player::Player(bool isAI)
:m_score(0),m_isAI(isAI),m_human(0),m_computer(0)
{
    
}

void Player::updateScore(int n){
    m_score+=n;
}
void Player::updateXorO(char c){
    XorO = c;
    if(m_isAI && c == 'X'){
        m_computer = X_VAL;
        m_human = O_VAL;
    }
    else if (m_isAI && c == 'O'){
        m_computer = O_VAL;
        m_human = X_VAL;
    }
   // cerr<<"updated player to have this char: "<<c<<endl;
}
int Player::getScore() const{
    return m_score;
}

void Player::updateIsCurrentTurn(bool someValue){
    m_isCurrentTurn = someValue;
}

bool Player::justWon(TTTBoard* tptr) const{
    return tptr->hasWon() && this->m_isCurrentTurn == true;
}


char Player::getXorO() const{
    return XorO;
}
void Player::move(TTTBoard* tptr, int squarePosition, char someXorO){
    tptr->updateBoard(someXorO, squarePosition, true);
}

/*
//UNDER CONSTRUCTION
int Player::pickOptimizedMove(TTTBoard* tptr, Player* opponent){
   
    
    if
    
    
    vector<int> listOfMoves(9,0);
    
    int result;
    
    for (int i=0;i<NUMBER_OF_SQUARES;i++){
        
        //occupy every spot temporarily
        if(tptr->accessSpotOnBoard(i)==' '){
            tptr->setAValueInBoard(this->XorO, i);
            if (tptr->isGameOver() && tptr->hasWon())
                listOfMoves[i] = 9999;
            else if (tptr->isGameOver() && tptr->hasWon()==false)
                listOfMoves[i] = 0;
        } //record if there's a tie or a win
        
        result = howMuchOpponentCanHurtMe(tptr,this, opponent);
        
        tptr->setAValueInBoard(' ', i);
        
    }
    
    int bestMove=0;
    for (int i=0;i<listOfMoves.size();i++)
        if (listOfMoves[i]>bestMove)
            bestMove=listOfMoves[i];
    
    return bestMove;
}

int Player::howMuchOpponentCanHurtMe(TTTBoard* tptr,Player* me, Player* other){
      vector<int> listOfMoves(9,0);
    int result;
    
    for (int i=0;i<NUMBER_OF_SQUARES;i++){
        
        //occupy every spot temporarily
        if(tptr->accessSpotOnBoard(i)==' '){
            tptr->setAValueInBoard(other->XorO, i);
            if (tptr->isGameOver() && tptr->hasWon())
                listOfMoves[i] = -9999;
            else if (tptr->isGameOver() && tptr->hasWon()==false)
                listOfMoves[i] = 0;
        } //record if there's a tie or a win
        
        result = howMuchOpponentCanHurtMe(tptr,this, other);
        
        tptr->setAValueInBoard(' ', i);
        
    }
    
    int bestMove=0;
    for (int i=0;i<listOfMoves.size();i++)
        if (listOfMoves[i]<bestMove)
            bestMove=listOfMoves[i];
    
    return bestMove;

}
*/

/*
int Player::miniMax(TTTBoard* tptr, Player *somePlayer){
    
  
    
    if (this->justWon(tptr))
        return 9999;
    else if (somePlayer->justWon(tptr) && somePlayer->XorO!=this->XorO)
        return -9999;
    
    int move = -1;
    int someScore=-26;
    int i;
    for (i = 1;i<=NUMBER_OF_SQUARES;i++){
        if (tptr->accessSpotOnBoard(i)==' '){
            tptr->setAValueInBoard(this->XorO, i);
            
            if(this->XorO =='X')
                this->XorO = 'O';
            else
                this->XorO ='X';
            
            int thisScore = -miniMax(tptr, this);
            if (thisScore > m_scoreForMoving){
                m_scoreForMoving = thisScore;
                move = i;
            }
        }
        
        tptr->setAValueInBoard(' ', i);
    }//end of for loop
    
    
    
    
    if (move==-1) return 0;
    return someScore;
}

void Player::performMove(TTTBoard* tptr){
    
      char temp = this->XorO;
    
    int move = -1;
    int score = -2;
    int i;
    for(i = 1; i <= 9; ++i) {
        if(tptr->isOccupied(i) == false) {
            tptr->setAValueInBoard(this->XorO, i);
            int tempScore = -miniMax(tptr, this);
            tptr->setAValueInBoard(' ', i);
            if(tempScore > m_scoreForMoving) {
                m_scoreForMoving = tempScore;
                move = i;
            }
        }
    }
    //returns a score based on minimax tree at a given node.
    tptr->setAValueInBoard(temp, move);
}
*/

/*
AImove Player::getBestMove(TTTBoard* tptr, int somePlayer){
    
    vector<AImove> listOfMoves;
    
    
    
    int returnValue = tptr->whoWon();
    if (returnValue==m_computer)
        return AImove(9999);
    else if (returnValue == m_human)
        return AImove(-9999);
    else if (returnValue==NO_VAL)
        return AImove(0);
    
    
     if(this->justWon(tptr)&&this->m_isAI)
     return AImove(9999);
     else if (this->justWon(tptr)&&this->m_isAI==false)
     return AImove(-9999);
     else if (tptr->isGameOver())
     return AImove(0);
 
    for (int i=1;i<10;i++)
    {
        if (tptr->accessSpotOnBoard(i)==' '){
            AImove someMove;
            someMove.posOnBoard = i;
            tptr->setAValueInBoard(this->XorO, i);
            if(m_computer== somePlayer){
                someMove.scoreForMoving = getBestMove(tptr,m_human).scoreForMoving;
            }
            else
                someMove.scoreForMoving = getBestMove(tptr, m_computer).scoreForMoving;
            
            listOfMoves.push_back(someMove);
            tptr->setAValueInBoard(' ', i);
        }
    }
    
    int bestMove = 0;
    if(somePlayer == m_computer){
        int bestScore = -10000;
        for (int i=0;i<listOfMoves.size();i++){
            if (listOfMoves[i].scoreForMoving>bestScore)
                bestMove = i;
            bestScore = listOfMoves[i].scoreForMoving;
        }
    }
    else{
        int bestScore = 10000;
        for (int i=0;i<listOfMoves.size();i++){
            if (listOfMoves[i].scoreForMoving<bestScore)
                bestMove = i;
            bestScore = listOfMoves[i].scoreForMoving;
        }
    }
    return listOfMoves[bestMove];
}

void Player::performMove(TTTBoard* tptr){
    AImove best = this->getBestMove(tptr, m_computer);
    tptr->setAValueInBoard(this->XorO,best.posOnBoard);
}
*/
