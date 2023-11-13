#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
#define int long long

int32_t main() {
    int n, m;
    cin >> n >> m;
    vector< vector<int> > adj(n);
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 0; i < n; i++) {
        sort(adj[i].begin(), adj[i].end());
        reverse(adj[i].begin(), adj[i].end());
    }
    stack < pair<int, vector<int> > > dfs;
    dfs.push({0, {0}});
    vector<bool> visited(n, false);
    vector< vector<int> > paths(n);
    while (!dfs.empty()) {
        int curr = dfs.top().first;
        vector<int> path = dfs.top().second;
        cout << curr << ": ";
        for (auto x: path) {
            cout << x << " ";
        }
        cout << endl;
        dfs.pop();
        if (visited[curr]) continue;
        visited[curr] = true;
        paths[curr] = path;
        for (auto x: adj[curr]) {
            vector<int> new_path = path;
            new_path.push_back(x);
            dfs.push({x, new_path});
        }
    }
    for (int i = 0; i < n; i++) {
        cout << i << ": ";
        for (auto x: paths[i]) {
            cout << x << " ";
        }
        cout << endl;
    }
}