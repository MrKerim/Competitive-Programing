pair<int,int> find(vector<vector<char>>& board, int n, int m){
    for(int i = 0;i<n;i++)
        for(int j = 0;j<m;j++)
            if(board[i][j] == 'R') return make_pair(i,j);

    return make_pair(0,0);
}

class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        auto[r,c] = find(board,n,m);


        int sum = 0;

        for(int i = r;i>=0;i--){
            if(board[i][c] == 'B') break;
            else if(board[i][c] == 'p') {sum++; break;}
        }

        for(int i = r;i<n;i++){
            if(board[i][c] == 'B') break;
            else if(board[i][c] == 'p') {sum++; break;}
        }

        for(int i = c;i>=0;i--){
            if(board[r][i] == 'B') break;
            else if(board[r][i] == 'p') {sum++; break;}
        }

        for(int i = c;i<n;i++){
            if(board[r][i] == 'B') break;
            else if(board[r][i] == 'p') {sum++; break;}
        }

        return sum;
    }
};