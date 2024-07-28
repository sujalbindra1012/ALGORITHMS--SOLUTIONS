#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int prim(int src,int v,vector<vector<pair<int,int>>>&graph){
    vector<int>dist(v,INT_MAX);
    vector<int>parent(v,0);
    vector<int>visited(v,0);

    for(int i=0;i<v;i++){
        parent[i]=i;
    }

    //priority queue is used to find the minimum wt edge
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push(make_pair(0,src));
    dist[src]=0;
    while(!pq.empty()){
        pair<int,int>p=pq.top();
        pq.pop();

        if(visited[p.second]==0){
            visited[p.second]=1;

            vector<pair<int,int>>::iterator it;
            for(it=graph[p.second].begin();it!=graph[p.second].end();it++){
                if(visited[it->second]==0 && dist[p.second]!=INT_MAX && dist[it->second]>it->first){
                    parent[it->second]=p.second;
                    dist[it->second]=it->first;
                    pq.push(*it);
                }
            }
        }
    }
    int result =0;
    for(int i=0;i<v;i++){
        result+=dist[i];
    }
    cout<<endl;
    return result;

}

int main(){
    int v,e;
    cout<<"enter the number of vertices  :";
    cin>>v;
    cout<<endl;
    cout<<"enter the number  of edges : ";
    cin>>e;

    vector<vector<pair<int,int>>>graph(v);
    cout<<endl;
    cout<<"enter the start,destination and weight : ";
    for(int i=0;i<e;i++){
        int u,v,w;
        cin>>u,v,w;
        graph[u].push_back(make_pair(w,v));
        graph[v].push_back(make_pair(w,u));
    }
    int source ;
    cout<<endl;
    cout<<"enter the source element ";
    cin>>source;

    cout<<prim(source,v,graph)<<endl;
    return 0;
}