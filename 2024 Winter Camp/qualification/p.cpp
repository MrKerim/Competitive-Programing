#include <iostream>
#include <vector>
#include <map>
#include <stack>
#define MOD 1000000007
#define int long long
using namespace std;
int nodes[1000007];
int dfs(map<int,vector<int> > &graph,int n){
    stack<int> q;
    q.push(n);
    int sum = 0;
    while (!q.empty())
    {
        int node = q.top(); q.pop();
        nodes[node] = nodes[node]%MOD + 1;  if(graph[node].size() == 0) sum = (sum+ nodes[node])%MOD;
        else for (auto x: graph[node]){nodes[x] = nodes[node]; q.push(x);}
    }
    return sum;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n >> m;
    map<int,vector<int> > graph;
    for (int i = 0; i < m; i++) {int x,y; cin>>x>>y; graph[y].push_back(x);}
    cout<<dfs(graph,n)<<endl;
}