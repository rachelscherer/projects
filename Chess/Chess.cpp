#include "Chess.h"

//Constructor
Chess::Chess(){
    //Dynamically allocate an array of Pieces
    try{
        pieces = new Piece*[32];
        for(int i=0;i<16;i++){pieces[i] = new Pawn(i+1);}
        for(int i=16;i<20;i++) {pieces[i] = new Rook(i+1);}
        for(int i=20;i<24;i++) {pieces[i] = new Knight(i+1);}
        for(int i=24;i<28;i++) {pieces[i] = new Bishop(i+1);}
        for(int i=28;i<30;i++) {pieces[i] = new Queen(i+1);}
        for(int i=30;i<32;i++) {pieces[i] = new King(i+1);}
    } catch(bad_alloc& e){
        cout << "Memory allocation failed: " << e.what() << "\n";
    }
    
    //Initialize the positions in the board array
    for(int i=2;i<6;i++){
        for(int j=0;j<8;j++){
            board[j][i] = 0;
        }
    }
    
    //Initialize the "opponent turn" flag to false
    oppTurn = false;
    
    //Initialize the "game won" flag to false
    gameWon = false;
    
    //Initializes the "check" flag to false for both players
    check[0] = false;
    check[1] = false;
    
    //Set turnNumber to 1
    turnNumber = 1;
    
    //Pawns
    for(int i=0;i<8;i++){
        board[i][6] = pieces[i*2]->getRepVal();
        board[i][1] = pieces[i*2+1]->getRepVal();
    }
    
    //Rooks
    board[0][0] = pieces[17]->getRepVal();
    board[7][0] = pieces[19]->getRepVal();
    board[0][7] = pieces[16]->getRepVal();
    board[7][7] = pieces[18]->getRepVal();
    
    //Knights
    board[1][0] = pieces[21]->getRepVal();
    board[6][0] = pieces[23]->getRepVal();
    board[1][7] = pieces[20]->getRepVal();
    board[6][7] = pieces[22]->getRepVal();
    
    //Bishops
    board[2][0] = pieces[25]->getRepVal();
    board[5][0] = pieces[27]->getRepVal();
    board[2][7] = pieces[24]->getRepVal();
    board[5][7] = pieces[26]->getRepVal();
    
    //Queens
    board[3][0] = pieces[29]->getRepVal();
    board[3][7] = pieces[28]->getRepVal();
    
    //Kings
    board[4][0] = pieces[31]->getRepVal();
    board[4][7] = pieces[30]->getRepVal();
}

//Destructor
Chess::~Chess(){
    //Pointer to an array of pointers, so we need to loop through and delete each element
    for(int i=0;i<32;i++){
        delete pieces[i];
    }
    delete[] pieces;
    pieces = NULL;
}

//Copy constructor
Chess::Chess(const Chess& copy){
    //Copy location of the pieces
    for(int i=7;i>=0;i--){
        for(int j=0;j<8;j++){
            board[j][i] = copy.board[j][i];
        }
    }
    
    //Copy possibleMoves, pieceBank, and moveHistory
    possibleMoves = copy.possibleMoves;
    pieceBank[0] = copy.pieceBank[0];
    pieceBank[1] = copy.pieceBank[1];
    moveHistory = copy.moveHistory;
    
    
    //Copy all flags
    gameWon = copy.gameWon;
    check[0] = copy.check[0];
    check[1] = copy.check[1];
    oppTurn = copy.oppTurn;
    turnNumber = copy.turnNumber;
}

//Operator overloaded constructor
Chess Chess::operator =(const Chess& right){
    if(this==&right) return *this;
    
    for(int i=7;i>=0;i--){
        for(int j=0;j<8;j++){
            board[j][i] = right.board[j][i];
        }
    }
    
    //Copy possibleMoves, pieceBank, and moveHistory
    possibleMoves = right.possibleMoves;
    pieceBank[0] = right.pieceBank[0];
    pieceBank[1] = right.pieceBank[1];
    moveHistory = right.moveHistory;
    
    
    //Copy all flags
    gameWon = right.gameWon;
    check[0] = right.check[0];
    check[1] = right.check[1];
    oppTurn = right.oppTurn;
    turnNumber = right.turnNumber;
    
    return *this;
}

/**
 * Draws the chess board
 */
void Chess::drawBoard(){
    //Call helper functions
    drawCharCoordinate();
    drawLongLine();
    
    //Nested for loops allow me to go through each element of the 2D board array
    for(int i=7;i>=0;i--){
        drawEmptyLines();
        drawEmptyLines();
        
        cout << i+1 << setw(4) << "|"; //Draws the Y coordinate number, then a "   |"
        
        //Iterate through the X coordinate to draw "Opponent" or "Player" for each space
        for(int j=0;j<8;j++){
            if(board[j][i] == 0){
                cout << setw(12); //If it's 0, then just draw an empty space
            } else{
                if(pieces[board[j][i]-1]->isOpponent()) //Check to see if the piece belongs to the player or opponent
                    cout << setw(10) << "Player 2" << setw(2);
                else
                    cout << setw(10) << "Player 1" << setw(2);
            }
            cout << "|";
        }
        
        cout << setw(3) << i+1 << "\n" << setw(5) << "|"; //Draws the end of the line and start of a new line
        
        //Iterate through the X coordinate to draw thew piece names for each space
        for(int j=0;j<8;j++){
            if(board[j][i] == 0)
                cout << setw(12); //If it's 0, then just draw an empty space
            else if(pieces[board[j][i]-1]->getName().length() == 6) //Otherwise, get the piece name and center it
                cout << setw(9) << pieces[board[j][i]-1]->getName() << setw(3);
            else
                cout << setw(8) << pieces[board[j][i]-1]->getName() << setw(4);
            cout << "|";
        }
        cout << "\n";
        drawEmptyLines();
        drawLongLine();
    }
    cout << "\n";
    drawCharCoordinate();
    cout <<"\n(Type 'quit' to exit, /h to display move history, and /p to display captured pieces)\n\n";
}

/**
 * Helper function for drawBoard()
 */
void Chess::drawEmptyLines(){
    cout << setw(5) << "|" << setw(12) << "|" << setw(12)
              << "|" << setw(12) << "|" << setw(12)
              << "|" << setw(12) << "|" << setw(12)
              << "|" << setw(12) << "|" << setw(13) << "|\n";
}

/**
 * Helper function for drawBoard()
 */
void Chess::drawCharCoordinate(){
    cout << setw(11) << "A" << setw(12) << "B"
          << setw(12) << "C" << setw(12) << "D"
          << setw(12) << "E" << setw(12) << "F"
          << setw(12) << "G" << setw(12) << "H\n";
}

/**
 * Helper function for drawBoard()
 */
void Chess::drawLongLine(){
    cout << "     _______________________________________________________________________________________________\n";
}


/**
 * Calls on checkInputValidity(), checkStartValidity(), checkDestinationValidity(), and makeMove()
 * @param input
 * @return 
 */
bool Chess::checkValidity(string& input){
    transform(input.begin(),input.end(),input.begin(),::tolower); //Makes the input lowercase
    if(input == "quit") return true; //Returns to main() if input is "quit"
    if(input == "/h"){
        displayHistory();
        return true;
    }
    if(input == "/p"){
        displayPieceBank();
        return true;
    }
    
    //Checks to see if input is valid
    if(!checkInputValidity(input)) return false;
    
    //Breaks input down into four int values representing the start and destination coordinates
    int x1 = (int)(input[input.find_first_of("abcdefgh")]) - 96;
    int y1 = (int)(input[input.find_first_of("12345678")] - 48);
    int x2 = (int)(input.substr(3,2)[input.find_first_of("abcdefgh")]) - 96;
    int y2 = (int)(input.substr(3,2)[input.find_first_of("12345678")] - 48);
    char x2Ch = (input.substr(3,2)[input.find_first_of("abcdefgh")]);
    
    //Checks to see if start coordinates are valid
    if(!checkStartValidity(x1-1,y1-1)) return false;
    
    //Checks to see if end coordinates are valid
    if(!checkDestinationValidity(x2-1,y2-1)) return false;
    
    //If everything checks out, execute the move
    makeMove(x1-1,y1-1,x2-1,y2-1, x2Ch);
    
    if(gameWon) input = "quit";
    
    return true;
}

/**
 * Checks to see if input is in format "A1-A2" (containing two coordinates and a dash)
 * @param input
 * @return 
 */
bool Chess::checkInputValidity(string input){
    if(input.length()!=5){
        cout << "Error! Coordinate must be five characters long.\n\n";
        return false;
    }
    if(input[2] != '-'){
        cout << "Error! Must be in format D2-D4\n";
        return false;
    }
    
    //Breaks input into two smaller substrings for each coordinate
    string c1 = input.substr(0,2);
    string c2 = input.substr(3,2);
    
    //Breaks those substrings into a char and an integer
    char c1letter = c1[c1.find_first_of("abcdefgh")];
    int c1number = c1[c1.find_first_of("12345678")];
    char c2letter = c2[c2.find_first_of("abcdefgh")];
    int c2number = c2[c2.find_first_of("12345678")];
    
    //If find_first_of couldn't find the required characters, the variable is NULL. Return false if that's the case.
    if (c1letter == 0 || c1number == 0){
        cout << "Error! Start coordinate doesn't exist.\n\n";
        return false;
    }
    
    if (c2letter == 0 || c2number == 0){
        cout << "Error! End coordinate doesn't exist.\n\n";
        return false;
    }
    
    return true;
}

/**
 * Checks to see if start coordinates belong to a space with a piece to move
 * @param x
 * @param y
 * @return 
 */
bool Chess::checkStartValidity(int x, int y){
    //If the board array is 0, return false.
    if(board[x][y] == 0){
        cout << "Error! You must select a coordinate that contains a piece to move.\n\n";
        return false;
    }
 
    if((oppTurn && board[x][y]%2==0) || (!oppTurn && board[x][y]%2==1)){
        cout << "Error! You must select a piece that belongs to you.\n\n";
        return false;
    }
    
    //If the start piece is valid, determine the legal moves the player can make
    getPossibleMoves(x,y);
    
    return true;
}

/**
 * Checks to see if the end coordinates are included in the possibleMoves vector
 * @param x
 * @param y
 * @return
 */
bool Chess::checkDestinationValidity(int x, int y){
    //Searches through the vector
    //y*8+x is an easier way to represent the board coordinates in one dimension, so we're using that
    if(find(possibleMoves.begin(),possibleMoves.end(),(y*8+x)) == possibleMoves.end()){
        cout << "Error! You must select a coordinate that your piece can move to.\n\n";
        return false;   
    }
    
    return true;
}

/**
 * Adds to the possibleMoves vector if the coordinate is empty
 * This will be changed in the final program to call a unique getPossibleMoves()
 * member function belonging to each piece class.
 */
void Chess::getPossibleMoves(int x, int y){
    //We won't consider whether or not a check can be made unless a piece has already been moved
    bool dummy = false;
    pieces[board[x][y]-1]->getPossibleMoves(board, check, possibleMoves, dummy);
}

/**
 * Moves the piece from the start coordinate to the destination coordinate
 * @param x1
 * @param y1
 * @param x2
 * @param y2
 * @param x2Ch
 */
void Chess::makeMove(int x1, int y1, int x2, int y2, char x2Ch){
    int temp = board[x2][y2];
    board[x2][y2] = board[x1][y1];
    board[x1][y1] = 0;
    
    //If already in check, see if the move gets you out of check
    if(check[0]){
        if(getCheckStatus(true)){
            cout << "Error! That won't move player 2 out of check.\n\n";
            board[x1][y1] = board[x2][y2];
            board[x2][y2] = temp;
            return;
        } else{
            check[0] = false;
        }
    } else if(check[1]){
        if(getCheckStatus(false)){
            cout << "Error! That won't move player 1 out of check.\n\n";
            board[x1][y1] = board[x2][y2];
            board[x2][y2] = temp;
            return;
        } else{
            check[1] = false;
        }
    }
    
    //Does the given move put you in check?
    if((oppTurn==true && getCheckStatus(true)) || (oppTurn==false && getCheckStatus(false))){
        cout << "Error! You cannot put yourself in check.\n\n";
        board[x1][y1] = board[x2][y2];
        board[x2][y2] = temp;
        return;
    }
    
    //If it's a valid move, add pieces to pieceBank.
    if(oppTurn && temp!=0){
        pieceBank[1].push_back(pieces[temp-1]->getRepVal());
    } else if(!oppTurn && temp!=0){
        pieceBank[0].push_back(pieces[temp-1]->getRepVal());
    }
    
    //Clear the possibleMoves vector and redraw the board
    possibleMoves.clear();
    cout << "\n";
    drawBoard();
    
    //Does the given move put the other player in check?
    if(oppTurn==true && getCheckStatus(false)) check[1] = true;
    else if(oppTurn==false && getCheckStatus(true)) check[0] = true;
    
    //If the other player is in check, is it actually a checkmate?
    if(check[0] && getCheckMateStatus()){
        cout << "---------Checkmate! Player 1 won the game!---------\n\n";
        gameWon = true;
        return;
    } else if(check[1] && getCheckMateStatus()){
        cout << "---------Checkmate! Player 2 won the game!---------\n\n";
        gameWon = true;
        return;
    }
    
    //********Add to move history (Uses a simplified algebraic notation)********
    int repVal = pieces[board[x2][y2]-1]->getRepVal();
    string turn = "";
    
    //If not pawn, get letter name of piece
    if(repVal >= 17 && repVal <= 20) turn += "R";
    else if(repVal >= 21 && repVal <= 24) turn += "N";
    else if(repVal >= 25 && repVal <= 28) turn += "B";
    else if(repVal == 29 || repVal == 30) turn += "Q";
    else if(repVal == 31 || repVal == 32) turn += "K";
    
    //If piece was captured, append an "x"
    if(temp!=0) turn += "x";
    
    //Append the destination coordinates
    turn += x2Ch + to_string(y2+1);
    
    //If a king was put into check, append a "+";
    if(check[0] || check[1]) turn += "+";
    
    //Add to moveHistory
    if(!oppTurn) moveHistory.push_back(to_string(turnNumber) + ". " + turn + " ");
    else moveHistory.back() += turn;
    
    //Display the check status
    if(check[0]) cout << "---------Player 1 put player 2 in check!---------\n\n";
    else if(check[1]) cout << "---------Player 2 put player 1 in check!---------\n\n";
    
    //Swap turns
    if(oppTurn){
        oppTurn = false;
        turnNumber++;
    }
    else oppTurn = true;
    
}

bool Chess::getOppTurn(){return oppTurn;}

/**
 * When pieceFlag is true, check if player 1's pieces can access the other's king.
 * When pieceFlag is false, check if player 2's pieces can access the other's king. 
 * @param pieceFlag
 * @return 
 */
bool Chess::getCheckStatus(bool pieceFlag){
    //Since we don't need to know what the possibleMoves are for what we're checking, pass through a dummy vector.
    vector<int> tempMoves;
    
    //Flag which lets us determine if a king accessible from a given piece
    bool kPresent = false;
    
    //If we want to check player 2's pieces...
    if(pieceFlag==false){
        
        //Iterate through the board to find their pieces.
        for(int i=7;i>=0;i--){
            for(int j=0;j<8;j++){
                if(board[j][i]%2==1){
                    
                    //For all of player 2's pieces, call getPossibleMoves() to see if they can reach player 1's king.
                    pieces[board[j][i]-1]->getPossibleMoves(board,check,tempMoves,kPresent);
                    
                    //If so, return true
                    if(kPresent){
                        return true;
                    }
                }
            }
        }
        
    //Likewise, we can do the same for player 1's pieces.
    } else{
        for(int i=7;i>=0;i--){
            for(int j=0;j<8;j++){
                if(board[j][i]%2==0 && board[j][i]!=0){
                    pieces[board[j][i]-1]->getPossibleMoves(board,check,tempMoves,kPresent);
                    if(kPresent){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

/**
 * Finds if a check is actually a checkmate by simulating all possible moves and
 * calling getCheckStatus() to see if the king is still able to be reached by opponent
 * @return 
 */
bool Chess::getCheckMateStatus(){
    //Since we're simulating moves, temp will hold the a value from the board in case we need to return to the
    //original state of the board
    int temp;
    
    //If it's player 1's turn, loop through the board and call getPossibleMoves for all of player 2's pieces
    if(!oppTurn){
        for(int i=7;i>=0;i--){
            for(int j=0;j<8;j++){
                if(board[j][i]%2==1){
                    getPossibleMoves(j,i);
                    //Iterate through every possible move player 2 can make
                    for(vector<int>::iterator it = possibleMoves.begin(); it!=possibleMoves.end();++it){
                        //Simulate the given move
                        temp = board[*it%8][*it/8];
                        board[*it%8][*it/8] = board[j][i];
                        board[j][i] = 0;
                        
                        //Call getCheckStatus() for that move. Make it true to see if player 1 can reach king.
                        if(!getCheckStatus(true)){
                            //If player 1 can reach the king, restore the board to its original state
                            board[j][i] = board[*it%8][*it/8];
                            board[*it%8][*it/8] = temp;
                            
                            //There exists a move that will get player 2 out of check, so return false.
                            return false;
                        }
                        
                        //We need to restore the board back to the original state either way.
                        board[j][i] = board[*it%8][*it/8];
                        board[*it%8][*it/8] = temp;
                    }
                    
                    //Clear possibleMoves
                    possibleMoves.clear();
                }
            }
        }
    
    //Do the same for the other player 1's pieces if it's player 2's turn.
    } else{
        for(int i=7;i>=0;i--){
            for(int j=0;j<8;j++){
                if(board[j][i]!=0 && board[j][i]%2==0){
                    getPossibleMoves(j,i);
                    for(vector<int>::iterator it = possibleMoves.begin(); it!=possibleMoves.end();++it){
                        temp = board[*it%8][*it/8];
                        board[*it%8][*it/8] = board[j][i];
                        board[j][i] = 0;
                        if(!getCheckStatus(false)){
                            board[j][i] = board[*it%8][*it/8];
                            board[*it%8][*it/8] = temp;
                            return false;
                        }
                         board[j][i] = board[*it%8][*it/8];
                         board[*it%8][*it/8] = temp;
                    }
                    possibleMoves.clear();
                }
            }
        }
    }
    return true;
}

/**
 * Displays the captured pieces for both players
 */
void Chess::displayPieceBank(){
    cout << "\nPlayer 1's captured pieces:\n";
    if(pieceBank[0].empty()) cout << "Nothing yet!\n";
    else{
        for(vector<int>::iterator it = pieceBank[0].begin(); it!= pieceBank[0].end(); ++it){
            cout << *it << "\n";
        }
    }
    
    cout << "\nPlayer 2's captured pieces:\n";
    if(pieceBank[1].empty()) cout << "Nothing yet!\n";
    else{
        //Iterate through pieceBank[1] vector
        for(vector<int>::iterator it = pieceBank[1].begin(); it!= pieceBank[1].end(); ++it){
            cout << *it << "\n";
        }
    }
    cout << "\n";
}

/**
 * Displays the history of every move in the game.
 */
void Chess::displayHistory(){
    if(turnNumber==1 && !oppTurn) cout << "\nNothing here yet!\n\n";
    else{
        cout << "\n";
        for(vector<string>::iterator it = moveHistory.begin(); it!= moveHistory.end(); ++it){
            cout << *it << "\n";
        }
        cout << "\n";
    }
}