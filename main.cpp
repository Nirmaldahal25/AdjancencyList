// CMAKENEW generated file: Sample main file
#include <iostream>
#include "graphs.hpp"
#include <string>

int main(){
    Graph<char> graph{'A', 'B'};
    std::set<char> se;
    graph.addVertex('C');
    graph.addVertex('D');
    graph.addVertex('E');
    graph.addEdge('A', 'B');
    graph.addEdge('A', 'C');
    graph.neighbours('A', se);
    graph.removeEdge('A','B');
    graph.display();
    std::cout<<graph.outDegree('A')<<"  Outdegree"<<std::endl;
    std::cout<<graph.inDegree('A')<<"  Indegree"<<std::endl;
    std::cout<<graph.degree('A')<<" total degree\n";

    graph.removeVertex('A');
    std::cout<<"A Vertex Removed\n";
    std::cout<<std::boolalpha<<graph.isDirected()<<"  Directed\n";
    std::cout<<std::boolalpha<<graph.isNeighbour('A','C')<<"  Are neighbours\n";
    for(auto i : se)
    {
        std::cout<<i<<std::endl;
    }
    return 0;  
}

