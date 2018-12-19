/* 
 * File:   Chess.h
 * Author: rachel
 *
 * Created on October 1, 2018, 7:51 PM
 */

//User libraries
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include "Pawn.h"

//I'm including both <vector> and "Vector.h" as this program built pretty heavily
//using iterators and nothing wants to play nice with my simple vector class.
//However, pieceBank[] can use it so it's included!
#include "MyVector.h"

//System Libraries
#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;

#ifndef CHESS_H
#define CHESS_H

class Chess{
private:
    //Board and piece information
    Piece** pieces;                         //Array of chess pieces
    int board[8][8];                        //Stores where the pieces are on the board
    vector<int> possibleMoves;              //Stores location a given piece can move to
    MyVector pieceBank[2];                  //Captured pieces go here
    vector<string> moveHistory;             //Contains a history of every move in the game
    int turnNumber;                         //Counts how many turns have passed
    
    //drawBoard() Helper functions
    void drawCharCoordinate();              //Draws "  A    B    C    D    E   "
    void drawLongLine();                    //Draws "__________________________"
    void drawEmptyLines();                  //Draws "|    |    |    |    |    |"

    //User Validation
    bool checkInputValidity(string);        //Validates the input from the user
    bool checkStartValidity(int,int);       //Verifies if the user selects a valid start piece
    bool checkDestinationValidity(int,int); //Verifies if the user selects a valid end piece
    
    //Game flags
    bool oppTurn;                           //Whose turn is it?
    bool gameWon;                           //Did someone win the game?
    bool check[2];                          //Is anyone currently in check?
    
    //Display functions
    void displayPieceBank();                //Displays the captured pieces
    void displayHistory();                  //Displays the history
    
    //Core game functionality
    void makeMove(int,int,int,int,char);    //Executes a given move
    void getPossibleMoves(int,int);         //Gets all the possible moves given a set of coordinates
    bool getCheckStatus(bool);              //Checks to see if a player is able to reach the other's king
    bool getCheckMateStatus();              //Checks if a checkmate has been reached
public:
    //Constructors
    Chess();                                //Default
    Chess(const Chess&);                    //Copy
    Chess operator=(const Chess&);          //Operator overloaded
    
    //Destructor
    ~Chess();
    
    bool checkValidity(string&);            //Calls private input validation functions
    bool getOppTurn();                      //Returns "oppTurn"
    void drawBoard();                       //Draws the board
};

#endif /* CHESS_H */