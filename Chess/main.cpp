/* 
 * File:   main.cpp
 * Author: rachel
 *
 * Created on September 30, 2018, 6:56 PM
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "Chess.h"

//Function prototypes
bool validateInput(string);
void displayRules();

int main(int argc, char** argv){
    string input;
    char temp = 'x';
    do{
        cout << "------------Welcome to terminal chess!------------\n";
        cout << "Please select from one of the following options:\n\n";
        cout << "1. Play chess game.\n";
        cout << "2. Read the rules.\n\n";
        
        do{ 
            cout << "Please type a number: ";
            cin >> input;
        }while(!validateInput(input));

        cout << "\n";

        if(input=="2"){
            displayRules();
            cout << "Press any key then enter to continue: ";
            cin >> temp;
            //I would just say to press enter and use cin.get(), but my terminal emulator doesn't
            //send anything to the program unless there's a whole line of input. I tried setting my
            //emulator in non-canonical mode but now I can't backspace. Can't find a solution online.
            //...It's a weird unix thing. Fix later?
            cout << "\n";
        }  
    }while(input=="2");

    if(input=="1"){
        Chess session;
        session.drawBoard();
        
        while(input != "quit"){
            do{
                if(!session.getOppTurn()) cout << "PLAYER 1:\n";
                else cout << "PLAYER 2:\n";
                cout << "Please enter your move using format A2-A3: ";
                cin >> input;
            }while(!session.checkValidity(input));
        }
    }
    
    return 0;
}

bool validateInput(string input){
    if(!isdigit(input[0])){
        cout << "Error! Must type a number.\n";
        return false;
    }
    if(input != "1" && input != "2"){
        cout << "Error! You must select a valid option!\n";
        return false;
    }
    return true;
}

void displayRules(){
    cout << "If you want to know the general rules of chess, please visit this link: https://www.chess.com/learn-how-to-play-chess\n\n";

    cout << "How to move:\n";
    cout << "Type the coordinates of the piece you'd like to move, followed by a dash (-), then the coordinates of where'd you like to move to. (ex: A2-A4).\n\n";
    cout << "Other inputs:\n";
    cout << "Type 'quit' at any time during the game to exit the program.\n";
    cout << "You can also type /c to castle, /h to display the move history and /p to display the captured pieces\n\n";
    cout << "Things not included in this version: Castling, en passant, pawn promotion, and recognition of stalemates.\n\n";
    cout << "The game is won when one player puts the other in checkmate. Enjoy!\n\n";
}