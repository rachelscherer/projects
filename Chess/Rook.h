/* 
 * File:   Rook.h
 * Author: rachel
 *
 * Created on October 1, 2018, 7:58 PM
 */

#include "Piece.h"

#ifndef ROOK_H
#define ROOK_H

class Rook:public Piece{
private:
    string name = "Rook";
public:
    //Constructor
    Rook(int repVal):Piece(repVal){}
    
    //Destructor
    ~Rook(){}
    
    string getName(){return name;}
    void getPossibleMoves(int (&board)[8][8], bool check[], vector<int>& possibleMoves, bool& kPresent);
};

#endif /* ROOK_H */