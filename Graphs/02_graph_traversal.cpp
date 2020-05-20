/*
 *  02_graph_traversal.cpp
 *
 *  author : Sreejith S
 *  email  : echo $(base64 -d <<< NDQ0bGhjCg==)@gmail.com
 *  date   : Mon 18 May 2020 01:47:15 IST
 *  ver    :
 *
 *  Perform BFS and DFS graph traversal from a given vertex
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <cassert>
#include "Graph.h"


using std::vector;
using namespace ALG;


template <class Type>
void recursiveDFS(Graph<Type>& G, vector<char>& visited, int source)
{
    //Args: Graph, visited, index of Source Node
    //Here source node index is used for the ease of programming
    visited[source] = 1;
    std::cout << "Visited Node: " << G[source] << std::endl;
    vector<int> outAdj = G.outAdjacentNodes(G[source]);
    for(auto& w : outAdj)
    {
        if (!visited[w])
            recursiveDFS(G, visited, w);
    }
}


template <class Type>
void iterativeBFS(Graph<Type>& G, int source)
{
    int v;
    std::queue<int> Q;
    std::vector<char> visited(G.size(), 0);
    Q.push(source);
    visited[source] = 1;
    while(!Q.empty())
    {
        v = Q.front();
        Q.pop();
        std::cout << "Exploring Node: " << G[v]<< std::endl;
        std::vector<int> outAdj = G.outAdjacentNodes(G[v]);
        for(auto& w : outAdj)
        {
            if(!visited[w])
            {
                Q.push(w);
                visited[w] = 1;
                std::cout << "Found Node: " << G[w]<< std::endl;
            }
        }

    }

}

int main()
{

    Graph<char> G;
    int n;
    char c, node_name;
    std::cout << "Enter No. of Nodes: " << std::endl;
    std::cin >> n;
    assert(n < G.sizeMax());
    std::cout << "Enter the Graph (Adjacency List): " << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> node_name;
        G.addNode(node_name);
        std::string line;
        std::getline(std::cin, line);
        std::istringstream iss(line);
        while ( iss >> c )
        {
            G.addEdge(node_name, c);
        }

    }
    G.printAdjMat();

    std::cout << "\n\nRecursive DFS Traversal" << std::endl;
    std::vector<char> visited(G.size(), 0); //to keep track of visited nodes
    recursiveDFS(G, visited, 0); //starting at node of index 0

    std::cout << "\n\nIterative BFS Traversal" << std::endl;
    iterativeBFS(G, 0);

    return 0;
}


