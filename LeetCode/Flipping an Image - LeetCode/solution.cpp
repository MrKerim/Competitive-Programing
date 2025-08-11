class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        
        int n = image.size();

        for(int i = 0;i<n;i++){
            for(int j = 0;j<image[0].size()/2;j++){
                int temp = !image[i][j];
                image[i][j] = !image[i][n-j-1];
                image[i][n-j-1] = temp;
            }

            if(image[0].size()%2 == 1)
                image[i][image[0].size()/2] = !image[i][image[0].size()/2];
        }

        return image;
    }
};