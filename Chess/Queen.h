/* 
 * File:   Queen.h
 * Author: rachel
 *
 * Created on October 1, 2018, 7:58 PM
 */

#include "Piece.h"

#ifndef QUEEN_H
#define QUEEN_H

class Queen:public Piece{
private:
    string name = "Queen";
public:
    //Constructor
    Queen(int repVal):Piece(repVal){}
    
    //Destructor
    ~Queen(){}
    
    string getName(){return name;}
    void getPossibleMoves(int (&board)[8][8], bool check[], vector<int>& possibleMoves, bool& kPresent);
};

#endif /* QUEEN_H */