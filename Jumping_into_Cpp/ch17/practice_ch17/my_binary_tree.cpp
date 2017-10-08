// How to build: $clang++ -std=c++11 hello_world.cpp
// How to build: $g++ -std=c++11 hello_world.cpp      // YES
// How to build: $g++ hello_world.cpp -o hello        // NO!
// How to debug: $gdb ./$MY_BINARY_NAME
// gcc?
#include <iostream>
using namespace std;

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
    void destroy_tree(node *p_tree);
private:
    node* insert(node *p_tree, int key);
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
         cout << "deleting node:" << p_tree->key_value;
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
// Option: sorter order
void display(node* p_tree)
{
    // base case, no tree
    if(p_tree == nullptr)
    {
         cout << "empty";
    } 
    // display value if there are no more children to explore 
    if( p_tree->p_right == nullptr && p_tree->p_left == nullptr)
    {
         cout << p_tree->key_value;  
    } 
    // display left tree
    else if( p_tree->p_left != nullptr)
    {
         display(p_tree->p_left); 
    } 
    // display right tree
    else if( p_tree->p_right != nullptr)
    {
         display(p_tree->p_right); 
    } 
    // display parent node
    cout << p_tree->key_value;  

}

int main()
{
    auto numbers = {1,2,3,4,5}; 

    BinaryTree redwood;
    redwood.add(10);
/*
    redwood.insert(redwood, 10);
    node* insert (node *p_tree, int key);
    a.key_value = 0;

    node *p_a = &a;

    a.insert(p_a, 10);
    a.insert(p_a, 7);

    display(p_a);
*/
    // O-notation
    // source: https://stackoverflow.com/questions/2307283/what-does-olog-n-mean-exactly
    //
    for (const int& nn : numbers)
    {
//        a.insert(p_a, nn);
        cout << nn;
    }


    return 0;
}
