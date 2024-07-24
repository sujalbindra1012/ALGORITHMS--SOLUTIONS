#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>> &graph, vector<bool> &visited, int u)
{
    visited[u] = true;
    cout << u << " ";

    for (auto v : graph[u])
    {
        if (!visited[v])
        {
            dfs(graph, visited, v);
        }
    }
}

int main()
{
    int nodes, edges;
    cout << "Enter the number of nodes and edges : ";
    cin >> nodes >> edges;

    cout << "\n";

    vector<vector<int>> graph(nodes);
    cout << "Enter the edges : ";
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u); // Undirected Graph
    }
    cout << "\n";
    int i;
    cout << "Enter the starting edge : ";
    cin >> i;

    vector<bool> visited(nodes);
    dfs(graph, visited, i);
}