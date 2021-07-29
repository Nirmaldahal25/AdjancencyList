// CMAKENEW generated file: Sample header file
#ifndef GRAPHS_CLASS 
#define GRAPHS_CLASS
#include <unordered_map>
#include <set>
#include <initializer_list>
#include <type_traits>
#include <utility>

template<bool type, typename T>
using enable_if_t = typename std::enable_if<type, T>::type;

template <typename T, enable_if_t<std::is_arithmetic<T>::value || std::is_same<T *,char *>::value,T> = 0>
class Graph
{
    public:
        //initialize all the vertices of the graph
        Graph()
        {

        }
        Graph(std::initializer_list<T> list)
        {
            for(const auto& i:list)
            {
                this->vertices.insert(i);
            }
        }

        bool isEmpty()const
        {
            return vertices.empty();
        }

        int noofVertices()const
        {
            return vertices.size();
        }

        int noofEdges() const
        {
            return this->graph.size();
        }

        int degree(const T& vertex) const
        {
            return this->outDegree(vertex)+this->inDegree(vertex);
        }

        #include "graphs.hxx"
    private:
        std::unordered_multimap<T,T> graph;
        std::set<T> vertices;
};

#endif