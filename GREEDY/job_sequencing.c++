#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.first > b.first;
}

int main()
{
    int n;
    cout << "enter number of jobs : ";
    cin >> n;
    cout << endl;
    cout << "enter profit and deadline : ";
    vector<pair<int, int>> jobs;
    int profit, deadline;
    for (int i = 0; i < n; i++)
    {
        cin >> profit >> deadline;
        jobs.push_back(make_pair(profit, deadline));
    }
    sort(jobs.begin(), jobs.end(), compare);
    int maxendtime = 0;
    for (int i = 0; i < n; i++)
    {
        if (jobs[i].second > maxendtime)
        {
            maxendtime = jobs[i].second;
        }
    }
    int count = 0;
    int maxprofit = 0;
    int fill[10];
    for (int i = 0; i < maxendtime; i++)
    {
        fill[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        int j = jobs[i].second - 1;
        while (j >= 0 && fill[j] != -1)
        {
            j--;
        }
        while (j >= 0 && fill[j] == -1)
        {
            fill[j] = i;
            count++;
            maxprofit += jobs[i].first;
        }
    }
    cout << "no of jobs done :" << count << endl;
    cout << "profit earned :" << maxprofit << endl;
}