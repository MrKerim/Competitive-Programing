#include <iostream>
#include <vector>
#include <queue>
#define Iamspeed ios::sync_with_stdio(0); cin.tie(0);
#define int long long
using namespace std;

bool visited[100005];

void BFS(int start,vector<vector<int> > graph){

    queue<int> que;
    que.push(start);
    visited[start] = true;

    while (!que.empty())
    {
        int curr_node = que.front();
        que.pop();

        for(int neighbor: graph[curr_node]){
            if(!visited[neighbor]){
                visited[neighbor] = true;
                que.push(neighbor);
            }
        }
    }
    

}

int32_t main(){
    Iamspeed
    int v,e; cin>>v>>e;
    v=100000;
    e=99999;
    vector<vector< int > > graph(100000);
    for (int i = 0; i < e; i+=2)
    {
        int node_from; cin>>node_from;
        int node_to; cin>>node_to;
        graph[i+1].push_back(i+2);
        graph[i+2].push_back(i+1);
    }


    int num_city = 0;
    // We will visit ower every node and if it's not visited before we add it to the cities.

    for (int n = 1; n <= v; n++)
    {

        if(!visited[n]){
            num_city++;
            BFS(n,graph);
        }
    }
    cout<<num_city<<endl;
    
    

    return 0;
}