/* 
 * File:   Knight.h
 * Author: rachel
 *
 * Created on October 1, 2018, 7:58 PM
 */

#include "Piece.h"

#ifndef KNIGHT_H
#define KNIGHT_H

class Knight:public Piece{
private:
    const string name = "Knight";
public:
    //Constructor
    Knight(int repVal):Piece(repVal){}
    
    //Destructor
    ~Knight(){}
    
    string getName(){return name;}
    void getPossibleMoves(int (&board)[8][8], bool check[], vector<int>& possibleMoves, bool& kPresent);
};

#endif /* KNIGHT_H */