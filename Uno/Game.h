/* 
 * File:   Game.h
 * Author: Rachel Scherer
 * Created on October 22, 2018, 8:54 PM
 * Purpose: Uno Clone
 */

#include <cstdlib>
#include <iostream>
#include <utility>
#include <string>
#include <algorithm>
#include <deque>
#include <ctime>
#include <map>
#include <time.h>
#include <vector>

#ifndef GAME_H
#define GAME_H

class Game
{
private:
    //Typedefs
    typedef std::pair<int, std::string> card;
    typedef std::multimap<int,int> mmInt;
    
    //Deques/pairs
    std::deque<card>* plrHnd;                       //Holds cards dealt to each player
    std::deque<card> deck;                          //Holds rest of deck
    
    //Vectors
    std::vector<int> gamePts;
    
    //Bool flags
    bool eog;                                       //End of game flag
    bool skip;                                      //"Skip" card flag
    bool reverse;                                   //"Reverse" card flag
    bool wd4Mtch;                                   //"Wild Draw 4" flag used for computers to call bluff on player
    
    //Ints
    int numOpp;                                     //Number of opponents
    int numDrwn;                                    //Number of cards drawn (used to shuffle cards)
    int winner;                                     //Holds which player won game
    
    //Strings
    std::string wColor;                             //Holds color set by Wild/Wild Draw 4 cards
    
    //Member functions
    void defineDeck();                              //Initialize each card and shuffle them
    void dealDeck();                                //Deal the cards       
    bool checkCardValidity(std::string);            //Validates user input when checking card
    bool getColor(std::string&);                    //Validates user input when choosing wild card
    void computerTurn(int);                         //Handle opponent computer logic
    std::multimap<int,int> getCardColorOrder(int);  //Helps computer decide which card to choose
    std::string displayCard(card);                  //Display card
    void playCard(int,int);                         //Get special inputs for certain cards, organizes placeCard()
    void placeCard(int,int);                        //Adds card from player hand to deck
    void drawCard(int);                             //Draw Card

public:
    //Constuctors
    Game();                                         //Default Constructor
    Game(std::vector<int>);                         //Constructor using points earned from different game as an argument
    
    //Destructors
    ~Game();                                        //Deletes dynamically allocated data
    
    //Mutators
    bool setNumOpp(std::string);                    //Sets numOpponents
    
    //Accessors
    bool getEOG();                                  //Returns end of game flag
    std::vector<int> getGamePts();                  //Returns game points
    
    //Helper functions
    bool playAgain();                               //Asks user if they want to play again
    void getRound();                                //Gets one complete round of uno
    void displayPoints();                           //Displays points earned in game
};

#endif /* GAME_H */