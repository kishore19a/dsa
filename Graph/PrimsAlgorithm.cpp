#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int spanningTree(int V, vector<vector<int>> adj[])
{
    std::vector<int> weight(V, INT_MAX);
    std::vector<bool> MST(V, false);
    
    weight[0] = 0;
    
    for(int i = 0; i < V; i++)
    {
        int min{INT_MAX}; int u;

        for(int j = 0; j < V; j++)
        {
            std::cout << weight[j] << " ";
        }
        std::cout << std::endl;

        for(int j = 0; j < V; j++)
        {
            if(!MST[j] && weight[j] < min)
            {
                min = weight[j];
                u = j;
            }
        }
        
        std::cout << "Selected u = " << u << std::endl;
        MST[u] = true;
        
        for(int j = 0; j < adj[u].size(); j++)
        {
            int v = adj[u][j][0];
            int w = adj[u][j][1];
            if(!MST[v] && weight[v] > w)
            {
                weight[v] = w;
            }
        }
    }
    
    int res{0};
    for(int i = 0; i < V; i++)
        res += weight[i];
        
    return res;
}

int main(int argc, char const *argv[])
{
    std::vector<std::vector<int>> adj[3];

    adj[0].push_back({1, 5});
    adj[1].push_back({0, 5});
    adj[0].push_back({2, 1});
    adj[2].push_back({0, 1});
    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});

    // for(int u = 0; u < 3; u++)
    // {
    //     for(int j = 0; j < adj[u].size(); j++)
    //     {
    //         int v = adj[u][j][0];
    //         int w = adj[u][j][1];
    //         std::cout << u << " " << v << " " << w << std::endl;
    //         // if(!MST[v] && weight[v] > adj[u][j][1])
    //         // {
    //         //     weight[v] = adj[u][j][1];
    //         // }
    //     }
    // }

    int res  = spanningTree(3, adj);
    std::cout << " res  => "  << res << std::endl;

    return 0;
}
