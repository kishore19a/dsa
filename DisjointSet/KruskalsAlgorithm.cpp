#include <iostream>
#include <vector>
#include <algorithm>
#include "UnionFind.h"

struct Edge
{
    int beg, end, weight;
    Edge(int beg, int end, int weight) : beg(beg), end(end), weight(weight) {}
};

int KruskalsAlgorithm(std::vector<Edge>& graph, int numVertices)
{
    std::sort(graph.begin(), graph.end(), [](const Edge& x, const Edge& y){
        return (x.weight < y.weight);
    });

    UnionFind disjointSet(numVertices);
    int s{0}, res{0};
    for (int i = 0; i < graph.size() || s < numVertices-1; i++)
    {
        Edge e = graph[i];

        int xRep = disjointSet.findWithPathCompression(e.beg);
        int yRep = disjointSet.findWithPathCompression(e.end);

        if(xRep == yRep)
            continue;
        else
        {
            disjointSet.UnionByRankAndFindWithPathCompression(xRep, yRep);
            s++;
            res += e.weight;
        }
    }
    
    return res;
}

int main(int argc, char const *argv[])
{
    // Construct the tree from edges
    int numEdges{7}, numVertices{5};
    std::vector<Edge> graph;
    
    graph.push_back({1, 3, 3});
    graph.push_back({1, 2, 5});
    graph.push_back({0, 1, 10});
    graph.push_back({3, 4, 15});
    graph.push_back({0, 2, 8});
    graph.push_back({2, 3, 4});
    graph.push_back({2, 4, 12});

    int weightOfMinimumSpanningTree = KruskalsAlgorithm(graph, numVertices);
    std::cout << "Weight of minimum spanning tree = " << weightOfMinimumSpanningTree << std::endl;

    return 0;
}
