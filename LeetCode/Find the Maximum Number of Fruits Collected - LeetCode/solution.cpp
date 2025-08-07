int child3Search(vector<vector<int>>& fruits, int n,int i, int j,  vector<vector<int> >& dp){

    int path1 = 0;
    int path2 = 0;
    int path3 = 0;


    // dioganal up
    if(i-1 > j+1){
        if(dp[i-1][j+1] == -1) {
            path1 = child3Search(fruits, n, i-1, j+1,dp);
            dp[i-1][j+1] = path1;
        }
        else path1 = dp[i-1][j+1];
    }

    // horizantal
    if(i != j+1){
        if(dp[i][j+1] == -1) {
            path2 = child3Search(fruits, n, i, j+1,dp);
            dp[i][j+1] = path2;
        }
        else path2 = dp[i][j+1];
    }

    // dioganal down
    if(i+1 < n && j+1 < n-1){
        if(dp[i+1][j+1] == -1) {
            path3 = child3Search(fruits, n, i+1, j+1,dp);
            dp[i+1][j+1] = path3;
        }
        else path3 = dp[i+1][j+1];   
    }

    return fruits[i][j] +  max(max(path1,path2),path3);
}

int child2Search(vector<vector<int>>& fruits, int n,int i, int j,  vector<vector<int> >& dp){


    int path1 = 0;
    int path2 = 0;
    int path3 = 0;


    // dioganal left
    if(i+1 < j-1){
        if(dp[i+1][j-1] == -1) {
            path1 = child2Search(fruits, n, i+1, j-1,dp);
            dp[i+1][j-1] = path1;
        }
        else path1 = dp[i+1][j-1];
    }

    // vertical
    if(i+1 != j){
        if(dp[i+1][j] == -1) {
            path2 = child2Search(fruits, n, i+1, j,dp);
            dp[i+1][j] = path2;
        }
        else path2 = dp[i+1][j];
    }

    // dioganal right
    if(i+1 < n-1 && j+1 < n) {
        if(dp[i+1][j+1] == -1) {
            path3 = child2Search(fruits, n, i+1, j+1,dp);
            dp[i+1][j+1] = path3;
        }
        else path3 = dp[i+1][j+1];

    }

    return fruits[i][j] +  max(max(path1,path2),path3);
}

class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        
        int n = fruits.size();
        int result = 0;

        vector<vector<int> > dp (n,vector<int>(n,-1));


        // child 1
        for(int i = 0;i<n;i++) result += fruits[i][i];

        result+= child2Search(fruits, n, 0, n-1, dp);

        result+= child3Search(fruits, n, n-1,0, dp);


        return result;
    }
};