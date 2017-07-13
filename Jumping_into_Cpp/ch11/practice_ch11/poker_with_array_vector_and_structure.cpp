// How to build: $clang++ -std=c++11 name_of_program.cpp
// How to build: $gcc -std=c++11 name_of_program.cpp
// How to build: $g++ name_of_program.cpp -o hello
// How to debug: $gdb ./$MY_BINARY_NAME
// You can put a breakpoint by name of function. e.g. b is_royal_flush
// Add to bashrc: alias g++="g++ -g -Wall --std=c++0x"
// Then build $g++ name_of_program.cpp
//

// To use random_shuffle 
#include <algorithm>
 
#include <cstdlib>

// To use std::begin, std::end
#include <iterator>
#include <iostream>

#include <vector>

//
// Play poker
// Provide 5 cards to the player, let player choose new cards
// Round of betting
// Each player may discard up to 3 cards.
// Player with best hand wins. 
// 


// 
//
//
struct PokerCard 
{

    //
    // 14 values in poker:
    // 1-10, Jack(11), Queen(12), King (13), Ace (14)
    //

    std::string card_name;

    int value;

    int number;

    //
    // 4 suits in poker:
    // HEARTS, SPADES, CLUBS, DIAMONDS
    //

    std::string suit_name;

    int suit;

};

//
// ############################################################################# 
//
 
//
// Global deck
//
 
const int deck_size = 52;

const int hand_size = 5;

PokerCard deck[deck_size]; 

//
// ############################################################################# 
//

std::string lookup_card_name(int card_number)
{

    std::string card_name;

    switch ( card_number )
    {
    	case 1:
      	    card_name = " Ace ";
      	    break;
    	case 2:
      	    card_name = " Two ";
      	    break;
    	case 3:
      	    card_name = " Three ";
      	    break;
    	case 4:
      	    card_name = " Four ";
      	    break;
    	case 5:
      	    card_name = " Five ";
      	    break;
    	case 6:
      	    card_name = " Six ";
      	    break;
    	case 7:
      	    card_name = " Seven ";
      	    break;
    	case 8:
      	    card_name = " Eight ";
      	    break;
    	case 9:
      	    card_name = " Nine ";
      	    break;
    	case 10:
      	    card_name = " Ten ";
      	    break;
    	case 11:
      	    card_name = " Jack ";
      	    break;
    	case 12:
      	    card_name = " Queen ";
    	    break;
    	case 13:
      	    card_name = " King ";
    	    break;

	default:
      	    std::cout << "Error: Bad input. Quitting\n" << std::endl;
      	    break;

    }

    return card_name;

}

std::string lookup_suit(int number)
{
    std::string suit_name;

    switch(number)
    {
        case 1:
            suit_name = "HEARTS";
            break;
        case 2:
            suit_name = "SPADES";
            break;
        case 3:
            suit_name = "CLUBS";
            break;
        case 4:
            suit_name = "DIAMONDS";
            break;

        default:
            std::cout << "Error: I don't know how to write this input \n" << std::endl;
            break;
    }

    return suit_name;
}


void fill_a_deck()
{

       //
       // Index for each card ( 52 total )
       //

       int idx = 0;
       
       int current_suit    = 0;

       int current_number  = 0;

       int current_value   = 0;


       //
       // Fill out suit ( 4 suits )
       //

       for(int ii = 0; ii < 4; ++ii)
       {

           // 
           // Fill out numbers ( 13 cards )
           //

           for(int jj = 0; jj < 13; ++jj)
           {

               idx = jj + ii*13;

               //
               // Array indexing starts at 0, start at 1 to be intuitive
               //

               current_suit  = ii + 1;

               current_number = jj + 1;

               if( current_number == 1)
               {

                   current_value = 14;

               }
               else
               {
               
                   current_value = current_number; 

               }

               deck[idx].number = current_number;

               deck[idx].value = current_value;

               deck[idx].card_name = lookup_card_name(current_number);

               deck[idx].suit = current_suit; 

               deck[idx].suit_name = lookup_suit(current_suit); 

           }

       }

}

int ask_user(std::string message)
{
    int input = 0;

    std::cout << message << "\n";

    std::cin >> input;

    return input;
}

void print_cards_held(int a[])
{

    for(int ii = 0; ii < 5; ++ii)
    {

        std::cout << "Card " 
                  << ii + 1
                  << ". " 
	          << deck[ a[ii] ].card_name 
                  << deck[ a[ii] ].suit_name 
                  << " with value " 
	          << deck[ a[ii] ].value 
                  << std::endl;        

    }

}

void play_discard_option(int arr[], int top_of_deck_idx, std::vector <int>& deck_idx)
{
    int discard_pick = 0;

    for(int ii = 0; ii < 3; ++ii)
    {

        discard_pick = ask_user(" Pick a discard 1-5, or 0 for none ");        

        //TODO: Can you discard cards you have drawn?
        if( discard_pick !=0 && discard_pick < 6)
        {
            // Because array index start a 0 but humans count starting at 1
            discard_pick--;

            // Update the hand with a new card from the top of the deck
            arr[discard_pick] = deck_idx.at(top_of_deck_idx);

            // Because we took the top of the deck
            top_of_deck_idx++;
        }

    } 

}

//
// Input: non-empty array of max size of 5 ints, with possible values 1-13 
// Output: true if all suit values are the same
//
bool are_all_same_value(int a[], int n)
{
    
    int value_check = 0;
   
    value_check = deck[ a[0] ].value;

    bool are_all_same = true;

    for(int ii = 1; ii < n; ++ii)
    {

        if(value_check != deck[ a[ii] ].value )
        {

             are_all_same = false;

        }

    }

    return are_all_same;
    
}

//
// Input: non-empty array of max size of 5 ints, with possible values 1-4
// Output: true if all suit values are the same
//
bool are_all_same_suit(int a[], int n)
{

    //
    // An array is passed as a pointer.
    // We must pass the size to determine the number of elements in the array
    //
    
    int suit_check = 0;
   
    suit_check = deck[ a[0] ].suit;

    bool are_all_same = true;

    for(int ii = 1; ii < n; ++ii)
    {

        if(suit_check != deck[ a[ii] ].suit )
        {

             are_all_same = false;

        }

    }

    return are_all_same;

}

//
// Adds up the values of the suits.
// Exception is Ace, value of 1 becomes 14
//
int sum_all_values(int a[], int n)
{

    int sum_value = 0;

    for(int ii = 0; ii < n; ++ii)
    {
    
        if(deck[ a[ii] ].value == 1)
        {
     
            sum_value += 14;

        }
        else
        {
   
            sum_value += deck[ a[ii] ].value;
    
        }
  
    }

    return sum_value;
}

bool is_royal_flush(int a[], int sz_a)
{

    bool is_same_suit = false;

    int royal_flush_value = 0;

    is_same_suit = are_all_same_suit(a, sz_a);

    royal_flush_value = sum_all_values(a, sz_a);

    //
    // 1. Same suit
    // 2. 10, J(11), Q(12), K(13), A(14), total value of 60
    //
    if(is_same_suit && royal_flush_value == 60)
    {
    
    	return true;

    }
    else
    {
    
        return false;
    
    }

}

int find_index_of_highest_value_card(int a[], int n)
{

    int index_highest_value_card = 0;

    for(int ii = 0; ii < n; ++ii)
    {

	if( deck[ a[ii] ].value > deck[ a[index_highest_value_card] ].value )
	{

	    index_highest_value_card = ii;

	}
	
    }
    
    return index_highest_value_card;

}

int find_index_of_lowest_number_card(int a[], int n)
{

    int index_lowest_number_card = 0;

    for(int ii = 0; ii < n; ++ii)
    {

	if( deck[ a[ii] ].number < deck[ a[index_lowest_number_card] ].number )
	{

	    index_lowest_number_card = ii;

	}
	
    }
    
    return index_lowest_number_card;

}

//
// Input: Sorted deck
//
bool is_ace_high_straight(int a[], int sz_a)
{

    int max_idx = find_index_of_highest_value_card(a, sz_a);

    //
    // If the King is the highest value, then Ace must have a value of 14
    // Skip the Ace.
    // Highest possible is A (14), K (13), Q (12), J(11), 10 'Ace high flush' 
    //
    if( deck[ a[max_idx] ].value == 14)
    {

        int counter = 10;

        // Skip Ace by starting at 1 
        for(int ii = 1 ; ii > 0; --ii)
        {
        
            if( deck[ a[ii] ].value == counter )
            {
        
                counter++;
                
            }
            else
            {
        
                return false;
         
            }

         }

         return true;

    }
    else
    {

         return false;

    }

}

//
// Input: Sorted deck array with non-zero cards
//
bool is_straight(int a[], int sz_a)
{

    // Ace may be the highest or the lowest of the sequence
    // Lowest possible is  5, 4, 3, 2, A (1)  'Five high flush'

    // TODO: Same as find smallest in sort
    int min_idx = find_index_of_lowest_number_card(a, sz_a);

    int counter = deck[ min_idx ].number;

    //
    // In case you have an Ace and it is actually the highest valued card
    //

    bool is_special_case = is_ace_high_straight(a, sz_a);

    if( is_special_case )
    {  

       return true; 

    }
    else
    {

        for(int ii = 0; ii < sz_a; ++ii)
        {

            //
            // Check against the ordered deck with Ace being low (1)
            //
    
            if( deck[ a[ii] ].number == counter )
            {
    
                counter++;
            
            }
            else
            {
    
     	        return false;
     
            }
    
        }
    
        return true;

    }

}

//
// In: array with a size (assuming 5)
// Out: true if it's a straight flush  
//
bool is_straight_flush(int a[], int sz_a)
{

    bool is_same_suit = false;

    bool is_straight_values  = false;

    is_same_suit = are_all_same_suit(a, sz_a);

    is_straight_values = is_straight(a, sz_a);

    //
    // 1. Same suit
    // 2. In order. Lowest possible is A, 2, 3, 4, 5 
    //
    if(is_same_suit && is_straight_values)
    {
    
    	return true;

    }
    else
    {
    
        return false;
    
    }

}

//
// In: two arrays representing two players with non-zero number of cards
// Out: 1 if the first array's high value card is higher
//      2 if the second array's high value is higher
//      0 if they tie
//

int compare_max_values(int a[], int b[], int size)
{

    int a_max_idx = find_index_of_highest_value_card(a, size);

    int b_max_idx = find_index_of_highest_value_card(b, size);

    if (deck[a[a_max_idx]].value == deck[b[b_max_idx]].value)
    {

        return 0;

    }
    else if (deck[a[a_max_idx]].value > deck[b[b_max_idx]].value)
    {

        return 1;

    }
    else 
    {
        return 2;
    }   

}

//
// ############################################################################# 
//

//
// Copied insertion sort example from book.
//

//
// INSERTION SORT: Finds smallest element and puts in in the front.
// Finds the second smallest element and puts it after the first one found,
// and so on 
//

//
// Functions to swap and find smallest element
//
int findSmallestRemainingElement (int array[], 
				  int size,
                                  int index)
{

    int index_of_smallest_value = index;

    // Loops until it finds a value smaller 
    // than the previous smallest value 
    for(int ii = index + 1; ii < size; ++ii)
    {

        // Compares card values because I need the order to find straights
	if( deck[ array[ii] ].value < deck[ array[index_of_smallest_value] ].value )
	{

	    index_of_smallest_value = ii;

	}
	
    }
    
    return index_of_smallest_value;

}

void swap (int array[],
           int first_index,
           int second_index)
{

    int temp = array[ first_index ];

    array[first_index] = array[second_index];

    array[second_index] = temp; 

} 

void sort (int array[], int size)
{

    for(int ii = 0; ii < size; ++ii)
    {
	int index = findSmallestRemainingElement(array, 
                                                 size, 
                                                 ii);
        swap(array, ii, index);	
    }

}

//
// ############################################################################# 
//

int main()
{


    fill_a_deck();
    
    // 
    // Create a random list of 52 (0-51) numbers to serve as the index to draw from the deck
    //

    std::vector<int> deck_idx( deck_size );

    std::iota(deck_idx.begin(), deck_idx.end(), 0);

    std::random_shuffle( std::begin(deck_idx), std::end(deck_idx) );

    //
    // Print randomized indexes 
    //

    for (std::vector<int>::const_iterator ii = deck_idx.begin(); ii != deck_idx.end(); ++ii)
    {
   
        std::cout << *ii << ' '; 

    }

    std::cout <<"Hi! Let's play poker.\n"
              <<"Here are your cards. Mine are hidden. \n";

    //
    // The first 5 cards are the players, the second 5 cards are the opponents 
    //
    int player_cards [] = { 
                               deck_idx.at(0), 
                               deck_idx.at(1), 
                               deck_idx.at(2), 
                               deck_idx.at(3), 
                               deck_idx.at(4), 
                            };

    int opponent_cards [] = { 
                               deck_idx.at(5), 
                               deck_idx.at(6), 
                               deck_idx.at(7), 
                               deck_idx.at(8), 
                               deck_idx.at(9), 
                            };
        
//    int top_of_deck_index = 10;


    //
    // Sorted indexes correspond to the ordered deck
    //
    sort( player_cards, hand_size );

    sort( opponent_cards, hand_size );

    std::cout << " Player cards... " << std::endl;

    print_cards_held( player_cards );

    std::cout << " Opponent cards... " << std::endl;

    print_cards_held( opponent_cards );

    std::cout << "You may now discard up to 3 cards. \n"; 

//    play_discard_option(player_cards, top_of_deck_index, deck_idx);

    print_cards_held( player_cards );

//
// ############################################################################# 
//
    bool test_true_1  = false;

    bool test_true_2  = false;

    bool test_false   = true;

    int  test_value   = 0;

    //
    // The Royal flush starts at 10 hearts, and ends with ace hearts
    //

    int test_royal_flush [] = { 9, 10, 11, 12, 0 }; 

    int test_suit_pair   [] = { 9, 10 }; 

    int test_value_pair  [] = { 0, 13 }; 

    //
    // These have different suits all in disorder
    //

    int test_straight_high_five []   = { 39 , 40, 2, 3, 30 }; 

    int test_straight_ace_high []    = { 39 , 9, 10, 11, 12 }; 

    //
    // These have the same suits
    //

    int test_straight_flush []       = { 0 , 1, 2, 3, 4 }; 

    std::cout << " Testing... " << std::endl;

    print_cards_held( test_straight_high_five );

    // 
    // It is better to use vectors b/c arrays are passed as pointers
    // I also did not want to use global variables.
    //

    test_true_1  = are_all_same_suit( test_suit_pair, 2 );

    test_true_2  = are_all_same_value( test_value_pair, 2 );

    test_false   = are_all_same_value( test_suit_pair, 2 );

    std::cout << "Should be true: " << test_true_1 << "\n";

    std::cout << "Should be true: " << test_true_2 << "\n";

    std::cout << "Should be false: " << test_false << "\n";

    test_value   = sum_all_values( test_royal_flush, hand_size );

    test_true_1  = is_royal_flush( test_royal_flush, hand_size );

    std::cout << "Should be true: " << test_true_1 << "\n Value "  
              << test_value << "\n";

    int result_index = 0;

    int nn = 0;
    
    result_index = find_index_of_highest_value_card( test_royal_flush, hand_size );

    std::cout << "Value of highest value card: " 
              << deck[test_royal_flush[result_index]].value  << "\n";

    result_index = find_index_of_lowest_number_card( test_royal_flush, hand_size );

    std::cout << "Value of lowest number card: " 
              << deck[test_royal_flush[result_index]].value  << "\n";

    test_true_1  = is_straight( test_straight_high_five, hand_size );

    test_true_2  = is_straight( test_straight_ace_high, hand_size );

    std::cout << "Should be true: " << test_true_1 << "\n";

    std::cout << "Should be true: " << test_true_2 << "\n";

    test_true_1 = is_straight_flush( test_straight_flush, hand_size );

    test_false  = is_straight_flush( test_straight_ace_high, hand_size );

    std::cout << "Should be true: " << test_true_1 << "\n";

    std::cout << "Should be false: " << test_false << "\n";

    nn = compare_max_values(test_value_pair, test_suit_pair , 2);

    std::cout << "Should be 1: " << nn << "\n";

    nn = compare_max_values(test_suit_pair, test_value_pair , 2);

    std::cout << "Should be 2: " << nn << "\n";

    nn = compare_max_values(test_value_pair, test_value_pair , 2);

    std::cout << "Should be 0: " << nn << "\n";

//
// ############################################################################# 
//
    //
    // Who won?
    // In poker, Ace (14) > King (13) > Queen (12) > Jack (11), 10,..., 2
    //

    // Player with the highest ranked card wins
    // 1. Royal flush     
    // 2. Straight flush     
    // 3. Straight     
    // 4. 2 and 3 pairs 
    // 5. Pairs 
    // 6. High Value     



}

