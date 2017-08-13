
#include <string>
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

    //
    // Overloaded constructor
    //
    // You can have multiple constructors overloaded by argument type 
    // A constructor can take any number of arguments
    //
    ChessBoard( int board_size ); // <-- no return value at all

    PlayerColor getMove();

    ChessPiece getPiece(int x, int y);

    void makeMove( int from_x,
                   int from_y,
                   int to_x,
                   int to_y);

private:

    ChessPiece _board[8][8];

    PlayerColor _whose_move;

    int _move_count;

    const int _val;

    std::string _my_board_name;

};

//
// Constructor
//
ChessBoard::ChessBoard() // <-- still no return value
      //
      // The colon is followed by the list of variables
      // with the argument to the constructor
      // E.g. at this point _my_board_name constructor has been called
      // and it contains the value "white" 
      // E.g. _val is a const, so it MUST be initialized in the 'init list'
      // 'INITIALIZATION LIST'
      //
      : _my_board_name("white")
      , _move_count( 0 )
      , _val( 0 )
{

    //
    // You could do this...
    // The actual code that executes here might be surprising.
    // The constructor for _my_board_name will be called.
    // It's good b/c you can safely use any of your class's fields in the constructor
    //  
    // but you can pass arguments to the constructor of a class member, if you want,
    // rather than having the default constructor run. 
    // (See above)
    //
    //  _my_board_name = "banana";

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

//
// Constructor overloaded 
//
ChessBoard::ChessBoard( int board_size ) // <-- still no return value
      : _val( 0 )  // Must be initialized like this b/c it's const
{

}

int main()
{

    //
    // The constructor is called on the very line where you create the object.
    //
    ChessBoard a;

    //
    // Since there are 2, the constructors are in the order the objects are declared, a then b 
    //
    ChessBoard b;

    //
    // ChessBoard constructor is also called as part of memory allocation
    //
    ChessBoard *p_board_1 = new ChessBoard;

    //
    // ChessBoard constructor that can accept arguments 
    //
    ChessBoard c(8);

    //
    // ChessBoard constructor dynamically allocated 
    //
    ChessBoard *p_board_2 = new ChessBoard( 8 );

    //
    // Note on syntax: No parenthesis needed when declaring an object with a no-argument constructor. 
    //
    // ChessBoard board();                   // BAD CODE..that compiles >_<
    // ChessBoard *board = new ChessBoard(); // OK to use parenthesis 

} 

