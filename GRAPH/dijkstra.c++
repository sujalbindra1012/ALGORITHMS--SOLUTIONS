#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

vector<int> dijkstra(int src, int v, vector<vector<pair<int, int>>> &graph)
{
    vector<int> dist(v, INT_MAX);
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while (!pq.empty())
    {
        pair<int, int> p = pq.top();
        pq.pop();

        int u = p.second;
        if (dist[u] < p.first)
        {
            continue;
        }
        for (const pair<int, int> &edges : graph[u])
        {
            int v = edges.second;
            int wt = edges.first;
            if (dist[v] > wt + dist[u])
            {
                dist[v] = wt + dist[u];
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main()
{
    int v, e;
    cout << "enter the value of vertices : ";
    cin >> v;
    cout << endl
         << "Enter the value of edges : ";
    cin >> e;

    vector<vector<pair<int, int>>> graph(v);
    cout << endl
         << "enter the value of start,destination and weight :";
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(w, v));
        graph[v].push_back(make_pair(w, u));
    }
    int src;
    cout << "enter the value of starting index : ";
    cin >> src;

    vector<int> dist = dijkstra(src, v, graph);

    cout << "Vertex distances from source:" << endl;
    for (int i = 0; i < v; i++)
    {
        cout << "Vertex " << i << ": " << dist[i] << endl;
    }

    return 0;
}
