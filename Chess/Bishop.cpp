#include "Bishop.h"

void Bishop::getPossibleMoves(int (&board)[8][8], bool check[], vector<int>& possibleMoves, bool& kPresent){
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
    
    //Trav will be number added to and subtracted from the x and y coordinates to get the diagonals
    //(x+trav,y+trav) - Traverses up and right
    //(x-trav,y+trav) - Traverses up and left
    //(x-trav,y-trav) - Traverses down and left
    //(x+trav,y-trav) - Traverses down and right
    int trav = 0;
     
    //Down and to the left
    bool flag = false;
    do{
        trav++;
        //Makes sure the coordinates don't go out of bounds
        if(x-trav < 0 || y-trav < 0) flag = true;
        else{
            if(repVal%2==0){                                                            //If the selected piece belongs to player 1...
                if(board[x-trav][y-trav]%2 == 0 && board[x-trav][y-trav] != 0){         //...and the next coordinate contains player 1's piece.
                    flag = true;                                                        //...end traversal. Don't make space available to move
                }else if(board[x-trav][y-trav]%2 == 1 && board[x-trav][y-trav] != 0){   //If the next coordinate contains player 2's piece...
                    possibleMoves.push_back((y-trav)*8+(x-trav));                       //...end traversal. Make space available to move.
                    if(board[x-trav][y-trav]==31) kPresent = true;                     //If player 2's king is one of the possible moves, set the "kPresent" flag to true.
                    flag = true;
                }else{
                    possibleMoves.push_back((y-trav)*8+(x-trav));                       //Otherwise, the space is empty so it can traverse there.
                }
            } else if(repVal%2==1){                                                     //If the selected piece belongs to player 2...
                if(board[x-trav][y-trav]%2 == 1 && board[x-trav][y-trav] != 0){         //...and the next coordinate contains player 2's piece...
                    flag = true;                                                        //...end traversal. Don't make space available to move
                }else if(board[x-trav][y-trav]%2 == 0 && board[x-trav][y-trav] != 0){   //If the next coordinate contains player 1's piece...
                    possibleMoves.push_back((y-trav)*8+(x-trav));                       //...end traversal. Make space available to move.
                    if(board[x-trav][y-trav]==32) kPresent = true;                      //If player 1's king is one of the possible moves, set the "kPresent" flag to true.
                    flag = true;
                }else{
                    possibleMoves.push_back((y-trav)*8+(x-trav));                       //Otherwise, the space is empty so it can traverse there.
                }
            }
        }
    }while(!flag);
    
    //Up and to the right
    trav = 0;
    flag = false;
    do{
        trav++;
        if(x+trav > 7 || y+trav > 7) flag = true;
        else{
            if(repVal%2==0){
                if(board[x+trav][y+trav]%2 == 0 && board[x+trav][y+trav] != 0){
                    flag = true;
                }else if(board[x+trav][y+trav]%2 == 1 && board[x+trav][y+trav] != 0){
                    possibleMoves.push_back((y+trav)*8+(x+trav));
                    if(board[x+trav][y+trav]==31) kPresent = true;
                    flag = true;
                }else{
                    possibleMoves.push_back((y+trav)*8+(x+trav));
                }
            } else if(repVal%2==1){
                if(board[x+trav][y+trav]%2 == 1 && board[x+trav][y+trav] != 0){
                    flag = true;
                }else if(board[x+trav][y+trav]%2 == 0 && board[x+trav][y+trav] != 0){
                    possibleMoves.push_back((y+trav)*8+(x+trav));
                    if(board[x+trav][y+trav]==32) kPresent = true;
                    flag = true;
                }else{
                    possibleMoves.push_back((y+trav)*8+(x+trav));
                }
            }
        }
    }while(!flag);
    
    //Up and to the left
    trav = 0;
    flag = false;
    do{
        trav++;
        if(x-trav < 0 || y+trav > 7) flag = true;
        else{
            if(repVal%2==0){
                if(board[x-trav][y+trav]%2 == 0 && board[x-trav][y+trav] != 0){
                    flag = true;
                }else if(board[x-trav][y+trav]%2 == 1 && board[x-trav][y+trav] != 0){
                    possibleMoves.push_back((y+trav)*8+(x-trav));
                    if(board[x-trav][y+trav]==31) kPresent = true;
                    flag = true;
                }else{
                    possibleMoves.push_back((y+trav)*8+(x-trav));
                }
            } else if(repVal%2==1){
                if(board[x-trav][y+trav]%2 == 1 && board[x-trav][y+trav] != 0){
                    flag = true;
                }else if(board[x-trav][y+trav]%2 == 0 && board[x-trav][y+trav] != 0){
                    possibleMoves.push_back((y+trav)*8+(x-trav));
                    if(board[x-trav][y+trav]==32) kPresent = true;
                    flag = true;
                }else{
                    possibleMoves.push_back((y+trav)*8+(x-trav));
                }
            }
        }
    }while(!flag);
    
    //Down and to the right
    trav = 0;
    flag = false;
    do{
        trav++;
        if(x+trav > 7 || y-trav < 0) flag = true;
        else{
            if(repVal%2==0){
                if(board[x+trav][y-trav]%2 == 0 && board[x+trav][y-trav] != 0){
                    flag = true;
                }else if(board[x+trav][y-trav]%2 == 1 && board[x+trav][y-trav] != 0){
                    possibleMoves.push_back((y-trav)*8+(x+trav));
                    if(board[x+trav][y-trav]==31) kPresent = true;
                    flag = true;
                }else{
                    possibleMoves.push_back((y-trav)*8+(x+trav));
                }
            } else if(repVal%2==1){
                if(board[x+trav][y-trav]%2 == 1 && board[x+trav][y-trav] != 0){
                    flag = true;
                }else if(board[x+trav][y-trav]%2 == 0 && board[x+trav][y-trav] != 0){
                    possibleMoves.push_back((y-trav)*8+(x+trav));
                    if(board[x+trav][y-trav]==32) kPresent = true;
                    flag = true;
                }else{
                    possibleMoves.push_back((y-trav)*8+(x+trav));
                }
            }
        }
    }while(!flag);
}