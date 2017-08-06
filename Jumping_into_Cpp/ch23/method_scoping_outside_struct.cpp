//
// This shows an example of a 'method'
// inside a struct.
// Methods allow you to use the structure data 
// without having to pass it to it.
//

#include <iostream>

//
//
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


struct ChessBoard
{

    ChessPiece board [8][8];

    PlayerColor whose_move;
 
    // Function declaration + definition is in this struct
    PlayerColor getMove ()
    {
        return whose_move;
    }

    // Function declaration only, definition is outside 
    ChessPiece getPiece (int x,
                         int y);

    // Function declaration only, definition is outside 
    void makeMove (int from_x,
                   int from_y,
                   int to_x,
                   int to_y);
};

// 
// These two are function definitions for the struct.
//
ChessPiece ChessBoard::getPiece (int x,
                                 int y)
{
    return board[x][y];
}

void ChessBoard::makeMove (int from_x,
                           int from_y,
                           int to_x,
                           int to_y)
{

    //
    // Normally we'd want code that avlides the move first
    // 
    board[ to_x ][ to_y ] = 
            board[ from_x ][ from_y ];

    board[ from_x ][ from_y ] = EMPTY_SQUARE;

}


int main()
{

    //
    // How does the method know which instance of teh structure to work on?
    // Calling a function associate with the structure looks almost
    // exactly like accessing a field of the structure.
    //
    ChessBoard b;

    b.getMove();

    /* The compiler is handling the details of letting the method access the data in the structure the method was called on.

    Conceptually, the <variable>.<method> syntax is a shorthand for passing <variable> to <method>.

    Now you know why we need this syntax in the chapter on STL. The functions worked like these methods. (Ch 18)

    */

}
