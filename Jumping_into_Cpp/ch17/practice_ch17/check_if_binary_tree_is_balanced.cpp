// How to build: $clang++ -std=c++11 hello_world.cpp
// How to build: $g++ -std=c++11 hello_world.cpp      // YES
// How to build: $g++ hello_world.cpp -o hello        // NO!
// How to debug: $gdb ./$MY_BINARY_NAME
// gcc?
#include <iostream>
#include <stdlib.h> // need abs()
using namespace std;

/*

In a balanced tree the height of the subtrees differ by at most 1.
Same thing for the children.
- The left subtree is balanced AND
- the right subtree is balanced.


Balanced tree
            A       // A children. Differnce is 1
           /  \
          B    C    // B children. Difference is 1
         /    / \
        D    E  F  // C  children difference in height 1
            /
           G 

Unbalanced tree
            A       // A children. Differnce is 1
           /  \
          B    C    // B children. Difference is 1
         /    /  
        D    E      // C children. Difference is 2! NOT BALANCED. 
            /
           G 


*/

struct node
{
    int key_value;
    node *p_left;
    node *p_right;
};

class BinaryTree
{
public:
    BinaryTree(); 
    ~BinaryTree(); 
    void add(int key);
    void show();
    bool is_balanced();
    int number_of_nodes();
    void destroy_tree(node *p_tree);
private:
    node* insert(node *p_tree, int key);
    void display(node* p_tree);
    int count(node * p_tree);
    bool check_if_balanced(node * p_tree);
    int return_longest_depth(node * p_tree);
    node* _p_tree_top;
};

BinaryTree::BinaryTree()
{
   // Create an empty tree.
   _p_tree_top = nullptr;    
}

BinaryTree::~BinaryTree()
{
   // Delete the tree.
   destroy_tree(_p_tree_top);
}

void BinaryTree::add(int key)
{
   _p_tree_top = insert(_p_tree_top, key);

}


node* BinaryTree::insert( node *p_tree, int key)
{

    //
    // base case: we have reached an empty tree and need 
    // to insert our new node here
    //
    if( p_tree == nullptr)
    {
         node* p_new_tree = new node;
         p_new_tree->p_left = nullptr;
         p_new_tree->p_right = nullptr;
         p_new_tree->key_value = key;
         return p_new_tree;
    }
    //
    // decide whether to insert into the left subtree or
    // the tight subtree depending on the value of the 
    // node
    //
    if( key < p_tree->key_value)
    {
         //
         // build a new tree based on p_tree->left by
         // adding the key. Then replace the existing left pointer
         // with a pointer to a new tree.
         // 
         // iIf the left isn't null then p_tree->p_left won't 
         // actually change but it doesn't hurt to set it
         //
         p_tree->p_left = insert( p_tree->p_left, key);
    }
    else 
    {
         // Insertion into the right is exactly symmetric to left insertion
         p_tree->p_right = insert( p_tree->p_right, key);
         
    }
    return p_tree;    

}

node *search (node *p_tree, int key)
{
    if(p_tree==nullptr)
    {
         return nullptr;
    } 
    else if(key == p_tree->key_value)
    {
         return p_tree;
    }
    else if (key < p_tree->key_value)
    {
         return search(p_tree->p_left, key);
    }
    else
    {
         return search(p_tree->p_right, key);
    }
}

void BinaryTree::destroy_tree(node *p_tree)
{
    if(p_tree != nullptr)
    {
         destroy_tree(p_tree->p_left);
         destroy_tree(p_tree->p_right);
         cout << "deleting node:" << p_tree->key_value << endl;
         delete p_tree; 
    }
}

node* remove_max_node( node* p_tree, node* p_max_node)
{
    if(p_tree==nullptr)
    {
         return nullptr;
    } 
    if(p_tree == p_max_node)
    {
         return p_max_node->p_left;
    }    
    p_tree->p_right = remove_max_node(
         p_tree->p_right, p_max_node); 
    return p_tree;
}

node* find_max(node* p_tree)
{
    if(p_tree==nullptr)
    {
         return nullptr;
    }
    if(p_tree->p_right == nullptr)
    {
         return p_tree;
    } 
    return find_max( p_tree->p_right);
}

node* remove (node* p_tree, int key)
{
    if(p_tree==nullptr)
    {
         return nullptr;
    } 
    if(p_tree->key_value == key)
    {
         // Ah 
         if(p_tree->p_left == nullptr)
         {
              node* p_right_subtree = p_tree->p_right;
              delete p_tree;
              return p_right_subtree;
         }
         if(p_tree->p_right == nullptr)
         {
              node* p_left_subtree = p_tree->p_left;
              delete p_tree;
              return p_left_subtree;
         }
         node* p_max_node = find_max( p_tree->p_left);
         p_max_node->p_left =
              remove_max_node(p_tree->p_left, p_max_node); 
         p_max_node->p_right = p_tree->p_right;
         delete p_tree;
         return p_max_node;
    }
    else if (key < p_tree->key_value)
    {
         return remove(p_tree->p_left, key);
    }
    else
    {
         return remove(p_tree->p_right, key);
    }
    
}
bool BinaryTree::is_balanced()
{
    return check_if_balanced(_p_tree_top);
}
bool BinaryTree::check_if_balanced(node * p_tree)
{
    
    int right_depth = 0; 
    int left_depth = 0; 

    if(p_tree == nullptr)
    {
        return false;
    }

    // Get depth of the children
    if(p_tree->p_left != nullptr)
    {
        left_depth += return_longest_depth(p_tree->p_left);
    }
    if(p_tree->p_right != nullptr)
    {
        right_depth += return_longest_depth(p_tree->p_right);
    }

    // If the difference in depths is 1 or less, it's balanced 
    int difference = right_depth - left_depth;
    cout << "Node with " << p_tree->key_value << " value\n";  
    cout << "     has " << right_depth << " right children\n";  
    cout << "     and " << left_depth << " left children\n";  
    if(abs(difference) <= 1)
    { 
        return true;
    } 
    else
    {
        return false;
    }  
}

// returns the difference in depths between 2 children 
int BinaryTree::return_longest_depth(node * p_tree)
{
    int right_depth = 0; 
    int left_depth = 0; 

    if(p_tree == nullptr)
    {
        return 0;
    }
    if(p_tree->p_left == nullptr && p_tree->p_right == nullptr)
    {
        return 1;
    }
    if(p_tree->p_left != nullptr)
    {
        left_depth += return_longest_depth(p_tree->p_left);
    }
    if(p_tree->p_right != nullptr)
    {
        right_depth += return_longest_depth(p_tree->p_right);
    }
    cout << "Node with " << p_tree->key_value << " value\n";  
    cout << "Node has " << right_depth << " right children\n";  
    cout << "     and " << left_depth << " left children\n";  

    if(right_depth > left_depth)
    {
        return right_depth;
    } 
    else
    {
        return left_depth;
    } 

}


void BinaryTree::show()
{
    display(_p_tree_top);
}

int BinaryTree::number_of_nodes()
{
     return count(_p_tree_top);
}

int BinaryTree::count(node * p_tree)
{
    int curr_count = 0;

    if(p_tree == nullptr)
    {
        return 0;
    }
    // count left tree, rep. by p_left
    else if(p_tree->p_left != nullptr)
    {
        curr_count += count(p_tree->p_left);
    }
    // count right tree
    else if(p_tree->p_right != nullptr)
    {
        curr_count += count(p_tree->p_right);
    }
    // count the parent
    curr_count += 1;

    return curr_count;

}

// Option: sorter order
void BinaryTree::display(node* p_tree)
{
    // base case, no tree
    if(p_tree == nullptr)
    {
         cout << "empty";
    } 
    // display left tree
    else if( p_tree->p_left != nullptr)
    {
         cout << " L: \n";
         cout << p_tree->p_right->key_value << endl;  
         display(p_tree->p_left); 
    } 
    // display right tree
    else if( p_tree->p_right != nullptr)
    {
         cout << " R: \n";
         cout << p_tree->p_right->key_value << endl;  
         display(p_tree->p_right); 
    } 
    // display parent node
    cout << " P: \n";
    cout << p_tree->key_value << endl;  

}

int main()
{
    auto numbers = {1,2,3,4,5}; 

    BinaryTree redwood;

    // O-notation
    // source: https://stackoverflow.com/questions/2307283/what-does-olog-n-mean-exactly
    //
    for (const int& nn : numbers)
    {
        redwood.add(nn);
    }
    cout << endl;

    redwood.show();

    cout << "There are " << redwood.number_of_nodes()  << " nodes in the tree \n";

    if(redwood.is_balanced())
    {
         cout << "tree is balanced \n";
    }
    return 0;
}
