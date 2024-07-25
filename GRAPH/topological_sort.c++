#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void topoSortUtils(vector<vector<int>> &graph, vector<bool> &visited, stack<int> &st, int i)
{
    visited[i] = true;
    int n = graph[i].size();
    for (int j = 0; j < n; j++)
    {
        if (!visited[graph[i][j]])
        {
            topoSortUtils(graph, visited, st, graph[i][j]);
        }
    }
    st.push(i);
}

void topoSort(vector<vector<int>> &graph, int nodes)
{
    vector<bool> visited(nodes, false);
    stack<int> st;
    for (int i = 0; i < nodes; i++)
    {
        if (!visited[i])
        {
            topoSortUtils(graph, visited, st, i);
        }
    }
    while (!st.empty())
    {
        cout << st.top() + 1 << " ";
        st.pop();
    }
}

int main()
{
    int nodes, edges;
    cout << "Enter the number of vertices and edges :";
    cin >> nodes >> edges;

    vector<vector<int>> graph(nodes);
    for (int i = 0; i < edges; i++)
    {
        int start, end;
        cin >> start >> end;
        graph[start - 1].push_back(end - 1);
    }

    topoSort(graph, nodes);
}