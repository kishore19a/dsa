#include <iostream>
#include <vector>
#include <queue>
#include <stack>

void BFS(std::vector<std::vector<int>>& adjList, std::vector<bool>& visited, int node)
{
    std::queue<int> bfsTrav;
    bfsTrav.push(node);
    visited[node] = true;

    while (!bfsTrav.empty())
    {
        int front = bfsTrav.front();
        bfsTrav.pop();

        std::cout << front << " ";

        for(auto neb : adjList[front])
        {
            if(!visited[neb])
            {
                bfsTrav.push(neb);
                visited[neb] = true;
            }
        }
    }    
}

void CBFS(std::vector<std::vector<int>>& adjList)
{
    std::vector<bool> visited(adjList.size(), false);

    for(int i = 1; i < adjList.size(); i++)
        if(!visited[i])
            BFS(adjList, visited, i);
}

void DFS(std::vector<std::vector<int>>& adjList, std::vector<bool>& visited, int node)
{
    visited[node] = true;
    std::cout << node << " ";

    for(auto neb : adjList[node])
        if(!visited[neb])
            DFS(adjList, visited, neb);
}

void CDFS(std::vector<std::vector<int>>& adjList)
{
    std::vector<bool> visited(adjList.size(), false);

    for(int i = 1; i < adjList.size(); i++)
        if(!visited[i])
            DFS(adjList, visited, i);
}

bool cycleBFS(std::vector<std::vector<int>>& adjList, std::vector<bool>& visited, int node)
{
    std::queue<std::pair<int, int>> bfsTrav;
    bfsTrav.push({node, -1});
    visited[node] = true;

    while (!bfsTrav.empty())
    {
        auto front = bfsTrav.front();
        bfsTrav.pop();

        for(auto neb : adjList[front.first])
        {
            if(!visited[neb])
            {
                bfsTrav.push({neb, front.first});
                visited[neb] = true;
            }
            else
            {
                if(neb != front.second)
                    return true;
            }
        }
    }    

    return false;
}

bool detectCycleBFS(std::vector<std::vector<int>>& adjList)
{
    std::vector<bool> visited(adjList.size(), false);

    for(int i = 1; i < adjList.size(); i++)
        if(!visited[i])
            if(cycleBFS(adjList, visited, i))
                return true;

    return false;
}

bool cycleDFS(std::vector<std::vector<int>>& adjList, std::vector<bool>& visited, int node, int parent)
{
    visited[node] = true;

    for(auto neb : adjList[node])
    {
        if(!visited[neb])
        {
            visited[neb] = true;
            if(cycleDFS(adjList, visited, neb, node)) 
                return true;
        }
        else
            if(neb != parent)
                return true;
    }

    return false;
}

bool detectCycleDFS(std::vector<std::vector<int>>& adjList)
{
    std::vector<bool> visited(adjList.size(), false);

    for(int i = 1; i < adjList.size(); i++)
        if(!visited[i])
            if(cycleDFS(adjList, visited, i, -1))
                return true;

    return false;
}

bool isBipartite(std::vector<std::vector<int>>& adjList)
{
    std::vector<int> visited(adjList.size(), -1);
    std::queue<int> bptTrav;
    bptTrav.push(1);
    visited[1] = 0;

    while (!bptTrav.empty())
    {
        int front = bptTrav.front();
        bptTrav.pop();

        for(auto neb : adjList[front])
        {
            if(visited[neb] == -1)
            {
                visited[neb] = (visited[front] + 1) % 2;
                bptTrav.push(neb);
            }
            else
            {
                if(visited[neb] == visited[front])
                    return false;
            }
        }
    }   

    return true;
}

bool cycleDetDirDfs(std::vector<std::vector<int>>& adjList, int node, std::vector<bool>& visited, std::vector<bool>& visitedDfs)
{
    visited[node] = true;
    visitedDfs[node] = true;

    for(auto neb : adjList[node])
    {
        if(!visited[neb])
        {
            if(cycleDetDirDfs(adjList, neb, visited, visitedDfs))
                return true;
        }
        else if(visitedDfs[neb])
        {
            return true;
        }
    }

    visitedDfs[node] = false;
    return false;
}

bool cycleDetectionDirected(std::vector<std::vector<int>>& adjList)
{
    std::vector<bool> visited(adjList.size(), false);
    std::vector<bool> visitedDfs(adjList.size(), false);

    for(int i = 1; i < adjList.size(); i++)
        if(!visited[i])
            if(cycleDetDirDfs(adjList, i, visited, visitedDfs))
                return true;

    return false;
}

void tpsDfs(std::vector<std::vector<int>>& adjList, std::vector<bool>& visited, int node, std::stack<int>& tps)
{
    visited[node] = true;

    for(auto neb : adjList[node])
        if(!visited[neb])
            tpsDfs(adjList, visited, neb, tps);

    tps.push(node);
}

void topologicalSortDfs(std::vector<std::vector<int>>& adjList)
{
    std::vector<bool> visited(adjList.size(), false);
    std::stack<int> tps;

    for(int i = 1; i < adjList.size(); i++)
        if(!visited[i])
            tpsDfs(adjList, visited, i, tps);

    while(!tps.empty())
    {
        int x = tps.top();
        tps.pop();
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

void tpsBfsKahn(std::vector<std::vector<int>>& adjList, int node, std::vector<int>& indegree)
{
    std::queue<int> tpsTrav;
    tpsTrav.push(node);

    while (!tpsTrav.empty())
    {
        int front = tpsTrav.front();
        tpsTrav.pop();
        std::cout << front << " ";

        for(auto neb : adjList[front])
        {
            indegree[neb]--;
            if(indegree[neb] == 0)
                tpsTrav.push(neb);
        }            
    }    
}

bool topologicalSortBfs(std::vector<std::vector<int>> adjList)
{
    std::vector<int> indegree(adjList.size(), 0);

    for(auto vec : adjList)
        for(auto x : vec)
            indegree[x]++;

    for(int i = 1; i < adjList.size(); i++)
        if(indegree[i] == 0)
            tpsBfsKahn(adjList, i, indegree);
    std::cout << std::endl;

    for(auto x : indegree)
        if(x > 0)
            return true;

    return false;
}

int main(int argc, char const *argv[])
{
    int d, n, m; // n = number of nodes , m = number of edges
    std::cin >> d >> n >> m;

    std::vector<std::vector<int>> adjList;
    adjList.resize(n+1);

    if(d)
    {
        for(int i = 0; i < m; i++)
        {
            int u, v;
            std::cin >> u >> v;

            adjList[u].push_back(v);
        }

        std::cout << "----------------- Check if cycle present in directed graph -------------------" << std::endl;
        if(cycleDetectionDirected(adjList))   
            std::cout << "Is cycle present in this directed graph? Yes" << std::endl;
        else
            std::cout << "Is cycle present in this directed graph? No" << std::endl;

        std::cout << "----------------- Print topological sort of directed graph using DFS -------------------" << std::endl;
        topologicalSortDfs(adjList);

        std::cout << "----------------- Print topological sort of directed graph using BFS - KAHN'S ALGORITHM -------------------" << std::endl;
        if(topologicalSortBfs(adjList))
            std::cout << "Is cycle present in this directed graph - using Kahn's Algo? Yes" << std::endl;
        else
            std::cout << "Is cycle present in this directed graph - using Kahn's Algo? No" << std::endl;
    }
    else
    {
        for(int i = 0; i < m; i++)
        {
            int u, v;
            std::cin >> u >> v;

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        std::cout << "----------------- BFS of the given graph -------------------" << std::endl;
        CBFS(adjList);
        std::cout << std::endl;

        std::cout << "----------------- DFS of the given graph -------------------" << std::endl;
        CDFS(adjList);
        std::cout << std::endl;

        std::cout << "----------------- Check if cycle present in graph using BFS -------------------" << std::endl;
        if(detectCycleBFS(adjList))   
            std::cout << "Is cycle present in graph? Yes" << std::endl;
        else
            std::cout << "Is cycle present in graph? No" << std::endl;

        std::cout << "----------------- Check if cycle present in graph using DFS -------------------" << std::endl;
        if(detectCycleDFS(adjList))   
            std::cout << "Is cycle present in graph? Yes" << std::endl;
        else
            std::cout << "Is cycle present in graph? No" << std::endl;

        std::cout << "----------------- Check if graph Bipartite graph using BFS -------------------" << std::endl;
        if(isBipartite(adjList))   
            std::cout << "Is the graph bipartite? Yes" << std::endl;
        else
            std::cout << "Is the graph bipartite? No" << std::endl;

    }

    return 0;
}
