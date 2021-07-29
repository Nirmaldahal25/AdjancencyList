// CMAKENEW generated file: Sample main file
#include <iostream>
#include "graphs.hpp"
#include <string>

int main(){
    Graph<char> graph{'A', 'B'};
    graph.addVertex('C');
    graph.addVertex('D');
    graph.addVertex('E');
    graph.addEdge('A', 'B');
    graph.addEdge('A', 'C');
    graph.removeEdge('A','B');
    graph.display();
    std::cout<<graph.outDegree('A');
    std::cout<<graph.inDegree('B');
    std::cout<<std::boolalpha<<graph.isDirected()<<std::endl;
    return 0;  
}

