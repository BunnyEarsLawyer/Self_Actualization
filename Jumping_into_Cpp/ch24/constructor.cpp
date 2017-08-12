
#include <iostream>

//
// Sample Constructor 
//

enum ChessPiece 
{

    EMPTY_SQUARE,

    WHITE_PAWN

    /* and others */

};

enum PlayerColor 
{

    PC_WHITE, 

    PC_BLACK

}; 


class ChessBoard
{

public:

    //
    // Notice the constructor is part of the public section
    // If it weren't then no intances of ChessBoard object could 
    // be created. Why? 
    // B/c the constructor must be called anytime the object is created.
    // If it were private, notoby outside the class could call the constructor. 
    //

    //
    // The constructor 
    //
    ChessBoard(); // <-- no return value at all

    PlayerColor getMove();

    ChessPiece getPiece(int x, int y);

    void makeMove( int from_x,
                   int from_y,
                   int to_x,
                   int to_y);

private:

    ChessPiece _board[8][8];

    PlayerColor _whose_move;

};

ChessBoard::ChessBoard() // <-- still no return value
{

    _whose_move = PC_WHITE;
    //
    // start off by emptying the whole board
    // then fill it in with pieces
    //
    for( int i = 0; i < 8; ++i )
    {

        for( int j = 0; j < 8; ++j )
        {

            _board[i][j] = EMPTY_SQUARE;

        }

    }
    // Other code to intialize the board...

}

int main()
{

    //
    // The constructor is called on the very line where you create the object.
    //
    ChessBoard b;

    //
    // ChessBoard constructor is also called as part of memory allocation
    //
    ChessBoard *board = new ChessBoard;
} 

