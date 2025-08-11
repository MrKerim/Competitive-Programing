class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {

        int n = mat.size();
        int m = mat[0].size();

        if(n*m != r*c) return mat;

        vector<vector<int> > res(r,vector<int>(c,0));
        
        int a = 0;
        int b = 0;

        for(int i = 0;i<r;i++){
            for(int j = 0;j<c;j++){

                res[i][j] = mat[a][b];
                
                if(b == m-1){
                    a++;
                    b = 0;
                }
                else b++;
            }
        }
        
        return res;

    }
};