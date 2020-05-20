/*
 *  03_check_cycles.cpp
 *
 *  author : Sreejith S
 *  email  : echo $(base64 -d <<< NDQ0bGhjCg==)@gmail.com
 *  date   : Tue 19 May 2020 20:27:46 IST
 *  ver    :
 *
 *   Check whether any cycles are present in the graph
 *   Also printing a partial list of cycles
 *   Using colors
 *   white - 0 - Not visited
 *   grey  - 1 - Being explored
 *   black   - 2 - Finished exploring
 */


#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <sstream>
#include <cassert>
#include "Graph.h"

using std::vector;
using std::map;
using namespace ALG;

template <class Type>
void isCyclic(Graph<Type>& G, vector<char>& color, map<int, int> parent_map,
              int source, int parent)
{
    color[source] = 1; //set the currently being explored node to grey
    vector<int> outAdj = G.outAdjacentNodes(G[source]);
    parent_map[source] = parent;
    for(auto& w : outAdj)
    {
        if (color[w] == 1 && w != parent) //Found a grey node - Cycle found!
        {
            int c_node, p_node;
            std::cout << "Found Cycle: " << G[w] << "<-" << G[source];// << G[c_node] << "->" << G[p_node];
            c_node = source;
            p_node = -1;
            while (p_node != w)
            {
                p_node = parent_map[c_node];
                std::cout << "<-" << G[p_node];
                c_node = p_node;

            }
            std::cout << std::endl;
        }
        if (color[w] == 0) //Found a white node
        {
            isCyclic(G, color, parent_map, w, source);
        }
    }
    color[source] = 2; //set black, if there is nothing more to explore
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

    vector<char> color(G.size(), 0); //to keep track of nodes
    map<int, int> parent_map;
    for(int i = 0; i < G.size(); i++)
    {
        if (color[i] == 0) //Choose from white set
        isCyclic(G, color, parent_map, i, -1);
    }
    //std::cout << "The graph is "
              //<< ((!isCyclic(G, visited, 0, 0)) ? 'O' : 'X')
              //<< std::endl;

    return 0;
}


