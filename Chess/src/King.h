/* 
 * File:   King.h
 * Author: rachel
 *
 * Created on October 1, 2018, 7:57 PM
 */

#include "Piece.h"

#ifndef KING_H
#define KING_H

class King:public Piece{
private:
    const string name = "King";
public:
    //Constructor
    King(int repVal):Piece(repVal){}
    
    //Destructor
    ~King(){}
    
    string getName(){return name;}
    void getPossibleMoves(int (&board)[8][8], bool check[], vector<int>& possibleMoves, bool& kPresent);
};

#endif /* KING_H */