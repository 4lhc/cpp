/*
 *  01_adjacency_mat.cpp
 *
 *  author : Sreejith S
 *  email  : echo $(base64 -d <<< NDQ0bGhjCg==)@gmail.com
 *  date   : Tue 12 May 2020 23:41:59 IST
 *  ver    :
 *  Program to create a graph adjacency matrix from input
 *
 */


#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <assert.h>
#include "Graph.h"


using std::vector;
using namespace ALG;


int main() {

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
    return 0;
}


