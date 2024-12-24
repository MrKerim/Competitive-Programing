int diameter = 0;

int dfs(int current,vector<bool>& visited,unordered_map<int,vector<int> >& tree){

    priority_queue<int> pq;
    for(int neighbor : tree[current]) if(!visited[neighbor]){
        visited[neighbor] = true;
        pq.push(dfs(neighbor,visited,tree) + 1);
    }

    int max_d = 0;
    if(!pq.empty()){ max_d = pq.top(); pq.pop();}
    int secon_max_d = 0;
    if(!pq.empty()) {secon_max_d = pq.top(); pq.pop();}
    diameter = max(diameter,max_d + secon_max_d);
    return max_d;
}

class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        unordered_map<int,vector<int>> tree1;
        unordered_map<int,vector<int>> tree2;

        int n = -1;
        int m = -1;

        for(auto v:edges1){
            n = max(n,max(v[0],v[1]));
            tree1[v[0]].push_back(v[1]);
            tree1[v[1]].push_back(v[0]);
        }

        for(auto v:edges2){
            m = max(n,max(v[0],v[1]));
            tree2[v[0]].push_back(v[1]);
            tree2[v[1]].push_back(v[0]);
        }

        int d1;
        if(n!=-1){
        diameter = 0;
        vector<bool> visited(n+1,false);
        visited[0] = true;
        int temp = dfs(0,visited,tree1);
        d1 = diameter;
        }
        else d1 = 0;

        int d2;
        if(m!=-1){
        diameter = 0;
        vector<bool> visited1(m+1,false);
        visited1[0] = true;
        int temp1 = dfs(0,visited1,tree2);
        d2 = diameter;
        }
        else d2 = 0;

        cout<<d1<<d2<<(d2+1)/2+(d1+1)/2+1;

        return max(max(d1,d2),(d2+1)/2+(d1+1)/2+1);
    }
};