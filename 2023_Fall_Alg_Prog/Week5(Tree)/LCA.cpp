#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > tree,ancestor;
vector<int> depth;
int n;

void dfs(int node,int parent=0){
    depth[node] = depth[parent]+1;
    ancestor[node][0]=parent;

    for(int i=1;i<ancestor[node].size();i++){
        ancestor[node][i] = ancestor[ ancestor[node][i-1] ][i-1];
    }
    for(int neighbor : tree[node]) if(neighbor!=parent) dfs(neighbor,node);
}

int log2(int input){ int count = -1; while(input>0) {input>>=1; count++;} return count; }


int LCA(int node_a, int node_b){
    if(depth[node_b]>depth[node_a]) swap(node_a,node_b);
    for(int i = log2(n);i>=0;i--){
        if(depth[ancestor[node_a][i]]>=depth[node_b]) node_a=ancestor[node_a][i];
    }

    if(node_a==node_b) return node_a;

    for(int i= log2(n);i>=0;i--){
        if(ancestor[node_a][i]!=ancestor[node_b][i]) {node_a = ancestor[node_a][i]; node_b = ancestor[node_b][i];}
    }
    return ancestor[node_a][0];
}

int32_t main(){
    int q; cin>>n>>q;

    tree.assign(n + 1,vector<int>());

    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    ancestor.assign(n + 1, vector<int>(log2(n) + 1, 0));
    depth.assign(n + 1, 0);
    dfs(1);

    while(q--){
        int q_a,q_b;cin>>q_a>>q_b;
        int result = LCA(q_a,q_b);
        cout<<LCA(q_a,q_b)<<" "<<depth[q_a]+depth[q_b]-2*depth[result]<<endl;
    }




}