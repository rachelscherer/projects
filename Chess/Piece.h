 /* 
 * File:   Piece.h
 * Author: rachel
 *
 * Created on October 2, 2018, 6:34 PM
 */

#ifndef PIECE_H
#define PIECE_H

#include <string>
#include <vector>
using namespace std;

class Piece{
protected:
    int repVal;
public:
    //Constructor
    Piece(int repVal);
    
    //Destructor
    virtual ~Piece(){};
    
    //Getters
    int getRepVal(){return repVal;}
    virtual string getName(){}
    
    bool isOpponent();
    virtual void getPossibleMoves(int (&board)[8][8], bool check[], vector<int>& possibleMoves, bool& kPresent){}
};

#endif /* PIECE_H */