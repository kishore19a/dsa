#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <bits/stdc++.h>

class WeightedGraph
{
public:
    WeightedGraph(int numVertices)
      : _numVertices(numVertices)
    {
        _adjList.resize(numVertices);
    }

    ~WeightedGraph() {}

    void addEdge(int u, int v, int w);
    void primsMinSpanningTree();
    void DijkstrasAlgo(int startIndex);

private:
    int _numVertices;
    std::vector<std::vector<std::pair<int, int>>> _adjList;
};

void WeightedGraph::addEdge(int u, int v, int w)
{
    _adjList[u].push_back(std::make_pair(v, w));
    _adjList[v].push_back(std::make_pair(u, w));
}

void WeightedGraph::primsMinSpanningTree()
{
    std::vector<int> weightOfEachNode(_numVertices, INT_MAX);
    std::vector<bool> visited(_numVertices, false);

    weightOfEachNode[0] = 0;
    visited[0] = true;

    for(auto& neb : _adjList[0])
        weightOfEachNode[neb.first] = neb.second;

    std::cout << "0 ";

    for (int i = 1; i < _numVertices; i++)
    {
        int minWeight{INT_MAX}; int nextNodeToVisit{-1};
        // find min among all unvisited nodes
        for (int j = 0; j < _numVertices; j++)
        {
            if(!visited[j])
            {
                if(weightOfEachNode[j] < minWeight)
                {
                    minWeight = weightOfEachNode[j];
                    nextNodeToVisit = j;
                }
            }
        }
        // if not visited update its neighbour
        std::cout << nextNodeToVisit << " ";
        visited[nextNodeToVisit] = true;
        for(auto& neb : _adjList[nextNodeToVisit])
            weightOfEachNode[neb.first] = neb.second;
    }

    std::cout << std::endl;
}

void WeightedGraph::DijkstrasAlgo(int startIndex)
{
    // First assign weight to reach node as infinity, and all nodes as unvisited
    std::vector<int> weightToReachThisNode(_numVertices, INT_MAX);
    std::vector<bool> visited(_numVertices, false);

    // set weight to reach start node as 0
    weightToReachThisNode[startIndex] = 0;
    visited[startIndex] = true;
    for(auto& neb : _adjList[startIndex])
        weightToReachThisNode[neb.first] = neb.second;

    // loop for number of vertices
    for (int i = 1; i < _numVertices; i++)
    {
        // find node with smallest which is still unvisited
        int minWeight{INT_MAX}, nextNodeToVisit{i};
        for (int j = 0; j < _numVertices; j++)
        {
            if(!visited[j])
            {
                if(weightToReachThisNode[j] < minWeight)
                {
                    minWeight = weightToReachThisNode[j];
                    nextNodeToVisit = j;
                }
            }
        }
        
        // update weight of all it's neighbour
        visited[nextNodeToVisit] = true;
        for(auto& neb : _adjList[nextNodeToVisit])
        {
            if(!visited[neb.first])
            {
                if(weightToReachThisNode[nextNodeToVisit] + neb.second < weightToReachThisNode[neb.first])
                    weightToReachThisNode[neb.first] = weightToReachThisNode[nextNodeToVisit] + neb.second;
            }
        }
    }

    for(int i = 0; i < _numVertices; i++)
    {
        std::cout << i << " -> " << weightToReachThisNode[i] << std::endl;
    }

}

int main(int argc, char const *argv[])
{
    int numVertices{7};

    WeightedGraph graph(numVertices);
    graph.addEdge(0, 2, 18);
    graph.addEdge(0, 1, 10);
    graph.addEdge(2, 3, 70);
    graph.addEdge(1, 2, 6);
    graph.addEdge(1, 4, 20);
    graph.addEdge(4, 5, 10);
    graph.addEdge(4, 6, 10);
    graph.addEdge(5, 6, 5);

    graph.primsMinSpanningTree();
    graph.DijkstrasAlgo(0);

    return 0;
}