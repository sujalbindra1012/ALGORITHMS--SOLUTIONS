#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<pair<int, int>> activities;
    cout<<"enter number of opeartions : ";
    int n;
    cin>>n;
    cout<<endl;
    cout<<"enter value of activites : ";
    for(int i=0;i<n;i++){
        int start,end;
        cin>>start>>end;
        activities.push_back(make_pair(end,start));
    }
    sort(activities.begin(),activities.end());
    int count=0;
    int endtime=-1;
    for(int i=0;i<n;i++){
        if(activities[i].second>endtime){
            count++;
            endtime=activities[i].first;
        }
    }
    cout<<"maximum activities done are : "<<count<<endl;

}