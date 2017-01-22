//
//  Player.h
//  TicTacToeRevised
//
//  Created by Jonathan Quach on 12/31/16.
//  Copyright © 2016 QuachLabs. All rights reserved.
//

#ifndef Player_h
#define Player_h
#include <vector>
class TTTBoard; //need to know what a board is



//awkward?
struct AImove{
    AImove();
    AImove(int score){
        scoreForMoving = score;
    }
    int posOnBoard;
    int scoreForMoving;
};


class Player{
public:
    Player();
    Player(bool isAI);
    void move(TTTBoard *tptr, int squarePosition, char someXorO);
    void updateXorO(char c);
    char getXorO() const;
    bool justWon(TTTBoard* tptr) const;
    void updateScore(int n);
    int getScore() const;
    
    void updateIsCurrentTurn(bool someValue);
    
    int pickOptimizedMove(TTTBoard* tptr, Player* opponent);
  
    int howMuchOpponentCanHurtMe(TTTBoard* tptr,Player* me, Player* somePlayer);


    int miniMax (TTTBoard* tptr, Player* somePlayer);
    
    AImove getBestMove(TTTBoard* tptr, int somePlayer);
    void performMove(TTTBoard* tptr);
   private:
    int m_score;
    char XorO;
    bool m_isAI;
    
    bool m_isCurrentTurn;
   
    int m_human;
    int m_computer;
    /*
    int m_positionOnBoard; //1-9
    int m_bestMove;
    
    int m_scoreForMoving;*/
    
    
    };
   




#endif /* Player_h */
