/*
 *  Graph.h
 *
 *  author : Sreejith S
 *  email  : echo $(base64 -d <<< NDQ0bGhjCg==)@gmail.com
 *  date   : Sun 17 May 2020 17:59:56 IST
 *  ver    :
 *
 *  A graph implementation based on https://www.youtube.com/watch?v=BcaZIxaS-F4
 *
 */

#ifndef GRAPH_H
#define GRAPH_H
#include <assert.h>
#include <string>
#include <iostream>
#include <iomanip>

namespace ALG
{

    template <class Type>
    class Graph
    {
        private:
            static const int MAX{20};
            int adjacencyMatrix[MAX][MAX];
            Type labels[MAX];
            int numNodes{0};

        public:
            Graph();
            ~Graph();
            int size(); //Return the nuber of edges
            int sizeMax(); //Return MAX
            void addNode(const Type& value);
            void addEdge(Type& source, Type& target);
            void addEdge(Type& source, Type& target, int weight);
            int getIndex(const Type& value);
            Type& operator [] (int node);
            void printAdjMat();

    };
}

#endif
