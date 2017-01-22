//
//  Game.cpp
//  TicTacToeRevised
//
//  Created by Jonathan Quach on 12/31/16.
//  Copyright © 2016 QuachLabs. All rights reserved.
//

#include <stdio.h>
#include "Player.h"
#include "TTTBoard.h"
#include "Game.h"




#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

Game::Game()
:m_rounds(1),m_switch(true)
{
    m_gboard = new TTTBoard;
    m_somePlayer = new Player;
    m_someSecondPlayer = new Player;
}

Game::~Game(){
    delete m_gboard;
    delete m_someSecondPlayer;
    delete m_somePlayer;
}
void Game::alternateSwitch(){
    if (m_switch)
        m_switch = false;
    else
        m_switch = true;
}
void Game::menu(){
    cout<<"Pick a mode. Any natural single number not in the list will quit the gane :)"<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"1. Player Versus Player"<<endl;
    cout<<"2. Player Versus Computer (ez pz)"<<endl;
    cout<<"3. Player Versus Computer (medium difficulty)"<<endl;
    
    string input;
    cout<<endl;
    cout<<"Game mode: ";
    getline(cin,input);
    cout<<endl;
    
    //while player does not give a valid spot in the board
    while(input.size()!= 1 || !isdigit(input[0])){
        cout<<"ERROR! Only a single digit input from 1 to 9 are valid"<<endl;
        getline(cin,input);
        
    }
    int convertInputToInt = input[0]-'0';
    switch (convertInputToInt) {
        case 1:
            playerVSplayer();
            break;
        
        case 2:
            playVersusEasyAI();
            break;
        
        case 3:
            playVersusMediumAI();
            break;
        default:
            cout<<"Thanks for playing!"<<endl;
            break;
    }
}


TTTBoard* Game::getBoard() const{
    return m_gboard;
}
void Game::welcomeMessage() const{
    cout<<"Welcome to a round of Tic-Tac-Toe!"<<endl;
    cout<<"Type in the number that corresponds to where you want to insert your X or O!"<<endl;
    cout<<"==========================="<<endl;
}

//under construction, not actually called yet
void Game::round(Player *p){
    alternateSwitch();
    cout<<"Player 1's turn."<<endl;
    cout<<"Place an '"<<p->getXorO()<<"' on the board!"<<endl;
    cout<<"Square position: ";
    
    string pinput;
    
    getline(cin,pinput);
    cout<<endl;
    
    //while player does not give a valid spot in the board
    while(pinput.size()!= 1 || !isdigit(pinput[0])){
        cout<<"Please type only a valid position in the Tic-Tac-Toe."<<endl;
        getline(cin,pinput);
    }
    while(m_gboard->isOccupied(pinput[0]-'0')){
        cout<<"That square is already occupied! Please choose an empty spot."<<endl;
        cout<<"Square position: ";
        getline(cin,pinput);
    }
    
    //after moving, check to see if the game ends.
    //if game ends, first check if game is won, then check if the board is full (in that order*)
    //otherwise, the game is a draw (*sometimes game is won and board is full at the same time)
    
    p->move(m_gboard, pinput[0]-'0',p->getXorO() );
    m_gboard->printBoard();
    if(m_gboard->isGameOver()){
        if (m_gboard->hasWon()){
            cout<<"Player 1 has won!"<<endl;
            p->updateScore(1);
            
        }
        else{
            cout<<"Draw!"<<endl;
            
        }
    }
}





//looks good!
void Game::playerVSplayer(){
    
    Player* p1 = m_somePlayer;
    Player* p2 = m_someSecondPlayer;
    
    m_gboard->clearBoard();//for replay
    
    if (m_rounds==1)
        welcomeMessage();
    
    m_gboard->printBoard();
    
    
    //randomly choose who is X and who is O
    int randomlyChooseXorO = rand()%2;
    if (randomlyChooseXorO){
        p1->updateXorO('X');
        p2->updateXorO('O');
    }
    else{
        p1->updateXorO('O');
        p2->updateXorO('X');
    }
    
    
    
    string p1input; //remember, we cannot expect the players to always put in valid answers
    
    string p2input;
    while(1){
        
        
        int cycle = 0;
        
        //player 1 goes first in the first round, and who goes first alternates from then on
        if (m_switch){
            alternateSwitch();
            cout<<"Player 1's turn."<<endl;
            cout<<"Place an '"<<p1->getXorO()<<"' on the board!"<<endl;
            cout<<"Square position: ";
            
            getline(cin,p1input);
            cout<<endl;
            
            //while player does not give a valid spot in the board
            while(p1input.size()!= 1 || !isdigit(p1input[0])){
                cout<<"Please type only a valid position in the Tic-Tac-Toe."<<endl;
                getline(cin,p1input);
            }
            while(m_gboard->isOccupied(p1input[0]-'0')){
                cout<<"That square is already occupied! Please choose an empty spot."<<endl;
                cout<<"Square position: ";
                getline(cin,p1input);
            }
            
            //after moving, check to see if the game ends.
            //if game ends, first check if game is won, then check if the board is full (in that order*)
            //otherwise, the game is a draw (*sometimes game is won and board is full at the same time)
            
            p1->move(m_gboard, p1input[0]-'0',p1->getXorO() );
            m_gboard->printBoard();
            if(m_gboard->isGameOver()){
                if (m_gboard->hasWon()){
                    cout<<"Player 1 has won!"<<endl;
                    p1->updateScore(1);
                    break;
                }
                else{
                    cout<<"Draw!"<<endl;
                    break;
                }
            }
        }
        
        else{
            alternateSwitch();
            cout<<"Player 2's turn."<<endl;
            cout<<"Place an '"<<p2->getXorO()<<"' on the board!"<<endl;
            cout<<"Square position: ";
            getline(cin,p2input);
            cout<<endl;
            cycle++;
            
            while(p2input.size()!= 1 || !isdigit(p2input[0])){
                cout<<"Please type only a valid position in the Tic-Tac-Toe."<<endl;
                getline(cin,p2input);
            }
            while(m_gboard->isOccupied(p2input[0]-'0')){
                cout<<"That square is already occupied! Please choose an empty spot."<<endl;
                cout<<"Square position: ";
                getline(cin,p2input);
            }

            p2->move(m_gboard, p2input[0]-'0', p2->getXorO());
            m_gboard->printBoard();
            if(m_gboard->isGameOver()){
                if (m_gboard->hasWon()){
                    cout<<"Player 2 has won!"<<endl;
                    p2->updateScore(1);
                    break;
                }
                else{
                    cout<<"Draw!"<<endl;
                    break;
                }
            }
    
             
        
        }
        
        
    }//end of while
    
    cout<<"Current score:"<<endl;
    cout<<"Player 1: "<<p1->getScore()<<endl;
    cout<<"Player 2: "<<p2->getScore()<<endl;
    m_rounds++;
    
    string replay;
    cout<<"Play again? Enter 'y' to play another round or 'n' to quit to main menu."<<endl;
    getline(cin,replay);
    
    //again, making sure we get a valid input
    while(replay.size()!=1){
        cout<<"Please enter either 'y' or 'n'"<<endl;
        getline(cin,replay);
    }
    
    while(replay[0]!='n' && replay[0]!='y'){
        cout<<"Please enter either 'y' or 'n'"<<endl;
        getline(cin,replay);

    }
    char yesOrNo = tolower(replay[0]);
    
    //end the game if 'n', play another if 'y'
    if (yesOrNo=='n'){
        cout<<"Thanks for playing!"<<endl;
    }
    else {
        cout<<"Initiating another round..."<<endl;
        cout<<"==========================="<<endl;
        playerVSplayer();
    }
}

void Game::playVersusEasyAI(){
    Player* p1 = m_somePlayer;
    Player* ai = m_someSecondPlayer;
    
    m_gboard->clearBoard();//for replay
    
    if (m_rounds==1)
        welcomeMessage();
    
    m_gboard->printBoard();

    //randomly choose who is X and who is O
    int randomlyChooseXorO = rand()%2;
    if (randomlyChooseXorO){
        p1->updateXorO('X');
        ai->updateXorO('O');
    }
    else{
        p1->updateXorO('O');
        ai->updateXorO('X');
    }
    
    
    
    string p1input; //remember, we cannot expect the players to always put in valid answers

    
    while(1){
        
       
        
        if (m_switch){
            alternateSwitch();
            cout<<"Player 1's turn."<<endl;
            cout<<"Place an '"<<p1->getXorO()<<"' on the board!"<<endl;
            cout<<"Square position: ";
            
            getline(cin,p1input);
            cout<<endl;
            
            
            while(p1input.size()!= 1 || !isdigit(p1input[0])){
                cout<<"Please type only a valid position in the Tic-Tac-Toe."<<endl;
                getline(cin,p1input);
            }
            while(m_gboard->isOccupied(p1input[0]-'0')){
                cout<<"That square is already occupied! Please choose an empty spot."<<endl;
                cout<<"Square position: ";
                getline(cin,p1input);
            }
            p1->move(m_gboard, p1input[0]-'0',p1->getXorO() );
            m_gboard->printBoard();
            if(m_gboard->isGameOver()){
                if (m_gboard->hasWon()){
                    cout<<"Player 1 has won!"<<endl;
                    p1->updateScore(1);
                    break;
                }
                else{
                    cout<<"Draw!"<<endl;
                    break;
                }
            }
        }
        
        else{
            alternateSwitch();
            cout<<"Computer's turn."<<endl;
            
            //have computer randomly choose a valid spot in the game
            int randomlyChosenSquare = rand()%9+1;
            while(m_gboard->isOccupied(randomlyChosenSquare))
                randomlyChosenSquare = rand()%9+1;
            
            cout<<"Square position: "<<randomlyChosenSquare<<endl;
            cout<<endl;
            
            
            
            
            ai->move(m_gboard,randomlyChosenSquare, ai->getXorO());
            m_gboard->printBoard();
            if(m_gboard->isGameOver()){
                if (m_gboard->hasWon()){
                    cout<<"Computer has won!"<<endl;
                    ai->updateScore(1);
                    break;
                }
                else{
                    cout<<"Draw!"<<endl;
                    break;
                }
            }
            
            
        }
        
        
        
    }//end of while
    
    cout<<"Current score:"<<endl;
    cout<<"Player 1: "<<p1->getScore()<<endl;
    cout<<"Computer: "<<ai->getScore()<<endl;
    m_rounds++;
    
    /* //carey said to replay in the main, not game
    string replay;
    cout<<"Play again? Enter 'y' to play another round or 'n' to quit."<<endl;
    getline(cin,replay);
    
    while(replay.size()!=1){
        cout<<"Please enter either 'y' or 'n'"<<endl;
        getline(cin,replay);
    }
    
    while(replay[0]!='n' && replay[0]!='y'){
        cout<<"Please enter either 'y' or 'n'"<<endl;
        getline(cin,replay);
        
    }
    char yesOrNo = tolower(replay[0]);
    
    if (yesOrNo=='n'){
        cout<<"Thanks for playing!"<<endl;
        return;
    }
    else {
        cout<<"Initiating another round..."<<endl;
        cout<<"==========================="<<endl;
        playVersusEasyAI();
    }*/
}

int Game::smartMove(TTTBoard *tttptr) const{
    
    //remember that in the actual game, the players see 123456789, not 012345678
    
    /* 0 1 2
       3 4 5
       6 7 8*/
    
    //column 1
    if (tttptr->accessBoard()[0]=='_' && tttptr->accessBoard()[3]==tttptr->accessBoard()[6])
        return 1;
    if (tttptr->accessBoard()[0]==tttptr->accessBoard()[6] && tttptr->accessBoard()[3]=='_')
        return 4;
    if (tttptr->accessBoard()[0]==tttptr->accessBoard()[3] && tttptr->accessBoard()[6]=='_')
        return 7;
    
    
    //upper left to lower right diagonal
    if (tttptr->accessBoard()[0]=='_' && tttptr->accessBoard()[4]==tttptr->accessBoard()[8])
        return 1;
    if (tttptr->accessBoard()[0]==tttptr->accessBoard()[8]&&tttptr->accessBoard()[4]=='_')
        return 5;
    if (tttptr->accessBoard()[0]==tttptr->accessBoard()[4]&&tttptr->accessBoard()[8]=='_')
        return 9;
    
    
    //row 1
    if (tttptr->accessBoard()[0]=='_' && tttptr->accessBoard()[1]==tttptr->accessBoard()[2])
        return 1;
    if (tttptr->accessBoard()[0]==tttptr->accessBoard()[2] && tttptr->accessBoard()[1]=='_')
        return 2;
    if (tttptr->accessBoard()[0]==tttptr->accessBoard()[1] && tttptr->accessBoard()[2]=='_')
        return 3;
    
    
    //column 2
    if (tttptr->accessBoard()[1]=='_' && tttptr->accessBoard()[4]==tttptr->accessBoard()[7])
        return 2;
    if (tttptr->accessBoard()[1]==tttptr->accessBoard()[7] && tttptr->accessBoard()[4]=='_')
        return 5;
    if (tttptr->accessBoard()[1]==tttptr->accessBoard()[4] && tttptr->accessBoard()[7]=='_')
        return 8;

    
    
    //upper right to lower left diagonal
    if (tttptr->accessBoard()[2]=='_' && tttptr->accessBoard()[4]==tttptr->accessBoard()[6])
        return 3;
    if (tttptr->accessBoard()[2]==tttptr->accessBoard()[6] && tttptr->accessBoard()[4]=='_')
        return 5;
    if (tttptr->accessBoard()[2]==tttptr->accessBoard()[4] && tttptr->accessBoard()[6]=='_')
        return 7;
    
    //column 3
    if (tttptr->accessBoard()[2]=='_' && tttptr->accessBoard()[5]==tttptr->accessBoard()[8])
        return 3;
    if (tttptr->accessBoard()[2]==tttptr->accessBoard()[8] && tttptr->accessBoard()[5]=='_')
        return 6;
    if (tttptr->accessBoard()[2]==tttptr->accessBoard()[5] && tttptr->accessBoard()[8]=='_')
        return 9;
    
    
    //row 2
    if (tttptr->accessBoard()[3]=='_' && tttptr->accessBoard()[4]==tttptr->accessBoard()[5])
        return 4;
    if (tttptr->accessBoard()[3]==tttptr->accessBoard()[5] && tttptr->accessBoard()[4]=='_')
        return 5;
    if (tttptr->accessBoard()[3]==tttptr->accessBoard()[4] && tttptr->accessBoard()[5]=='_')
        return 6;
    
    //row 3
    if (tttptr->accessBoard()[6]=='_' && tttptr->accessBoard()[7]==tttptr->accessBoard()[8])
        return 7;
    if (tttptr->accessBoard()[6]==tttptr->accessBoard()[8] && tttptr->accessBoard()[7]=='_')
        return 8;
    if (tttptr->accessBoard()[6]==tttptr->accessBoard()[7] && tttptr->accessBoard()[8]=='_')
        return 9;


    return -1; //this just there was no 1 turn that could have ended the game as a win
}


void Game::playVersusMediumAI(){
    Player* p1 = m_somePlayer;
    Player* ai = m_someSecondPlayer;
    
    m_gboard->clearBoard();//for replay
    
    if (m_rounds==1)
        welcomeMessage();
    
    m_gboard->printBoard();
    
    //randomly choose who is X and who is O
    int randomlyChooseXorO = rand()%2;
    if (randomlyChooseXorO){
        p1->updateXorO('X');
        ai->updateXorO('O');
    }
    else{
        p1->updateXorO('O');
        ai->updateXorO('X');
    }
    
    
    
    string p1input; //remember, we cannot expect the players to always put in valid answers
    
    
    while(1){
        
        
        
        if (m_switch){
            alternateSwitch();
            cout<<"Player 1's turn."<<endl;
            cout<<"Place an '"<<p1->getXorO()<<"' on the board!"<<endl;
            cout<<"Square position: ";
            
            getline(cin,p1input);
            cout<<endl;
            
            
            while(p1input.size()!= 1 || !isdigit(p1input[0])){
                cout<<"Please type only a valid position in the Tic-Tac-Toe."<<endl;
                getline(cin,p1input);
            }
            while(m_gboard->isOccupied(p1input[0]-'0')){
                cout<<"That square is already occupied! Please choose an empty spot."<<endl;
                cout<<"Square position: ";
                getline(cin,p1input);
            }
            p1->move(m_gboard, p1input[0]-'0',p1->getXorO() );
            m_gboard->printBoard();
            if(m_gboard->isGameOver()){
                if (m_gboard->hasWon()){
                    cout<<"Player 1 has won!"<<endl;
                    p1->updateScore(1);
                    break;
                }
                else{
                    cout<<"Draw!"<<endl;
                    break;
                }
            }
        }
        else{
            alternateSwitch();
            cout<<"Computer's turn."<<endl;
            
            //have computer first consider a spot in the game that results in a win or blocking a win
            int potentialSquare = smartMove(m_gboard);
            if (potentialSquare==-1)
                potentialSquare= rand()%9+1; //chose not to have smartMove() return this
                                             //because I do not want to keep calling it to get rand()
                                             //also easy to discern if the move was wisely chosen and not random
            while(m_gboard->isOccupied(potentialSquare))
                potentialSquare = rand()%9+1;
            
            cout<<"Square position: "<<potentialSquare<<endl;
            cout<<endl;
            
            
            
            
            ai->move(m_gboard,potentialSquare, ai->getXorO());
            m_gboard->printBoard();
            if(m_gboard->isGameOver()){
                if (m_gboard->hasWon()){
                    cout<<"Computer has won!"<<endl;
                    ai->updateScore(1);
                    break;
                }
                else{
                    cout<<"Draw!"<<endl;
                    break;
                }
            }
            
            
        }
    
    
        
    }//end of while
    
    cout<<"Current score:"<<endl;
    cout<<"Player 1: "<<p1->getScore()<<endl;
    cout<<"Computer: "<<ai->getScore()<<endl;
    m_rounds++;
    
    
    /* //carey said due to memory restrictions, we should not call replay here
    string replay;
    cout<<"Play again? Enter 'y' to play another round or 'n' to quit."<<endl;
    getline(cin,replay);
    
    while(replay.size()!=1){
        cout<<"Please enter either 'y' or 'n'"<<endl;
        getline(cin,replay);
    }
    
    while(replay[0]!='n' && replay[0]!='y'){
        cout<<"Please enter either 'y' or 'n'"<<endl;
        getline(cin,replay);
        
    }
    char yesOrNo = tolower(replay[0]);
    
    if (yesOrNo=='n'){
        cout<<"Thanks for playing!"<<endl;
        
        return;
    }
    else {
        cout<<"Initiating another round..."<<endl;
        cout<<"==========================="<<endl;
        playVersusMediumAI();
    }*/

}
