void bfs(int r,int c,int n,int m,vector<vector<char>>& grid,vector<vector<bool>>& visited){
    
    visited[r][c] = true;
    queue<pair<int,int> > q;
    q.push({r,c});

    while(!q.empty()){
        int current_r = q.front().first;
        int current_c = q.front().second;
        q.pop();

        int dx[] = {-1, 0, 0, 1};
        int dy[] = {0, -1, 1, 0};

        for (int k = 0; k < 4; k++) {
            int i = dx[k];
            int j = dy[k];

            if(current_r + i < 0 || current_r + i >= n ||
                    current_c + j < 0 || current_c > m) continue;
                
            if(visited[current_r + i][current_c + j]) continue;
            visited[current_r + i][current_c + j] = true;

            if(grid[current_r + i][current_c + j] == '0') continue;
            q.push({current_r + i,current_c + j});
        }

    }
}

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool> > visited(n,vector<bool>(m,false));

        int res = 0;

        for(int i = 0;i<n;i++)
            for(int j = 0;j<m;j++){
                if(visited[i][j]) continue;
                if(grid[i][j] == '0'){
                    visited[i][j] = true;
                    continue;
                }

                res++;
                bfs(i,j,n,m,grid,visited);
            }
    
        return res;
    }
};