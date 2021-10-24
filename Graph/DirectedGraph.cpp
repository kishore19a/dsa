#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>

class DirectedGraph
{
public:
    DirectedGraph(int numVertices);
    ~DirectedGraph();

    void addEdgeFromUtoV(int u, int v);
    bool detectCycle(int index, std::vector<bool>& visited, std::vector<bool>& reccStack);
    void topologicalSort();

private:
    int _numVertices;
    std::vector<std::vector<int>> _directedGraph;
};

DirectedGraph::DirectedGraph(int numVertices)
  : _numVertices(numVertices)
{
    _directedGraph.resize(_numVertices);
}

DirectedGraph::~DirectedGraph()
{
}

void DirectedGraph::addEdgeFromUtoV(int u, int v)
{
    _directedGraph[u].push_back(v);
}

bool DirectedGraph::detectCycle(int index, std::vector<bool>& visited, std::vector<bool>& reccStack)
{
    visited[index] = true;
    reccStack[index] = true;

    for(auto v : _directedGraph[index])
    {
        if(!visited[v])
        {
            if(detectCycle(v, visited, reccStack))
                return true;
        }
        else if (reccStack[v] == true)
            return true;
    }

    reccStack[index] = false;
    return false;
}

void DirectedGraph::topologicalSort()
{
    std::cout << "Topological sort: " << std::endl;
    std::vector<int> indegree(_numVertices, 0);
    // Find indegree of all vertices
    for(auto list : _directedGraph)
        for(auto v : list)
            indegree[v]++;

    int count{0};
    std::queue<int> indegreeZeroQueue;
    
    for (int i = 0; i < _numVertices; i++)
        if(indegree[i] == 0)
            indegreeZeroQueue.push(i);

    while (!indegreeZeroQueue.empty())
    {
        int zeroIndegreeNode = indegreeZeroQueue.front();
        indegreeZeroQueue.pop();

        std::cout << zeroIndegreeNode << " ";
        count++;

        for(auto v : _directedGraph[zeroIndegreeNode])
        {
            indegree[v]--;
            if(indegree[v] == 0)
                indegreeZeroQueue.push(v);
        }
    }
    
    std::cout << std::endl;

    // side application of this Kahn's algorithm for topological sorting
    if(count == _numVertices)
        std::cout << "From topological sorting : Cycle doesn't exist" << std::endl;
    else
        std::cout << "From topological sorting : Cycle exists" << std::endl;
}

int main(int argc, char const *argv[])
{
    int numVertices{7};
    DirectedGraph directedGraph(numVertices);
    directedGraph.addEdgeFromUtoV(0, 1);
    directedGraph.addEdgeFromUtoV(2, 1);
    directedGraph.addEdgeFromUtoV(2, 3);
    directedGraph.addEdgeFromUtoV(3, 4);
    directedGraph.addEdgeFromUtoV(4, 6);
    directedGraph.addEdgeFromUtoV(6, 5);
    directedGraph.addEdgeFromUtoV(5, 3);

    std::vector<bool> visited(numVertices, false);
    std::vector<bool> reccStack(numVertices, false);

    bool cycleDetected{false};
    for(int i = 0; i < numVertices; i++)
    {
        if(!visited[i])
            if(directedGraph.detectCycle(i, visited, reccStack))
                cycleDetected = true;
    }

    if(cycleDetected) std::cout << "This graph has cycle" << std::endl;
    else std::cout << "This graph doesn't have cycle" << std::endl;

    directedGraph.topologicalSort();

    return 0;
}

