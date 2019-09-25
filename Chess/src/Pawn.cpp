#include "Pawn.h"

void Pawn::getPossibleMoves(int (&board)[8][8], bool check[], vector<int>& possibleMoves, bool& kPresent){
    //Find the x and y coordinates of the selected piece on the board
    int x, y;
    for(int i=7;i>=0;i--){
        for(int j=0;j<8;j++){
            if(board[j][i] == repVal){
                y = i;
                x = j;
            }
        }
    }
    
    //If the piece belongs to player 1...
    if(repVal%2==0){
        if(y < 7 && board[x][y+1]==0) possibleMoves.push_back((y+1)*8+x);       //Add the location above if empty
        if(y == 1 && board[x][y+2]==0) possibleMoves.push_back((y+2)*8+x);      //Add 2 locations above if in starting position
        if((y < 7 && x > 0) && board[x-1][y+1]%2==1){                           //If the diagonal pieces contains opponent's piece...
            possibleMoves.push_back((y+1)*8+(x-1));                             //Add that location
            if(board[x-1][y+1]==31) kPresent = true;                            //If it happens to also be a king, set "kPresent" flag to true
        }
        if((y < 7 && x < 7) && board[x+1][y+1]%2==1){                           //Diagonal-right
            possibleMoves.push_back((y+1)*8+(x+1));
            if(board[x+1][y+1]==31) kPresent = true;
        }
        
    //Do the same, but for player 2.
    } else{                                                                         
        if(y > 0 && board[x][y-1]==0) possibleMoves.push_back((y-1)*8+x);
        if(y == 6 && board[x][y-2]==0) possibleMoves.push_back((y-2)*8+x);
        if((y > 0 && x > 0) && (board[x-1][y-1]%2==0 && board[x-1][y-1]!=0)){
            possibleMoves.push_back((y-1)*8+(x-1));
            if(board[x-1][y-1]==31) kPresent = true;
        }
        if((y > 0 && x < 7) && (board[x+1][y-1]%2==0 && board[x-1][y-1]!=0)){
            possibleMoves.push_back((y-1)*8+(x+1));
            if(board[x+1][y-1]==31) kPresent = true;
        }
    }
}

//bool Pawn::getEnPassant(){return enPassant;}

//void Pawn::setEnPassant(bool enPassant){
//    this->enPassant = enPassant;
//}