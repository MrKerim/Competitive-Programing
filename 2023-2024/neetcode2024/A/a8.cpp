#include <vector>

using namespace std;

bool checkNineByNine(vector<vector<char>>& board,int row, int col){
    vector<int> check(9,0);
    for(int i = row; i<row+3; i++){
        for(int j = col; j<col+3; j++){
            if(board[i][j] == '.') continue;
            if(check[board[i][j]-'1'] == 1) return false;
            check[board[i][j]-'1'] = 1;
        }
    }
    return true;
}

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i+=3)
            for (int j = 0; j < 9; j+=3)
                if(!checkNineByNine(board,i,j)) return false;

        for(int row = 0; row<9;row++){
            vector<int> check(9,0);
            for(int col = 0; col <9;col++){
                if(board[row][col] == '.') continue;
                if(check[board[row][col]-'1'] == 1) return false;
                check[board[row][col]-'1'] = 1;
            }
        }

        for(int col = 0; col<9;col++){
            vector<int> check(9,0);
            for(int row = 0; row <9;row++){
                if(board[row][col] == '.') continue;
                if(check[board[row][col]-'1'] == 1) return false;
                check[board[row][col]-'1'] = 1;
            }
        }

        return true;
        
        
    }    
};
