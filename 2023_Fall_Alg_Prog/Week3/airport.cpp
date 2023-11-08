#include <iostream>
#include <vector>
#include <queue>
#define Iamspeed ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define INF 1e18
using namespace std;

vector<int> dijkstra(int start,int end,const vector<vector<pair<int,int> > > &graph,vector<int> distance, vector<int> landing_cost){

    priority_queue< pair<int,int> , vector<pair<int,int> >, greater<pair<int,int> > > pq;
    pq.push(make_pair(0,start));
    while(!pq.empty()){
        int current_distance = pq.top().first;
        int current_node = pq.top().second;
        pq.pop();

        if (current_distance > distance[current_node]) continue;
        for(pair<int,int> neighbor: graph[current_node]){
            if(distance[current_node] + neighbor.first + landing_cost[neighbor.second] < distance[neighbor.second])
            {
                distance[neighbor.second] = distance[current_node] + neighbor.first + landing_cost[neighbor.second];
                pq.push(make_pair(distance[neighbor.second],neighbor.second));
            }
        }
    }

    return distance;

}

int32_t main(){
    int v,e;cin>>v>>e;
    vector<vector< pair<int,int> > > graph(v+1);
    for (int i = 0; i < e; i++)
    {
        int node_from,node_to,cost;
        cin>>node_from>>node_to>>cost;
        graph[node_from].push_back(make_pair(cost,node_to));
        graph[node_to].push_back(make_pair(cost,node_from));
    }

    vector<int> landing_cost(v+1);
    for (int i = 1; i <= v; i++)
    {
        cin>>landing_cost[i];
    }
    int start,end;cin>>start>>end;
    vector< int > distance(v+1,INF);
    distance[start] = 0;


    vector<int> result = dijkstra(start,end,graph,distance,landing_cost);
    if(result[end] == INF){cout<<-1<<endl; return 0;}
    cout<<result[end]<<endl;

    return 0;
}