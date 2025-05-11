void search(int r,int c,int n,int m,
vector<vector<bool> >&visited,vector<vector<char>>& board,bool mark){
    int dx[] = {-1, 0, 0, 1};
    int dy[] = {0, -1, 1, 0};
    int i;
    int j;
    
    for(int k = 0; k<4;k++){
        i = r + dx[k]; j = c + dy[k];
        

        if(i<0 || i>=n || j<0 || j>=m) continue;
        if(visited[i][j]) continue;
 

        visited[i][j] = true;
        if(board[i][j] == 'X') continue;


        if(mark) board[i][j] = 'X';
        search(i,j,n,m,visited,board,mark);
    }

}

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool> > visited(n,vector<bool>(m,false));

        for(int i = 0;i<n;i++){
            if(visited[i][0]) continue;
            visited[i][0] = true;
            if(board[i][0] == 'X') continue;
            search(i,0,n,m,visited,board,false);
        }

        for(int i = 0;i<n;i++){
            if(visited[i][m-1]) continue;
            visited[i][m-1] = true;
            if(board[i][m-1] == 'X') continue;
            search(i,m-1,n,m,visited,board,false);
        }

        for(int j = 0;j<m;j++){
            if(visited[0][j]) continue;
            visited[0][j] = true;
            if(board[0][j] == 'X') continue;
            search(0,j,n,m,visited,board,false);
        }

        for(int j = 0;j<m;j++){
            if(visited[n-1][j]) continue;
            visited[n-1][j] = true;
            if(board[n-1][j] == 'X') continue;
            search(n-1,j,n,m,visited,board,false);
        }

        for(int i = 1;i<n-1;i++)
            for(int j = 1;j<m-1;j++){
                if(visited[i][j]) continue;
                visited[i][j] = true;
                if(board[i][j] == 'X') continue;
                board[i][j] = 'X';
                search(i,j,n,m,visited,board,true);

            }
    }
};