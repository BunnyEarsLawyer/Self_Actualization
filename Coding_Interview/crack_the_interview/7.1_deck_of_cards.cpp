#include<iostream>
#include <list>
/*
Deck of Cards

Design the data structure for a generic deck of cards.

How would you subclass the data structures to implement blackjack.
*/ 

using namespace std;

enum Suit
{
   // Automatically numbered from 0 to 3
   HEART,
   CLOVER,
   DIAMOND,
   SPADE
};

struct Card
{
    int value;
    string symbol;
};
 
// This class represents a directed graph using
// adjacency list representation
class Deck 
{
 
    list<Card> cards;   
    int number_of_cards;

public:
    Deck();
    
};

// Constructor 
Deck::Deck()
{
   //
   // Create 52 cards, values 1-13, 4 suits
   // and add those cards to the list
   //

}

// Subclass

int main()
{

    return 0;
}
