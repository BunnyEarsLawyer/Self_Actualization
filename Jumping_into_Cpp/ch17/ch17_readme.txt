Binary Trees
Why do I need binary trees?
- B/c w/ Linked Lists it can take a long time to find things.  
- Even arrays don't help if the data is just one big long list w/out any structure.
  And it's difficult to insert to the array.
- Looking up things quickly is very important.

E.g.
- MMORPG, allow players to quickly sign into the game. Look up the player quickly.
- Credit cards, millions of transactions. Find the account balance quickly.
- Low-power device, like smartphone, display address book quickly.

- Use pointers but in a way that's easier to search for values.
- Give structure.

What is a binary tree?
- Sophisticated memory structure.
- It can hold more than one next node at a time.
- You have 2 next nodes.
- There are at most 2 branches from each node.
- Parent and 2 children
- Left elements are less than the parent
- Right elements are more than the parent  

Vocab
- parent node
- child node
- subtrees 
- balanced tree

            10 
           /  \
          6   14 
         / \  / \
        5  8 11  18 

- Notice that the left child of each element is a smaller value  
- Notice that the right child of each element is a larger value  
- Each child oof a node is itself an entire binary tree.

-------------------------------------------------------------------------
How to search: Think of a dictionary 
You open the dictionary in the middle, you know the letter you are looking for is 
either left or right. You open it again halfway and repeat.

Balance tree
- There are the same number of nodes in the left as in the right.
- When this happens, each child binary tree is about half the size of the whole tree.
- Evertime you search, you remove about half the elements from the search.

E.g. Search 1000 elements -> 500 -> 250 -> ... -> 1

-------------------------------------------------------------------------
How many times must you subdivide a tree before reaching only a single element?
Log_2 (n)

n = number of elements

E.g. 4 billion elements 
log_2(4 billion) = 32

WOW! This is 100 million times faster than a search in a Linked List with the same size.


However...if the list is not balanced...you won't be able to cut the tree in half.

At worst, each node has 1 child, then it's a glorified Linked List!

Vocab
- red-black tree = self-balancing binary search tree. Extra bit for color, red or black.
-------------------------------------------------------------------------
Talking about trees.
- Simplest tree is rep. by NULL
- The end are links to empty trees.
- When referring to a tree 
  ' tree headed by [value] '

Vocab
- empty-tree = just null  
 
Implementing binary trees

struct node
{
    int key_value;
    node *p_left;
    node *p_right;
}

Functions you need:

node* insert (node* p_tree, int key);
node  *search (node * p_tree, int key);
void destroyTree (node* p_tree);
node *remove (node* p_tree, in key);

// Why are the * symbols in different places?


Inserting into a tree:
 
- Recursion shines.
- The binary tree data structure is recursive in nature.

Algorithm for inserting into a binary tree:
1. If we have an empty tree, create a new one.
2. Else, if the value being inserted is greater than the current node, insert in the left
   Recursively call inser()
3. else, if the value being inserted is less than the current node, insert it in the right.
   Recursively call inser()


// What it looks like in the stack.
insert (NULL, 5) // recursion
insert (<tree with parent 10>, 5)

E.g. return p_new_tree..
     p_tree->left = insert(p_tree>left, key) // creates a new tree with value 5 and children NULL.
     p_tree->left = p_new_tree // has value 5 

  10
 /  \
Null Null


insert 5.


1. create tree with 5 as the parent.


  5 
 /  \
Null Null

2. Recursively return this new tree and attach to 10, on the left cause 5 is smaller.


    10
  /   \
  5   Null
 /  \
Null Null

-----------------------------------
insert(NULL, 7)
insert ( <tree with paretn 5>, 7)
insert ( <tree with parent 10>, 7)

    10
  /   \
  5   Null
 /  \
Null 7

- Caveat: Since 10 to the tree with parent 5 is already linked, re-linking the left child of 10 
  isn't necessary but it removes an extra conditional check from the code to check if the sub-tree is empty.

-----------------------------------

Searching the tree

0. First check the base cases: is it empty, or we found the node 
1. Figure out which sub-tree side to check, left or right.
2. Recurse, we either found it or we reached NULL.

- Searching a balance tree takes the time log_2(n)
  It's super-fast b/c you cut the search by half every time. 
  E.g. Instead of going through each and every item in the dictionary
       You cut the dictionary in half, and you know which side to look for.
       You cut that half again, and you know which side will get you closer.

Destroying the tree

- Recursive
- Tree destroyed bottom-up

This is the order in which it would be destroyed:

    7 
   /  \
  3     6 
 /  \  /  \
1   2 4   5

- IMPORTANT: This si a good example of a recusrive algorithm that would NOT be easy to 
 implement iteratively. 

Why? B/c you'd have to make the loop keep track of the left tree and the right tree! 
     And for every bit of tree, you'd have to do the same!

- The stack helps keep things organized.

- Since each function call has its own stack frame, it keeps strack of the entire current state of the tree's destsruction, one level of the tree at a time.

Ugh, the only way to implement non-recursively would be to have a data structure that kept the equivalent amount of info for us.

E.g. simulate the stack with a linked-list of subtrees that are in the process of being desstroyed.

Loop algorithm could add subtrees into this list and remove them when they are fully destroyed.

TEACHING: implement destroy_tree non-recursively

--------------------------------

Removing a single item from a binary tree:

Easy stuff:
- if we have an empty tree-> done
- if the value being removed is in the left, remove the value from the left.
- if the value being removed is in the right, remove the value from the right.

Remember that a tree must maintain the following:
Every value in the tree to the left of the current node must be less than its key value.
Every value in the tree to the right of the current node must be more than its key value.

    7 
   /  \
 -1   8

Cases to consider
- node being removed has no children -> remove and you are done
- node being removed has 1 child     -> return that child
- node being removed has 2 children  -> mmmh

You can't just take one of the two children and promote it!
E.g. 

// removing 10 

    10 
   /  \
  6     14 
 /  \  /  \
5   8 11   18 

// Can't just replace with 6

     6 
   /  \
  8     14    // 8 is not less than 6!
 /    /  \
5    11   18 


// Can't just replace with 14 

     14 
   /  \
  8     11    // 11 is not more than 14!
 /       \
5        18 

- Sample solution: Pick the very greatest on the left side of the node we are removing.
  Guaranteed to be greater than every other node to its left b/c it ended up on the left to begin with

  E.g. 8 is the greatest value to the left of 10.

    10 
   /  \
  6     14 
 /  \  /  \
5   8 11   18 

    8 
   /  \
  6     14 
 /    /  \
5    11   18 

- Sample solution: Pick the very lowest on the right side of the tree.

  E.g. 11 is the lowest value to the right of 10.

    11 
   /  \
  6     14 
 /  \    \
5   8    18 

- You need the find_max() function.

1. If the tree is NULL, return NULL
2. If the tree to the right is NULL, you reached the end, return the current head node A.K.A p_tree.
3. If the tree to the right is not NULL, input the right node (the next tree) into find_max() 

"look ahead" one node while we still have a valid pointer.

- Subtle bug: You must remove the max node from its original place!

- We don't actually need to check for a NULL when removing max node...it's just good defensive coding.


    10            // Want to remove 10
   /  \
  6     14 
 /  \  /  \
5   8 11   18 

    10 
   /  \
  6     14 
 /  \  /  \
5   8 11   18     // find max_node on the left (lower) side, this is 8


    8 
   /  \
  6     14 
 /    /  \
5    11   18     // Replace 10 with 8, 6 right points to null 

------------------------------------
Real world uss of binary trees

E.g. Login of Wow has millions of users, each user name is a string 
(you'd have to check each character), you don't want to search each and every item!


Common situations where you want fast look-ups:

- World of Warcraft has a map with usernames and passwords ( the password itself isn't in the map, but a hashed version of the password is stored)

When you log in, WoW would lookup your username and find the hashed password, compare the password to what the user typed in. If the info is valid, get the rest of the character information.

The map would be implemented as a binary tree!

- Map as a binary tree: The key is used for inserting nodes (username in this case) and the value (password and other stuff) is in the same node, next to the key.

- E.g. Credit cards are millions and millions of users

If you have 1 million credit cards, stored in a balanced tree, looking up with take

   log_2 (1 000 000) = 20 nodes.

   That's 50,000 times better than doing a linear scan of each and every node!!!!!

Credit cards, WoW login, looking up a caller in your address book: all binary trees.
Well, in reality they are implemented in much more complicated structures but they all build upon binary trees and maps.
E.g. Credit cards need to store data permanently in a data base. 


Vocab
- map = a data structure with a key and value e.g. {(key,value), (key,value)}
        The value may be another complicated structure, even another map!

- hash = an algorithm that turns a string of text into another string of text (or into a number)

---------------------------------------------------

The cost of building trees and maps

- It takes a long time to build a map using a binary tree.

Cost of adding or searching a node = log_2(n)

Cost of building the entire tree = n*log_2(n) 

Liner search on a linked list takes an AVERAGE of n/2 nodes.

E.g. if you have 100 elements in a linked list, on average you are comparing against 50 of them until you find a match.

There is no constants in O notation.

If you do 2log_2(n) searches on a linked list, you spend about the same time doing searches as it would take to build a binary tree.

(n/2)*2log_2(n) = n*log_2(n)

- Don't construct a binary tree if you are only going to use it one time.

E.g. good for credit card company, maybe not so smart for the cell phone.


























