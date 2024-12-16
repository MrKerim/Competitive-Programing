class Solution {
public:
    int maxArea(vector<int>& height) {
    
    int l = 0;
    int r = height.size()-1;
    int max = 0;

    while(l<r){
        max = std::max(std::min(height[l],height[r]) * (r-l),max);
        if(height[l]<height[r]) l++;
        else if(height[l]>height[r]) r--;
        else {
            if(height[l+1] <= height[r-1]) l++;
            else r--;
        }

    }

    return max;
    }
};