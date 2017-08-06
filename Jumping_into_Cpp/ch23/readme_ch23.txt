Hiding the Representation of Structure Data

- One very common place to hide data is when making a structure.
- "Isn't the whole point of a structure to provide some particular pieces of data?
   Why hide the representation?"

- You need to think of data structures in another different way:

- Most of the time, when you have a bunch of data, what really matters
  is not so much how you store the data, but what you can do with that data.

- WHAT MATTERS ISN'T HOW YOU STORE THE DATA BUT HOW YOU USE THE DATA.

Example: The string

- Unless you are implementing the string class, it doesn't really matter how 
  the string is stored.

- For code that uses strings they care how to get the lenght of the string, 
  access individual characters, display the string.

- E.g. maybe they use arrays, maybe linked list, we don't care!

- E.g. C++ string has 35 things you can do with it!

- You don't need most of them most of the time.

- What you want is the ability to create new data types without having to expose the raw data
  that is used to implement the data type.

- E.g. You don't need to worry about the buffer that holds a string when you create a string.

- STL vectors & maps work like this, you don't need to know you have to feed carrots to rabbits to make it work.


Using functions to hide the layout of a structure.

- E.g. chess board that represents the board and whose move it is:

--------------------------- 
enum ChessPiece 
{
    EMPTY_SQUARE,
    WHITE_PAWN
    /* and others */

}

enum PlayerColor 
{
    PC_WHITE, 
    PC_BLACK
}; 

struct ChessBoard
{

    ChessPiece baord [8][8];
    PlayerColor whose_move;
};

--------------------------- 

ChessPiece getPiece ( const ChessBoard *p_board,
                      int x,
                      int y)
{
    return p_board->board[x][y];
}

PlayerColor getMove ( const ChessBoard *p_board)
{
    return b_board-> whose_move;
}

void makeMove ( ChessBoard* p_board,
                int from_x,
                int from_y,
                int to_x,
                int to_y
               )
{

    //
    // Normally we'd want code that avlides the move first
    // 
    p_board-> board[ to_x ][ to_y ] = 
              p_board->[ from_x ][ from_y ];

    p_board->[ from_x ][ from_y ] = EMPTY_SQUARE;

}
     
// Initialize board.

ChessBoard b;

// Use the board

getMove( &b );

// move a piece from 0,0 to 1,0

makeMove( &b, 0, 0, 1, 0)

- A fine approach, C programmers used this approach for years!!
- However, all these functions are only associated with the ChessBoard structure b/c they
  happen to take it as an argument.
- This would say " This function should be considered core part of this structure "

- What if the structure didn't just contain data, but also the way to manipulate data?

---------------------------------
Vocab (C++)

- method = a function declared to be part of a structure.

Declare the method as a part of the structure, which directly ties the methods to the structure.

- Unlike free floating functions, methods can operate on the data stored on the structure.
- This way, the method called doesn't need to pass the structure as a separate argument!!

Method Syntax:

see method.cpp

-------------------------------

- Since it can be messy to define all functions inside the structure...
  you can take them outside!

  Super Special Scoping Syntax: <structure name> :: < method name >

  Just declare the functions and then define them outside with the scoping syntax.

  See method_scoping_outside_struct.cpp 

  For the rest of the book, we will split up the 'declaration' and 'definition' of 
  any method longer than a few lines.

  Some people argue to never expose your method implementation b/c it makes it more 
  likely that someone will write code that depends on the exact details of the implementation.

  This book does it to save space.










