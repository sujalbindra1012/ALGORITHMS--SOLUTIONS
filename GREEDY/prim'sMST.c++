#include <iostream>
#include <vector>
#include <queue>
#include <climits> // for INT_MAX
using namespace std;

int primMST(int src, int v, vector<vector<pair<int, int>>> &graph)
{
    vector<int> dist(v, INT_MAX);
    vector<int> parent(v, -1);
    vector<bool> visited(v, false);

    // Priority queue to find the minimum weight edge
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if (visited[u])
            continue;

        visited[u] = true;

        for (const auto &neighbor : graph[u])
        {
            int weight = neighbor.first;
            int v = neighbor.second;

            if (!visited[v] && dist[v] > weight)
            {
                dist[v] = weight;
                parent[v] = u;
                pq.push(make_pair(weight, v));
            }
        }
    }

    int result = 0;
    for (int i = 0; i < v; i++)
    {
        result += dist[i];
    }

    // Optional: print the MST edges
    /*
    cout << "Edges in MST:" << endl;
    for (int i = 1; i < v; i++) {
        cout << parent[i] << " - " << i << endl;
    }
    */

    return result;
}

int main()
{
    int v, e;
    cout << "Enter the number of vertices: ";
    cin >> v;
    cout << "Enter the number of edges: ";
    cin >> e;

    vector<vector<pair<int, int>>> graph(v);
    cout << "Enter the edges (u v w):" << endl;
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(w, v));
        graph[v].push_back(make_pair(w, u));
    }

    int src;
    cout << "Enter the source element: ";
    cin >> src;

    cout << "Total weight of MST: " << primMST(src, v, graph) << endl;
    return 0;
}
