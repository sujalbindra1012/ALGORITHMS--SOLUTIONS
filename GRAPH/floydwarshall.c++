#include <iostream>
#include <climits>
using namespace std;
#define INF INT_MAX

void floyd_warshall(int dist[10][10], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    cout << "matrix is :" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n, m;
    cout << "enter the number of elements ";
    cin >> n >> m;

    int dist[10][10];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> dist[i][j];
        }
    }
    floyd_warshall(dist, n, m);
}