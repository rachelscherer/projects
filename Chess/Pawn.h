/* 
 * File:   Pawn.h
 * Author: rachel
 *
 * Created on October 1, 2018, 7:59 PM
 */

#include "Piece.h"

#ifndef PAWN_H
#define PAWN_H

class Pawn:public Piece{
private:
    const string name = "Pawn";
    //bool enPassant;
public:
    //Constructor
    Pawn(int repVal):Piece(repVal){}
    
    //Destructor
    ~Pawn(){}
    
    //Getters
    //bool getEnPassant();
    
    //Setters
    //void setEnPassant();
    
    string getName(){return name;}
    void getPossibleMoves(int (&board)[8][8], bool check[], vector<int>& possibleMoves, bool& kPresent);
};

#endif /* PAWN_H */