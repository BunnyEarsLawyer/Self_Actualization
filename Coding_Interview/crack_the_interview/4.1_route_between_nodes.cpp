
// How to build: $clang++ -std=c++11 hello_world.cpp

// Program to print BFS traversal from a given
// source vertex. BFS(int s) traverses vertices 
// reachable from s.
#include<iostream>
#include <list>
/*
0-->1
^   | 
|   |
v   |
2<---
|
v
3

Breath First Search (BFS) from node 2 = 2, 0, 3, 1

There are 2 ways to represent graphs:
1. Connection matrix - Disadvantage of pointer fiddling
2. List of lists     - Easier to use when doing graph transformations

*/ 
using namespace std;
 
// This class represents a directed graph using
// adjacency list representation
class Graph
{
    int number_of_vertices;
 
    // Pointer to an array of adjacency lists
    list<int> *adj;   

public:
    Graph(int number_of_vertices);
 
    // function to add an edge to graph
    void addEdge(int v, int w); 
 
    // prints BFS traversal from a given source s
    void print_BFS(int s);  

    bool there_is_route(int a, int b);  
};

// Constructor 
Graph::Graph(int number_of_vertices)
{
    this->number_of_vertices = number_of_vertices;
    adj = new list<int>[number_of_vertices];
}

// Public functions 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}
 
//
// An array of bools of size (number_of_vertices) 
// keeps track of which nodes have been visited.
//
// A list of ints (a queue) 
//
void Graph::print_BFS(int s)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[number_of_vertices];
    for(int i = 0; i < number_of_vertices; i++)
        visited[i] = false;
 
    // Create a queue for BFS
    list<int> queue;
 
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);
 
    // 'i' will be used to get all adjacent
    // vertices of a vertex
    list<int>::iterator i;
 
    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop_front();
 
        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited, 
        // then mark it visited and enqueue it
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

// Depth First Search
bool Graph::there_is_route(int start, int end)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[number_of_vertices];
    for(int i = 0; i < number_of_vertices; i++)
        visited[i] = false;
 
    // Create a queue for BFS
    list<int> queue;
 
    // Mark the current node as visited and enqueue it
    visited[start] = true;
    queue.push_back(start);
 
    // 'i' will be used to get all adjacent
    // vertices of a vertex
    list<int>::iterator i;
 
    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        int front = queue.front();
        cout << front << " ";
        queue.pop_front();
 
        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited, 
        // then mark it visited and enqueue it
        for (i = adj[front].begin(); i != adj[front].end(); ++i)
        {
            if (!visited[*i])
            {
                if(*i == end) {
                    cout << end << " ";
                    return true;
                } else {
                    visited[*i] = true;
                    queue.push_back(*i);
                }
            }
        }
    }

    return false;
}
 
// Driver program to test methods of graph class
int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.print_BFS(2);

    cout << "Following is Breadth First Traversal "
         << "To find route between 1 and 3 \n";
    g.there_is_route(1,3);
 
    return 0;
}
