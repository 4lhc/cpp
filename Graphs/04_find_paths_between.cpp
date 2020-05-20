/*
 *  04_find_paths_between.cpp
 *
 *  author : Sreejith S
 *  email  : echo $(base64 -d <<< NDQ0bGhjCg==)@gmail.com
 *  date   : Wed 20 May 2020 14:37:39 IST
 *  ver    :
 *
 *   List all paths of length between two vector
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
void findPaths(Graph<Type>& G, vector<char>& visited, vector<int>& path,
                  int source, int target, int length)
{
    visited[source] = 1;
    path.push_back(source);
    //We only need pathsize of 4
    if (source == target && (int)path.size() == length+1)
    {
        std::cout << "Path found: " << std::endl;
        for(auto& n : path)
            std::cout << G[n] << " ";
        std::cout << std::endl;
    }
    else
    {
        vector<int> outAdj = G.outAdjacentNodes(G[source]);
        for(auto& w : outAdj)
        {
            if (!visited[w])
                findPaths(G, visited, path, w, target, length);
        }
    }
    path.pop_back(); //remove the current node from path and mark it as
    visited[source] = 0;    //unvisited

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

    std::cout << "\n\nRecursive DFS Traversal - Find Paths" << std::endl;
    std::vector<char> visited(G.size(), 0); //to keep track of visited nodes
    std::vector<int> path;
    //find paths of length '4' between 'S' & 'D'
    findPaths(G, visited, path, G.getIndex('S'), G.getIndex('D'), 4);
	return 0;
}
