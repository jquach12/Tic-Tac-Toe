//
//  Game.h
//  TicTacToeRevised
//
//  Created by Jonathan Quach on 12/31/16.
//  Copyright © 2016 QuachLabs. All rights reserved.
//

#ifndef Game_h
#define Game_h

class Player;
class TTTBoard;

class AI;

class Game{
public:
    Game();
    ~Game();
    
    void welcomeMessage() const;
    TTTBoard* getBoard() const;
    void alternateSwitch();
    void playerVSplayer();
    
    void round(Player* p);
    
    void playVersusEasyAI();
    void playVersusMediumAI();
    
    
    void playVersusHardAI();
    
    void menu();
    int smartMove(TTTBoard* tttptr) const; //helper function for medium AI
private:
    TTTBoard* m_gboard;
    Player* m_somePlayer;
    Player* m_someSecondPlayer;
    int m_rounds;
    bool m_switch;
};

#endif /* Game_h */
