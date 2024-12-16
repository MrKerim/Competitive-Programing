#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define int long long

int32_t main() {
    int n, m;
    cin >> n >> m;
    vector< vector<int> > adj(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<bool> visited(n, false);
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if (!visited[i]) {
            queue<int> bfs;
            bfs.push(i);
            while (!bfs.empty()) {
                int curr = bfs.front();
                bfs.pop();
                if (visited[curr]) continue;
                visited[curr] = true;
                for (auto x: adj[curr]) {
                    bfs.push(x); 
                }
            }
            ans++;
        }
    }
    cout << ans << endl;
}