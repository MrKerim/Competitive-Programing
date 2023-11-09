#include <bits/stdc++.h>

using namespace std;

int n;

vector<vector<int>> tree, blift;

vector<int> depth;

void dfs(int v, int p = 0){
    depth[v] = depth[p] + 1;

    blift[v][0] = p;
    for(int i = 1; i < blift[v].size(); i++) blift[v][i] = blift[blift[v][i - 1]][i - 1];

    for(auto e : tree[v]) if(e != p) dfs(e, v);
}

int find_kth(int v, int k){
    for(int i = __lg(n); i >= 0; i--){
        if((1 << i) <= k){
            v = blift[v][i];

            k -= (1 << i);
        }
    }

    return v;
}

int lca(int a, int b){
    if(depth[b] > depth[a]) swap(a, b);

    for(int i = __lg(n); i >= 0; i--){
        if(depth[blift[a][i]] >= depth[b]){
            a = blift[a][i];
        }
    }

    if(a == b) return a;

    for(int i = __lg(n); i >= 0; i--){
        if(blift[a][i] != blift[b][i]){
            a = blift[a][i], b = blift[b][i];
        }
    }

    return blift[a][0];
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    cin >> n;

    tree.assign(n + 1, {});

    for(int i = 0; i < n - 1; i++){
        int a, b;

        cin >> a >> b;

        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    blift.assign(n + 1, vector(__lg(n) + 1, 0));

    depth.assign(n + 1, 0);

    dfs(1);
}