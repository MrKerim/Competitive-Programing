#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

void DFS(int north_node,const vector<vector<int> > &graph,vector<bool>& visitied,stack<int> &Stack){
    visitied[north_node] = true;
    for(int neighbor : graph[north_node]){
        if(!visitied[neighbor]) DFS(neighbor,graph,visitied,Stack);
    }

    Stack.push(north_node);
}

int Count_SCC(int N,const vector<vector<int> >& graph, const vector<vector<int> > &transpose){

    stack<int> Stack;
    vector<bool> visited(N,false);
    for (int north_node = 0; north_node < N; north_node++)
    {   
        if(!visited[north_node]) DFS(north_node,graph,visited,Stack);
    }

    fill(visited.begin(),visited.end(),false);

    int count = 0;
    while(!Stack.empty()){
        int north_node = Stack.top();
        Stack.pop();

        if(!visited[north_node]){ DFS(north_node,transpose,visited,Stack); count++; }
    }
    return count;
}

int32_t main(){
    int n,s;cin>>n>>s;
    vector<vector<int> > graph(n+s);
    vector<vector<int> > transpose(n+s);
    for(int i = 0;i<n-1;i++){
        graph[i].push_back(i+1);
        transpose[i+1].push_back(i);
    }
    for (int i = n ; i < n+s-1; i++)
    {
        graph[i].push_back(i+1);
        transpose[i+1].push_back(i);
    }

    // Getting the portal values and assign them to heao
    // SO that we can acces elements in the increasing order
    int p;cin>>p;
    vector< priority_queue<int> > portals(n);
    while(p--){
        int a,b;cin>>a>>b;
        a--; b+=n-1;
        portals[a].push(b);
    }


    int south_max = -1;
    int north_max = -1;
    for(int north_node = 0;north_node < n;north_node ++){
        while(!portals[north_node].empty()){
            int south_node = portals[north_node].top();
            portals[north_node].pop();
            if(south_node > south_max) {

                if(north_node>north_max){
                // There is no crossection
                // Then this node is a type
                graph[south_node].push_back(north_node);
                transpose[north_node].push_back(south_node);
                south_max = south_node;
                }
                else{
                // There is a crossection
                graph[north_node].push_back(south_node);
                transpose[south_node].push_back(north_node);
                }
            }
            else {
                // There is a crossection
                // This node is type b
                graph[north_node].push_back(south_node);
                transpose[south_node].push_back(north_node);
            }
            north_max = north_node;
        }
    }


    cout<<Count_SCC(n+s,graph,transpose)<<endl;

    


}