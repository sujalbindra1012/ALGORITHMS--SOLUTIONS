#include <iostream>
#include <vector>
using namespace std;

void initialize(vector<int> &parent, vector<int> &rank, int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

int find(vector<int> parent, int x)
{
    if (parent[x] != x)
    {
        parent[x] = find(parent, parent[x]);
    }
    return parent[x];
}

void unionsets(vector<int> &parent, vector<int> &rank, int x, int y)
{
    int rootX = find(parent, x);
    int rootY = find(parent, y);

    if (rootX != rootY)
    {
        if (rank[rootX] > rank[rootY])
        {
            parent[rootY] = rootX;
        }
        else if (rank[rootX] < rank[rootY])
        {
            parent[rootX] = rootY;
        }
        else
        {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

void printParent(vector<int> &parent)
{
    for (int i = 0; i < parent.size(); i++)
    {
        cout << "Parent of " << i << " is " << parent[i] << endl;
    }
}

int main()
{
    int n;
    cout << "enter number of elements : ";
    cin >> n;

    vector<int> parent(n);
    vector<int> rank(n);

    initialize(parent, rank, n);

    unionsets(parent, rank, 0, 1);
    unionsets(parent, rank, 1, 2);
    unionsets(parent, rank, 3, 4);

    printParent(parent);

    cout << "Find(2): " << find(parent, 2) << endl;
    cout << "Find(3): " << find(parent, 3) << endl;
    cout << "Find(4): " << find(parent, 4) << endl;

    return 0;
}