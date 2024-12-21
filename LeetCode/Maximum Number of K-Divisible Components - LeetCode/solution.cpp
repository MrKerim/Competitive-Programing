int res;
int k;

long long dfs(int i,unordered_map<int,vector<int>>& graph,vector<long long>& values,vector<bool>&visited,int k){
    visited[i] = true;
    long long sum = 0;
    for(int e :graph[i]){
        if(!visited[e]) sum += dfs(e,graph,values,visited,k);
    }
    values[i] = values[i] + sum;
    if(values[i]%k == 0) res++;
    return values[i];
}



class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        //init
        res = 0;

        unordered_map<int,vector<int>> graph;
        for(auto v : edges){
            graph[v[0]].push_back(v[1]);
            graph[v[1]].push_back(v[0]);
        }

        vector<long long> cumulativeValues(n,0);
        for(int i = 0;i<n;i++) cumulativeValues[i] = values[i];

        vector<bool> visited(n,false);
        long long temp = dfs(0,graph,cumulativeValues,visited,k);

        return res;
    }
};