#include "Knight.h"

void Knight::getPossibleMoves(int (&board)[8][8], bool check[], vector<int>& possibleMoves, bool& kPresent){
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
    
    //Check the eight possible spaces around the knight
    if(repVal%2==0){
        if((x > 0 && y > 1) && ((board[x-1][y-2]==0) || board[x-1][y-2]%2==1)){
            possibleMoves.push_back((y-2)*8+(x-1));
            if(board[x-1][y-2]==31) kPresent = true; //If that piece happens to belong to a king, set kPresent to true.
        }
        if((x > 1 && y > 0) && ((board[x-2][y-1]==0) || board[x-2][y-1]%2==1)){
            possibleMoves.push_back((y-1)*8+(x-2));
            if(board[x-2][y-1]==31) kPresent = true;
        }
        if((x > 0 && y < 6) && ((board[x-1][y+2]==0) || board[x-1][y+2]%2==1)){
            possibleMoves.push_back((y+2)*8+(x-1));
            if(board[x-1][y+2]==31) kPresent = true;
        }
        if((x > 1 && y < 7) && ((board[x-2][y+1]==0) || board[x-2][y+1]%2==1)){
            possibleMoves.push_back((y+1)*8+(x-2));
            if(board[x-2][y+1]==31) kPresent = true;
        }
        if((x < 7 && y > 1) && ((board[x+1][y-2]==0) || board[x+1][y-2]%2==1)){
            possibleMoves.push_back((y-2)*8+(x+1));
            if(board[x+1][y-2]==31) kPresent = true;
        }
        if((x < 6 && y > 0) && ((board[x+2][y-1]==0) || board[x+2][y-1]%2==1)){
            possibleMoves.push_back((y-1)*8+(x+2));
            if(board[x+2][y-1]==31) kPresent = true;
        }
        if((x < 7 && y < 6) && ((board[x+1][y+2]==0) || board[x+1][y+2]%2==1)){
            possibleMoves.push_back((y+2)*8+(x+1));
            if(board[x+1][y+2]==31) kPresent = true;
        }
        if((x < 6 && y < 7) && ((board[x+2][y+1]==0) || board[x+2][y+1]%2==1)){
            possibleMoves.push_back((y+1)*8+(x+2));
            if(board[x+2][y+1]==31) kPresent = true;
        }
    } else{
        if((x > 0 && y > 1) && board[x-1][y-2]%2==0){
            possibleMoves.push_back((y-2)*8+(x-1));
            if(board[x-1][y-2]==32) kPresent = true;
        }
        if((x > 1 && y > 0) && board[x-2][y-1]%2==0){
            possibleMoves.push_back((y-1)*8+(x-2));
            if(board[x-2][y-1]==32) kPresent = true;
        }
        if((x > 0 && y < 6) && board[x-1][y+2]%2==0){
            possibleMoves.push_back((y+2)*8+(x-1));
            if(board[x-1][y+2]==32) kPresent = true;
        }
        if((x > 1 && y < 7) && board[x-2][y+1]%2==0){
            possibleMoves.push_back((y+1)*8+(x-2));
            if(board[x-2][y+1]==32) kPresent = true;
        }
        if((x < 7 && y > 1) && board[x+1][y-2]%2==0){
            possibleMoves.push_back((y-2)*8+(x+1));
            if(board[x+1][y-2]==32) kPresent = true;
        }
        if((x < 6 && y > 0) && board[x+2][y-1]%2==0){
            possibleMoves.push_back((y-1)*8+(x+2));
            if(board[x+2][y-1]==32) kPresent = true;
        }
        if((x < 7 && y < 6) && board[x+1][y+2]%2==0){
            possibleMoves.push_back((y+2)*8+(x+1));
            if(board[x+1][y+2]==32) kPresent = true;
        }
        if((x < 6 && y < 7) && board[x+2][y+1]%2==0){
            possibleMoves.push_back((y+1)*8+(x+2));
            if(board[x+2][y+1]==32) kPresent = true;
        }
    }
}