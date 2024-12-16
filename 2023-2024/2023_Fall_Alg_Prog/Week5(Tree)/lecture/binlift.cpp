#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;

vector<vector<int>> tree, blift;

void dfs(int v, int p = 0){
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

    dfs(1);

    cout << find_kth(5, 5);
}