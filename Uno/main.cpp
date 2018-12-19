 /* 
 * File:   main.cpp
 * Author: Rachel Scherer
 * Created on October 21, 2018, 1:48 PM
 * Purpose: Uno Clone
 */

//System Libraries
#include <iostream>
#include <vector>

//User Libraries
#include "Game.h"

int main(int argc, char** argv)
{
    std::vector<Game> sess;
    int numSess = 0;
    do{
        //If this is the very first game, call the default constructor.
        if(numSess == 0)
        {
            sess.emplace_back();
        }
        //Otherwise, pass the points earned from the previous game as an argument to the next one.
        else
        {
            sess.emplace_back(sess[numSess-1].getGamePts());
        }
        std::cout << "Welcome to Uno!\n\n";
        std::string numOpp;
        
        //Get the number of opponents from the user, and validate using the getNumOpponents member function.
        do
        {
            std::cout << "How many computers would you like to play with? ";
            std::cin >> numOpp;
        }while(!sess[numSess].setNumOpp(numOpp));
        
        //Loop through each round until the EOG flag is called.
        do
        {
            sess[numSess].getRound();
        }while(!sess[numSess].getEOG());
        
        //If the game is finished, display the points.
        sess[numSess].displayPoints();
        
        //If the user wants to play again, loop back to top.
    }while(sess[numSess++].playAgain());
    
    return 0;
}