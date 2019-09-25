#include "Rook.h"

void Rook::getPossibleMoves(int (&board)[8][8], bool check[], vector<int>& possibleMoves, bool& kPresent){
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
    
    //While 'y' is held constant, 'trav' will be temporarily testing different x coordinates
    //to see if it's legal for the rook to move there. We will do the same for the y coordinates
    int trav = x;
    
    bool flag = false;
    do{
        //Decrement trav while testing to see it it's out of bounds
        if(--trav < 0) flag = true;
        else{
            if(repVal%2==0){                                                //If the selected piece belongs to player 1...
                if(board[trav][y]%2 == 0 && board[trav][y] != 0){           //...and the next coordinate contains player 1's piece...
                    flag = true;                                            //...end traversal. Don't make space available to move to.
                }else if(board[trav][y]%2 == 1 && board[trav][y] != 0){     //If the next coordinate contains player 2's piece...
                    possibleMoves.push_back(y*8+trav);                      //...end traversal. Make space available to move to.
                    if(board[trav][y]==31) kPresent == true;                //If player 2's king is one of the possible moves, set the "kPresent" flag to true.
                    flag = true;
                }else{
                    possibleMoves.push_back(y*8+trav);                      //Otherwise, the space is empty so it can traverse there.
                }
            } else if(repVal%2==1){                                         //If the selected piece belongs to player 2...
                if(board[trav][y]%2 == 1 && board[trav][y] != 0){           //...and the next coordinate contains player 2's piece...
                    flag = true;                                            //End traversal. Don't make space available to move to.
                }else if(board[trav][y]%2 == 0 && board[trav][y] != 0){     //If the next coordinate contains player 1's piece...
                    possibleMoves.push_back(y*8+trav);                      //...end traversal. Make space available to move to.
                    if(board[trav][y]==32) kPresent = true;                //If player 1's king is one of the possible moves, set the "kPresent" flag to true.
                    flag = true;
                }else{
                    possibleMoves.push_back(y*8+trav);                      //Otherwise, the space is empty so it can traverse there.
                }
            }
        }
    }while(!flag);
    
    //Run the same code as above, but this time increment the x value while holding y constant.
    trav = x;
    flag = false;
    do{
        if(++trav > 7) flag = true;
        else{
            if(repVal%2==0){
                if(board[trav][y]%2 == 0 && board[trav][y] != 0){
                    flag = true;
                }else if(board[trav][y]%2 == 1 && board[trav][y] != 0){
                    possibleMoves.push_back(y*8+trav);
                    if(board[trav][y]==31) kPresent == true;
                    flag = true;
                }else{
                    possibleMoves.push_back(y*8+trav);
                }
            } else if(repVal%2==1){
                if(board[trav][y]%2 == 1 && board[trav][y] != 0){
                    flag = true;
                }else if(board[trav][y]%2 == 0 && board[trav][y] != 0){
                    possibleMoves.push_back(y*8+trav);
                    if(board[trav][y]==32) kPresent = true;
                    flag = true;
                }else{
                    possibleMoves.push_back(y*8+trav);
                }
            }
        }
    }while(!flag);
    
    //Run the same code as above, but this time decrement the y value while holding x constant.
    trav = y;
    flag = false;
    do{
        if(--trav < 0) flag = true;
        else{
            if(repVal%2==0){
                if(board[x][trav]%2 == 0 && board[x][trav] != 0){
                    flag = true;
                }else if(board[x][trav]%2 == 1 && board[x][trav] != 0){
                    possibleMoves.push_back(trav*8+x);
                    if(board[x][trav]==31) kPresent == true;
                    flag = true;
                }else{
                    possibleMoves.push_back(trav*8+x);
                }
            } else if(repVal%2==1){
                if(board[x][trav]%2 == 1 && board[x][trav] != 0){
                    flag = true;
                }else if(board[x][trav]%2 == 0 && board[x][trav] != 0){
                    possibleMoves.push_back(trav*8+x);
                    if(board[x][trav]==32) kPresent = true;
                    flag = true;
                }else{
                    possibleMoves.push_back(trav*8+x);
                }
            }
        }
    }while(!flag);
    
    //Run the same code as above, but this time increment the y value while holding x constant.
    trav = y;
    flag = false;
    do{
        if(++trav > 7) flag = true;
        else{
            if(repVal%2==0){
                if(board[x][trav]%2 == 0 && board[x][trav] != 0){
                    flag = true;
                }else if(board[x][trav]%2 == 1 && board[x][trav] != 0){
                    if(board[x][trav]==31) kPresent = true;
                    possibleMoves.push_back(trav*8+x);
                    flag = true;
                }else{
                    possibleMoves.push_back(trav*8+x);
                }
            } else if(repVal%2==1){
                if(board[x][trav]%2 == 1 && board[x][trav] != 0){
                    flag = true;
                }else if(board[x][trav]%2 == 0 && board[x][trav] != 0){
                    possibleMoves.push_back(trav*8+x);
                    if(board[x][trav]==32) kPresent == true;
                    flag = true;
                }else{
                    possibleMoves.push_back(trav*8+x);
                }
            }
        }
    }while(!flag);
}