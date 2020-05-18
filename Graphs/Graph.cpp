/*
 *  Graph.cpp
 *
 *  author : Sreejith S
 *  email  : echo $(base64 -d <<< NDQ0bGhjCg==)@gmail.com
 *  date   : Sun 17 May 2020 17:59:56 IST
 *  ver    :
 *
 */


#include "Graph.h"

using namespace ALG;


template <class Type>
const int Graph<Type>::MAX;

template <class Type>
Graph<Type>::Graph()
{

}

template <class Type>
Graph<Type>::~Graph()
{

}

template <class Type>
void Graph<Type>::addNode(const Type& value)
{
    assert(size() < MAX);
    if (getIndex(value) == -1)
    {
        //Avoid duplicate nodes
        int newNodeNum = numNodes;
        numNodes++;

        for(int i = 0; i < numNodes; i++)
        {
            adjacencyMatrix[i][newNodeNum] = 0;
            adjacencyMatrix[newNodeNum][i] = 0; //since no connections exists
        }
        labels[newNodeNum] = value;
    }
}


template <class Type>
void  Graph<Type>::addEdge(Type& source, Type& target, int weight)
{
    //in case target node doesn't exist, create it.
    int src{0}, dst{0};
    if (getIndex(target) == -1)
        addNode(target);
    src = getIndex(source);
    dst = getIndex(target);
    assert(src < size() && dst < size());
    adjacencyMatrix[src ][dst] = weight;
}


template <class Type>
void  Graph<Type>::addEdge(Type& source, Type& target)
{
    addEdge(source, target, 1);
}

template <class Type>
int Graph<Type>::getIndex(const Type& value)
{
    for(int i = 0; i < numNodes; i++)
    {
        if (labels[i] == value)
            return i;
    }
    return -1;
}

template <class Type>
Type& Graph<Type>::operator [](int node)
{
    assert(node < size());
    return labels[node];
}


template <class Type>
int Graph<Type>::size()
{
    return numNodes;
}

template <class Type>
int Graph<Type>::sizeMax()
{
    return MAX;
}

template <class Type>
void Graph<Type>::printAdjMat()
{
    int col_margin{3};
    int n = size();
    std::string hl(col_margin*n*2-1, '-');

    std::cout << " ";
    for (int i = 0; i < n; i++)
    {
        std::cout << std::setw(col_margin) << ' '
                  << std::setw(col_margin) << labels[i];
    }
    std::cout << std::endl;
    for(int i = 0; i < n; i++)
    {
        std::cout << std::setw(col_margin*(n*2 + 1)) << hl
                  << std::endl << labels[i];
        for(int j = 0; j < n; j++)
        {
            std::cout << std::setw(col_margin) << '|'
                      << std::setw(col_margin) << adjacencyMatrix[i][j];
        }
        std::cout << std::setw(col_margin) << '|' << std::endl;
    }
    std::cout << std::setw(col_margin*(n*2 + 1)) << hl << std::endl;
}

//Explicitly instantiate the template
template class ALG::Graph<char>;
template class ALG::Graph<int>;
template class ALG::Graph<std::string>;
