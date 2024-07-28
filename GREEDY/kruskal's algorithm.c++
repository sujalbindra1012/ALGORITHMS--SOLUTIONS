#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<pair<int, pair<int, int>>> viii;

int find(int u, vector<int> &parent)
{
    if (parent[u] < 0)
        return u;
    return find(parent[u], parent);
}

void unionbyweight(int u, int v, vector<int> &parent)
{
    int pu = find(u, parent);
    int pv = find(v, parent);
    if (pu != pv)
    {
        if (parent[pu] < parent[pv])
        {
            parent[pu] += parent[pv];
            parent[pu] = pv;
        }
        else
        {
            parent[pv] += parent[pu];
            parent[pu] = pv;
        }
    }
}

viii kruskals(viii g, int v)
{
    viii res;
    int s, d, w;
    vector<int> parent(v);
    for (int i = 0; i < v; i++)
    {
        parent[i] = -1;
    }
    sort(g.begin(), g.end());

    int e = g.size();
    for (int i = 0; i < e; i++)
    {
        s = g[i].second.first;
        d = g[i].second.second;
        w = g[i].first;
        if (find(s, parent) != find(d, parent))
        {
            res.push_back(g[i]);
            unionbyweight(s, d, parent);
        }
    }
    return res;
}

int main()
{
    viii res, g;
    int v, e, w, s, d;
    cout << "enter the value of vertices and edges : ";
    cin >> v >> e;
    cout << endl;
    cout << "enter the start and destination edges and weight :" << endl;
    for (int i = 0; i < e; i++)
    {
        cin >> s >> d >> w;
        g.push_back(make_pair(w, make_pair(s, d)));
    }
    res = kruskals(g, v);
    int sum = 0;
    for (int i = 0; i < res.size(); i++)
    {
        int w = res[i].first;
        cout << res[i].second.first << " " << res[i].second.second << endl;
        sum += w;
    }
    cout << "Total sum of weights : " << sum << endl;
}