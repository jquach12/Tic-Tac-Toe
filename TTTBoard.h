//
//  TTTBoard.h
//  TicTacToeRevised
//
//  Created by Jonathan Quach on 12/31/16.
//  Copyright © 2016 QuachLabs. All rights reserved.
//

#ifndef TTTBoard_h
#define TTTBoard_h
#include "Player.h"
#include <vector>
const int NUMBER_OF_SQUARES=9;
const int NO_VAL = 0;
const int X_VAL = 1;
const int O_VAL = 2;

class TTTBoard{
public:
    TTTBoard();
    char accessSpotOnBoard(int n) const;
    
    
    //helper
    //int checkWhoWon(Player* pptr) const;
    
    
    std::vector<char> accessBoard() const; //remove this later
    void printBoard() const;
    void clearBoard();
    bool isFull() const;
    bool hasWon() const;
    bool isGameOver() const;
    bool isOccupied(int spot) const;
    bool updateBoard(char XorO, int squarePosition, bool isPlayer); //isPlayer is set to true by default
    
    void setAValueInBoard(char c, int squarePosition); //needed for AI
    
    int whoWon() const;
private:
    std::vector<char> m_board;
    /*
        '_','_','_',
        '_','_','_',
        '_','_','_',
     */
    
    
};


#endif /* TTTBoard_h */
