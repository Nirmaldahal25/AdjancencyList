// CMAKENEW generated file: Sample cpp source file
#include "graphs.hpp"

void addVertex(T& new_vertex)
{
    this->vertices.emplace(new_vertex);
}

void addVertex(T&& vertex)
{
    this->vertices.insert(vertex);
}

void addEdge(T&& vertex1, T&& vertex2)
{
    if(this->vertices.find(vertex1) == vertices.end()) this->addVertex(vertex1);
    if(this->vertices.find(vertex2) == vertices.end()) this->addVertex(vertex2);
    this->graph.emplace(vertex1, vertex2);
}

void removeVertex(const T& vertex)
{
    auto key = this->vertices.erase(vertex);
    auto iter = graph.equal_range(vertex);
    for(auto it = iter.first; it != iter.second;)
    {
        it = graph.erase(it);
    }
    for(auto i: vertices)
    {
        iter= this->graph.equal_range(i);
        for(auto it = iter.first; it != iter.second;)
        {
            if(it->first == vertex || it->second == vertex)
            {
                it = this->graph.erase(it);
                continue;
            }
            it++;
        }
    }   
    
}

void removeEdge(const T& vertex1, const T& vertex2)
{
    auto map = this->graph.equal_range(vertex1);
    for(auto it = map.first; it != map.second;)
    {
        if(it->first == vertex1 && it->second == vertex2)
        {
            it = graph.erase(it);
            break;
        }
        it++;
    }
}


void neighbours(const T& vertex, std::set<T>& container)
{
    for(const auto& it : graph)
    {
        if(it.second == vertex)
        {
            container.insert(it.first);
        }
        if(it.first == vertex )
        {
            container.insert(it.second);
        }
    }
}

bool isDirected() const{
    std::set<int> data;
    for(const auto& i: vertices )
    {
        auto map = this->graph.equal_range(i);
        for(auto it = map.first; it != map.second; it++)
        {
            if(it->second == i)
            {
                continue;
            }
            data.insert(it->second);
        }
        if(data.size() < vertices.size() - 1) return true;
        data.clear();
    }
    return false;
}

int inDegree(const T& vertex) const
{
    int indegree = 0;
    for(const auto& vert : graph)
    {
        if(vert.second == vertex)
        {
            indegree++;
        }
    }
    return indegree;
}

int outDegree(const T& vertex) const
{
    if(vertices.find(vertex) == vertices.end()) return 0;
    
    auto map = this->graph.equal_range(vertex);
    int outdeg = 0;

    for(auto it = map.first; it != map.second; it++){
        outdeg++;
    }

    return outdeg;
}

bool isNeighbour(const T& vertex1, const T& vertex2) const
{
    auto map = this->graph.equal_range(vertex1);
    for(auto it = map.first; it!=map.second; it++)
    {
        if(it->second == vertex2) return true;   
    }

    map = this->graph.equal_range(vertex2);
    for(auto it = map.first; it!=map.second; it++)
    {
        if(it->second == vertex1) return true;   
    }
    return false;
}

void display()
{
    for(const auto& i : graph)
    {
        std::cout<<i.first<<' '<<i.second<<'\n';
    }
    for(const auto& i: vertices)
    {
        if(this->graph.find(i) == this->graph.end())
            std::cout<<i<<'\n';
    }
    std::cout<<std::endl;
}