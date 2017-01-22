//
//  TTTBoard.cpp
//  TicTacToeRevised
//
//  Created by Jonathan Quach on 12/31/16.
//  Copyright © 2016 QuachLabs. All rights reserved.
//

#include <stdio.h>
#include "TTTBoard.h"
#include "Player.h"
#include <iostream>
#include <vector>
using namespace std;
TTTBoard::TTTBoard(){
    for (int i=0;i<NUMBER_OF_SQUARES;i++)
        m_board.push_back('_');
}
char TTTBoard:: accessSpotOnBoard(int n) const{
    
    if(m_board[n-1]==' ')
        cerr<<"This is empty!"<<endl;
    else if (m_board[n-1] =='X')
        cerr<<"This is an X!"<<endl;
    else if (m_board[n-1] == 'O')
        cerr<<"This is an O!"<<endl;
        return m_board[n-1];
}
std::vector<char> TTTBoard::accessBoard() const{
    return m_board;
}

void TTTBoard::printBoard() const{
    for (int i=0;i<9;i++){
        if (i !=0 && i % 3 == 0)
            std::cout<<std::endl;
        
        std::cout<<m_board[i]<<" ";
        if (i==2)
            std::cout<<"       1 2 3"; //these side numbers are here for reference of the player
        else if (i==5)
            std::cout<<"       4 5 6";
        else if (i==8)
            std::cout<<"       7 8 9";
        
    }
    std::cout<<std::endl;
    std::cout<<"==========================="<<std::endl;
    
}

void TTTBoard::clearBoard() {
    for (int i=0;i<9;++i)
        m_board[i] = '_';
}

bool TTTBoard::isFull() const{
    bool hasNoUnderscores = true;
    
    for (int i=0;i<NUMBER_OF_SQUARES;i++)
        if (m_board[i]=='_')
            hasNoUnderscores = false;
    
    return hasNoUnderscores;

}

bool TTTBoard::isOccupied(int spot) const{
    return (m_board[spot-1]!='_');
}

bool TTTBoard::hasWon() const{
    if (m_board[0]!='_' && m_board[0]==m_board[3] && m_board[3]==m_board[6])
        return true;
    
    if (m_board[0]!='_' && m_board[0]==m_board[4] && m_board[4]==m_board[8])
        return true;
    
    if (m_board[0]!='_' && m_board[0]==m_board[1] && m_board[1]==m_board[2])
        return true;
    
    if (m_board[1]!='_' && m_board[1]==m_board[4] && m_board[4]==m_board[7])
        return true;
    
    if (m_board[2]!='_' && m_board[2]==m_board[4] && m_board[4]==m_board[6])
        return true;
    
    if (m_board[2]!='_' && m_board[2]==m_board[5] && m_board[5]==m_board[8])
        return true;
    
    if (m_board[3]!='_' && m_board[3]==m_board[4] && m_board[4]==m_board[5])
        return true;
    
    if (m_board[6]!='_' && m_board[6]==m_board[7] && m_board[7]==m_board[8])
        return true;
    
    return false;
}

bool TTTBoard::isGameOver() const{
    //game is over when three Xs or three Os are in a row or when the board is full
    
    if (isFull() || hasWon())
        return true;
    
    return false;

}

bool TTTBoard::updateBoard(char XorO, int squarePosition,bool isPlayer = true){
    
    if (isPlayer){
       
       if (m_board[squarePosition-1]!='_'){
            std::cout<<"That square is already occupied!"<<std::endl;
            std::cout<<"Please try a different square :)"<<std::endl;
           std::cout<<"Square position: "<<std::endl;
                return false;
        }

    }
    else{
        if (squarePosition>9 || squarePosition < 1)
            return false;
        if (m_board[squarePosition-1]!='_')
            return false;
    }//end of all possible ways board returns false
    
    
    m_board[squarePosition-1] = XorO;
    
        return true;
}


void TTTBoard::setAValueInBoard(char c, int squarePosition){
    m_board[squarePosition-1] = c;
}


//helper
int TTTBoard::whoWon() const{
    if (m_board[0]=='X' && m_board[0]==m_board[3] && m_board[3]==m_board[6])
        return X_VAL;
    
    if (m_board[0]!='X' && m_board[0]==m_board[4] && m_board[4]==m_board[8])
        return X_VAL;
    
    if (m_board[0]!='X' && m_board[0]==m_board[1] && m_board[1]==m_board[2])
        return X_VAL;
    
    if (m_board[1]!='X' && m_board[1]==m_board[4] && m_board[4]==m_board[7])
        return X_VAL;
    
    if (m_board[2]!='X' && m_board[2]==m_board[4] && m_board[4]==m_board[6])
        return X_VAL;
    
    if (m_board[2]!='X' && m_board[2]==m_board[5] && m_board[5]==m_board[8])
        return X_VAL;
    
    if (m_board[3]!='X' && m_board[3]==m_board[4] && m_board[4]==m_board[5])
        return X_VAL;
    
    if (m_board[6]!='X' && m_board[6]==m_board[7] && m_board[7]==m_board[8])
        return X_VAL;
    
    
    
    if (m_board[0]=='O' && m_board[0]==m_board[3] && m_board[3]==m_board[6])
        return O_VAL;
    
    if (m_board[0]!='O' && m_board[0]==m_board[4] && m_board[4]==m_board[8])
        return X_VAL;
    
    if (m_board[0]!='O' && m_board[0]==m_board[1] && m_board[1]==m_board[2])
        return O_VAL;
    
    if (m_board[1]!='O' && m_board[1]==m_board[4] && m_board[4]==m_board[7])
        return O_VAL;
    
    if (m_board[2]!='O' && m_board[2]==m_board[4] && m_board[4]==m_board[6])
        return O_VAL;
    
    if (m_board[2]!='O' && m_board[2]==m_board[5] && m_board[5]==m_board[8])
        return O_VAL;
    
    if (m_board[3]!='O' && m_board[3]==m_board[4] && m_board[4]==m_board[5])
        return O_VAL;
    
    if (m_board[6]!='O' && m_board[6]==m_board[7] && m_board[7]==m_board[8])
        return O_VAL;
    
    
    return NO_VAL;

}
