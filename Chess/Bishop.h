/* 
 * File:   Bishop.h
 * Author: rachel
 *
 * Created on October 1, 2018, 7:58 PM
 */

#include "Piece.h"

#ifndef BISHOP_H
#define BISHOP_H

class Bishop:public Piece{
private:
    const string name = "Bishop";
public:
    //Constructor
    Bishop(int repVal):Piece(repVal){}
    
    //Destructor
    ~Bishop(){}
    
    string getName(){return name;}
    void getPossibleMoves(int (&board)[8][8], bool check[], vector<int>& possibleMoves, bool& kPresent);
};

#endif /* BISHOP_H */