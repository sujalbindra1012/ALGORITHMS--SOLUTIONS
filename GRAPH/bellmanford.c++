#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> bellman_ford(int src, int v, vector<vector<pair<int, int>>> &g)
{
    vector<int> dist(v, INT_MAX);
    dist[src] = 0;
    vector<int> parent(v, 0);

    for (int i = 0; i < v; i++)
    {
        parent[i] = i;
    }

    for (int i = 0; i < v - 1; i++)
    {
        for (int u = 0; u < v; u++)
        {
            for (const auto &e : g[u])
            {
                int v = e.second;
                int w = e.first;
                if (dist[u] != INT_MAX && dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    parent[v] = u;
                }
            }
        }
    }

    // Check for negative weight cycles
    for (int u = 0; u < v; u++)
    {
        for (const auto &e : g[u])
        {
            int v = e.second;
            int w = e.first;
            if (dist[u] != INT_MAX && dist[v] > dist[u] + w)
            {
                cout << "Negative cycle detected" << endl;
                return {};
            }
        }
    }

    return dist;
}

int main()
{
    int v, e;
    cout << "Enter the number of vertices: ";
    cin >> v;
    cout << "Enter the number of edges: ";
    cin >> e;

    vector<vector<pair<int, int>>> graph(v);
    cout << "Enter the edges (start destination weight):" << endl;
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(w, v));
        graph[v].push_back(make_pair(w, u)); // If the graph is undirected
    }

    int src;
    cout << "Enter the source vertex: ";
    cin >> src;

    vector<int> dist = bellman_ford(src, v, graph);

    if (!dist.empty())
    {
        cout << "Vertex distances from source:" << endl;
        for (int i = 0; i < v; i++)
        {
            if (dist[i] == INT_MAX)
                cout << "Vertex " << i << ": INF" << endl;
            else
                cout << "Vertex " << i << ": " << dist[i] << endl;
        }
    }

    return 0;
}
