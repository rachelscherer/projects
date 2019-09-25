#include "Queen.h"

void Queen::getPossibleMoves(int (&board)[8][8], bool check[], vector<int>& possibleMoves, bool& kPresent){
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
    
    /**
     * NOTE - since a queen is essentially a bishop combined with a rook we will reuse that code.
     */

    //******************ROOK FUNCTIONALITY******************
    
    int trav = x;
    bool flag = false;
    do{
        //Decrement trav while testing to see it it's out of bounds
        if(--trav < 0) flag = true;
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
    
    //******************BISHOP FUNCTIONALITY******************
    
    //Down and to the left
    trav = 0;
    flag = false;
    do{
        trav++;
        if(x-trav < 0 || y-trav < 0) flag = true;
        else{
            if(repVal%2==0){
                if(board[x-trav][y-trav]%2 == 0 && board[x-trav][y-trav] != 0){
                    flag = true;
                }else if(board[x-trav][y-trav]%2 == 1 && board[x-trav][y-trav] != 0){
                    possibleMoves.push_back((y-trav)*8+(x-trav));
                    if(board[x-trav][y-trav]==31) kPresent = true;
                    flag = true;
                }else{
                    possibleMoves.push_back((y-trav)*8+(x-trav));
                }
            } else if(repVal%2==1){                                       
                if(board[x-trav][y-trav]%2 == 1 && board[x-trav][y-trav] != 0){    
                    flag = true;                                                  
                }else if(board[x-trav][y-trav]%2 == 0 && board[x-trav][y-trav] != 0){   
                    possibleMoves.push_back((y-trav)*8+(x-trav));                      
                    if(board[x-trav][y-trav]==32) kPresent = true;                    
                    flag = true;
                }else{
                    possibleMoves.push_back((y-trav)*8+(x-trav));
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