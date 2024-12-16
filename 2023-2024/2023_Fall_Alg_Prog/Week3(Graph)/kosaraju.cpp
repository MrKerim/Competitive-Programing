#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void DFS(int node,const vector<vector<int> > &graph,vector<bool>& visitied,stack<int> &Stack,bool is_stack_used){
    visitied[node] = true;
    for(int neighbor : graph[node]){
        if(!visitied[neighbor]) DFS(neighbor,graph,visitied,Stack,is_stack_used);
    }

    if(is_stack_used) Stack.push(node);
}

int Count_SCC(int N,const vector<vector<int> >& graph, const vector<vector<int> > &transpose){

    stack<int> Stack;
    vector<bool> visited(N,false);
    for (int node = 0; node < N; node++)
    {   
        if(!visited[node]) DFS(node,graph,visited,Stack,true);
    }

    fill(visited.begin(),visited.end(),false);

    int count = 0;
    while(!Stack.empty()){
        int node = Stack.top();
        Stack.pop();

        if(!visited[node]){ DFS(node,graph,visited,Stack,false); count++; }
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

    int p;cin>>p;
    while(p--){
        int a,b;cin>>a>>b;
        a--;b--;
        // a is higher than the b in the mountain:
        // meaning the directions is from b -> a
        if(a<b){
            b += n;
            graph[b].push_back(a);
        }
        else{
            b += n;
            graph[a].push_back(b);
        }
    }

    cout<<Count_SCC(n+s,graph,transpose)<<endl;

    


}