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
- The data structure is recursive in nature.










































