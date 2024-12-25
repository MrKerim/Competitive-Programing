class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char,bool> mp;
        // checking for 3x3 
        for(int i = 0;i<3;i++){
            for(int j=0;j<3;j++){
                mp.clear();
                for(int a = 0;a<3;a++){
                    for(int b = 0; b<3;b++){
                        int r = i*3+a;
                        int c = j*3+b;

                        if(board[r][c] !='.' && mp[board[r][c]] == 1) 
                        return false;
                        else mp[board[r][c]] = 1;
                    }
                }
            }
        }
        for(int i = 0;i<9;i++){
            mp.clear();
            for(int j = 0;j<9;j++){
                if(board[i][j] != '.' && mp[board[i][j]] == 1)
                return false;
                else mp[board[i][j]] = 1;
            }
        }

        for(int j = 0;j<9;j++){
            mp.clear();
            for(int i = 0;i<9;i++){
                if(board[i][j] != '.' && mp[board[i][j]] == 1)
                return false;
                else mp[board[i][j]] = 1;
            }
        }

        return true;
    }
};