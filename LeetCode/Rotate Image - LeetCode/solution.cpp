class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int temp;
        for(int i = 0;i<n/2;i++){
            for(int j = i;j<n-1-i;j++){

                temp = matrix[i][j];

                int temp_i = i; int temp_j = j;
                for(int t = 0; t < 3; t++){
                matrix[temp_i][temp_j] = matrix[n-temp_j-1][temp_i];
                int temp_temp_i = temp_i;
                temp_i = n-temp_j-1;
                temp_j = temp_temp_i;

                }
                matrix[j][n-1-i] = temp;
            }
        }

    }
};