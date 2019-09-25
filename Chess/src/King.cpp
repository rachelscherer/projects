#include "King.h"

void King::getPossibleMoves(int (&board)[8][8], bool check[], vector<int>& possibleMoves, bool& kPresent){
    
    //NOTE - It is impossible for a king to actively or passively put another King in check, so we will ignore "kPresent"
    
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
    
    //Check for all the spaces immediately around the king
    if(repVal%2==0){
        if(x > 0 && (board[x-1][y]==0 || board[x-1][y]%2==1)) possibleMoves.push_back(y*8+(x-1));
        if(x < 7 && (board[x+1][y]==0 || board[x+1][y]%2==1)) possibleMoves.push_back(y*8+(x+1));
        if(y > 0 && (board[x][y-1]==0 || board[x][y-1]%2==1)) possibleMoves.push_back((y-1)*8+x);
        if(y < 7 && (board[x][y+1]==0 || board[x][y+1]%2==1)) possibleMoves.push_back((y+1)*8+x);
        if((x > 0 && y > 0) && (board[x-1][y-1]==0 || board[x-1][y-1]%2==1)) possibleMoves.push_back((y-1)*8+(x-1));
        if((x > 0 && y < 7) && (board[x-1][y+1]==0 || board[x-1][y+1]%2==1)) possibleMoves.push_back((y+1)*8+(x-1));
        if((x < 7 && y > 0) && (board[x+1][y-1]==0 || board[x+1][y-1]%2==1)) possibleMoves.push_back((y-1)*8+(x+1));
        if((x < 7 && y < 7) && (board[x+1][y+1]==0 || board[x+1][y+1]%2==1)) possibleMoves.push_back((y+1)*8+(x+1));
    } else{
        if(x > 0 && (board[x-1][y]==0 || board[x-1][y]%2==0)) possibleMoves.push_back(y*8+(x-1));
        if(x < 7 && (board[x+1][y]==0 || board[x+1][y]%2==0)) possibleMoves.push_back(y*8+(x+1));
        if(y > 0 && (board[x][y-1]==0 || board[x][y-1]%2==0)) possibleMoves.push_back((y-1)*8+x);
        if(y < 7 && (board[x][y+1]==0 || board[x][y+1]%2==0)) possibleMoves.push_back((y+1)*8+x);
        if((x > 0 && y > 0) && board[x-1][y-1]%2==0) possibleMoves.push_back((y-1)*8+(x-1));
        if((x > 0 && y < 7) && board[x-1][y+1]%2==0) possibleMoves.push_back((y+1)*8+(x-1));
        if((x < 7 && y > 0) && board[x+1][y-1]%2==0) possibleMoves.push_back((y-1)*8+(x+1));
        if((x < 7 && y < 7) && board[x+1][y+1]%2==0) possibleMoves.push_back((y+1)*8+(x+1));
    }
}