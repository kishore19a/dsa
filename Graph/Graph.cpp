#include <iostream>
#include <vector>
#include <queue>

class Graph
{
public:
    Graph(int numVertices)
      : _numVertices(numVertices)
    {
        _adjList.resize(numVertices);
    }

    ~Graph() {}

    void addEdge(int u, int v);
    void BSF(int startIndex);
    void DFS(int index, std::vector<bool>& visited);

    void shortestPathToEachVertex(int startIndex);
    bool detectCycle(int index, int parent, std::vector<bool>& visited);

private:
    int _numVertices;
    std::vector<std::vector<int>> _adjList;
};

void Graph::addEdge(int u, int v)
{
    _adjList[u].push_back(v);
    _adjList[v].push_back(u);
}

void Graph::BSF(int startIndex)
{
    std::cout << "BFS of the given graph: " << std::endl;
    std::vector<bool> visited(_numVertices, false);
    std::queue<int> travQ;
    travQ.push(startIndex);
    visited[startIndex] = true;

    while (!travQ.empty())
    {
        int u = travQ.front();
        travQ.pop();

        std::cout << u << " ";

        for(auto v : _adjList[u])
        {
            if(!visited[v])
            {
                travQ.push(v);
                visited[v] = true;
            }
        }
    }
    
    std::cout << std::endl;
}

void Graph::DFS(int index, std::vector<bool>& visited)
{
    std::cout << index << " ";
    visited[index] = true;

    for(auto v : _adjList[index])
        if(!visited[v])
            DFS(v, visited);
}

bool Graph::detectCycle(int index, int parent, std::vector<bool>& visited)
{
    visited[index] = true;

    for(auto v : _adjList[index])
    {
        if(!visited[v])
        {
            if(detectCycle(v, index, visited))
                return true;
        }
        else if(v != parent) return true;
    }

    return false;
}

void Graph::shortestPathToEachVertex(int startIndex)
{
    std::cout << "Finding shortest path length to each vertex starting from " << startIndex << ":" << std::endl;
    std::vector<bool> visited(_numVertices, false);
    std::vector<int> pathLength(_numVertices, 0);

    std::queue<int> travQ;
    travQ.push(startIndex);
    visited[startIndex] = true;

    while (!travQ.empty())
    {
        int u = travQ.front();
        travQ.pop();

        std::cout << startIndex << " -- " << u << " = " << pathLength[u] << std::endl;

        for(auto v : _adjList[u])
        {
            if(!visited[v])
            {
                travQ.push(v);
                pathLength[v] = 1 + pathLength[u];
                visited[v] = true;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int numVertices{4};

    Graph graph(numVertices);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(1, 3);

    graph.BSF(0);

    std::cout << "DFS of the given graph: " << std::endl;
    std::vector<bool> dfsVisited(numVertices, false);
    graph.DFS(0, dfsVisited);
    std::cout << std::endl;

    graph.shortestPathToEachVertex(0);

    std::vector<bool> cycleVisited(numVertices, false), reccStack(numVertices, false);
    if(graph.detectCycle(0, -1, cycleVisited))
        std::cout << "Cycle detected" << std::endl;
    else
        std::cout << "Cycle not detected" << std::endl;

    return 0;
}
