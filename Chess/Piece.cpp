#include "Piece.h"

Piece::Piece(int repVal){
    this->repVal = repVal;
}

/**
 * Odd values belong to the opponent. Even ones belong to the player
 * @return 
 */
bool Piece::isOpponent(){
    if((repVal%2)==1) return true;
    return false;
}