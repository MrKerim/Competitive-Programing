#include <bits/stdc++.h>

using namespace std;

int n, q, qt, a, b;

vector<int> p, sz;
vector<vector<int>> nodes;

int find(int a){
    if(a == p[a]) return a;
    else return p[a] = find(p[a]);
}

void unite(int a, int b){
    a = find(a), b = find(b);

    if(a != b){
        if(sz[b] > sz[a]) swap(a, b);

        p[b] = a;
        sz[a] += sz[b];

        for(auto x : nodes[b]) nodes[a].push_back(x);
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    cin >> n >> q;

    p = sz = vector(n + 1, 0);

    nodes.assign(n + 1, {});

    for(int i = 1; i <= n; i++){
        p[i] = i;
        sz[i] = 1;

        nodes[i] = {i};
    }

    while(q--){
        cin >> qt;

        if(qt == 1){
            cin >> a >> b;

            unite(a, b);
        }
        else if(qt == 2){
            cin >> a >> b;
            if(find(a) == find(b)) cout << "YES\n";
            else cout << "NO\n";
        }
        else if(qt == 3){
            cin >> a;

            cout << sz[find(a)] << "\n";
        }
        else if(qt == 4){
            cin >> a;

            a = find(a);

            for(auto x : nodes[a]) cout << x << " ";
            cout << "\n";
        }
    }
} 
