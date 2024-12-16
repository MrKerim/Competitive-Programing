#include <bits/stdc++.h>

using namespace std;

int n, m, a, b;

vector<int> p, sz;

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
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    cin >> n >> m;

    p = sz = vector(n + 1, 0);

    for(int i = 1; i <= n; i++){
        p[i] = i;
        sz[i] = 1;
    }

    vector<array<int, 3>> edges;

    for(int i = 0; i < m; i++){
        int a, b, w;

        cin >> a >> b >> w;

        edges.push_back({w, a, b});
    }

    sort(edges.begin(), edges.end());

    for(auto [w, a, b] : edges){
        if(find(a) != find(b)){
            unite(a, b);

            cout << a << " " << b << " " << w << "\n";
        }
    }
}