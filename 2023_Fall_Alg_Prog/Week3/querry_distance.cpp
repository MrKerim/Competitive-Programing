#include <iostream>
#include <vector>
#include <queue>
#define Iamspeed ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define INF 1e18
using namespace std;

int dijkstra(int start, int end, const vector<vector<pair<int,int> > > &graph,vector<int> distance){
    distance[start] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int> > , greater<pair<int,int> > > pq;
    pq.push(make_pair(0,start));
    while(!pq.empty()){
        int current_node = pq.top().second;
        int current_distance = pq.top().first;
        pq.pop();
        if (current_distance > distance[current_node]) continue;
        for(pair<int,int> neighbor: graph[current_node]){
            if(distance[current_node] + neighbor.first < distance[neighbor.second]){
                distance[neighbor.second] = distance[current_node] + neighbor.first;
                pq.push(make_pair(distance[neighbor.second],neighbor.second));
            }
        }
    }

    if(distance[end]==INF) return -1;
    else return distance[end];

}


int32_t main(){
    Iamspeed
    int v,e,Q;cin>>v>>e>>Q;
    vector<vector<pair<int,int> > > graph(v+1);
    for(int i=0;i<e;i++){
        int node_from, node_to, cost; cin>>node_from>>node_to>>cost;
        graph[node_from].push_back(make_pair(cost,node_to));
        graph[node_to].push_back(make_pair(cost,node_from));
    }
    
    vector<int> distance(v+1,INF);

    for (int q = 0; q < Q; q++)
    {
        int start,end;cin>>start>>end;
        cout<<dijkstra(start,end,graph,distance)<<endl;
    }
    

    return 0;
}