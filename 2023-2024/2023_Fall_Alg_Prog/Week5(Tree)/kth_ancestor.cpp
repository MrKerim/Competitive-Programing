#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int> > tree,ancestor;

void dfs(int node,int parent = 0){
    ancestor[node][0] = parent;
    for(int i = 1; i < ancestor[node].size();i++) ancestor[node][i] = ancestor[ ancestor[node][i-1] ][i-1];
    for(int neighbor: tree[node]) if(neighbor!=parent) dfs(neighbor,node);
}

int log2(int n){ int count = -1; while(n>0) {n>>=1; count++;} return count; }

int find_kth_ancestor(int node, int k){
    for(int i = log2(n);i>=0;i--){
        if((1<<i)<=k ){
            node = ancestor[node][i];
            k-=(1<<i);
        }
    }
    return node;
}

int32_t main(){
    int q; cin>>n>>q;

    //initializing the tree
    tree.assign(n + 1,vector<int>());
    for(int i= 0; i<n-1;i++){
        int a,b;cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    ancestor.assign(n + 1, vector<int>(log2(n) + 1, 0));
    dfs(1);

    while(q--){
        int node,k; cin>>node>>k;
        int res = find_kth_ancestor(node,k);
        if(res!=0) cout<<res<<endl;
        else cout<<-1<<endl;

    }

    return 0;
}