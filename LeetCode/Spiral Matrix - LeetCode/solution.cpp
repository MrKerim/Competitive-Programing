enum direction {
    RIGHT,
    LEFT,
    DOWN,
    UP,
};

void traversal(int i,int j,direction prev_direction,vector<vector<int>>& matrix,vector<int>&res,int n,int m,vector<vector<bool>>& visited){
    if(prev_direction == RIGHT){
        if(j + 1 < m && !visited[i][j+1]) {
            // Continue going right
            res.push_back(matrix[i][j+1]);
            visited[i][j+1] = true;
            traversal(i,j+1,RIGHT,matrix,res,n,m,visited);
            return;
        }
        else{
            // Try to go down
            if(i + 1<n && !visited[i+1][j]){
                res.push_back(matrix[i+1][j]);
                visited[i+1][j] = true;
                traversal(i+1,j,DOWN,matrix,res,n,m,visited);
                return;
            }

            // we are at the end
            return;
            
        }
    }

    else if(prev_direction == LEFT){
        if(j - 1 >= 0 && !visited[i][j-1]) {
            // Continue going left
            res.push_back(matrix[i][j-1]);
            visited[i][j-1] = true;
            traversal(i,j-1,LEFT,matrix,res,n,m,visited);
            return;
        }
        else{
            // Try to go up
            if(i - 1<n && !visited[i-1][j]){
                res.push_back(matrix[i-1][j]);
                visited[i-1][j] = true;
                traversal(i-1,j,UP,matrix,res,n,m,visited);
                return;
            }

            // we are at the end
            return;
            
        }
    }

    else if(prev_direction == DOWN){
        if(i + 1 < n && !visited[i+1][j]) {
            // Continue going down
            res.push_back(matrix[i+1][j]);
            visited[i+1][j] = true;
            traversal(i+1,j,DOWN,matrix,res,n,m,visited);
            return;
        }
        else{
            // Try to go left
            if(j - 1 >=0 && !visited[i][j-1]){
                res.push_back(matrix[i][j-1]);
                visited[i][j-1] = true;
                traversal(i,j-1,LEFT,matrix,res,n,m,visited);
                return;
            }

            // we are at the end
            return;
            
        }
    }
    else if(prev_direction == UP){
        if(i - 1 >=0 && !visited[i-1][j]) {
            // Continue going UP
            res.push_back(matrix[i-1][j]);
            visited[i-1][j] = true;
            traversal(i-1,j,UP,matrix,res,n,m,visited);
            return;
        }
        else{
            // Try to go right
            if(j + 1<m && !visited[i][j+1]){
                res.push_back(matrix[i][j+1]);
                visited[i][j+1] = true;
                traversal(i,j+1,RIGHT,matrix,res,n,m,visited);
                return;
            }

            // we are at the end
            return;
            
        }
    }
    
}

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res {matrix[0][0]};
        vector<vector<bool> > visited(matrix.size(),vector<bool>(matrix[0].size(),false));
        visited[0][0] = true;

        int n = matrix.size();
        int m = matrix[0].size();
        traversal(0,0,RIGHT,matrix,res,n,m,visited);

        return res;
    }
};