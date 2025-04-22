class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());

        if(points.size() == 0) return 0;
        if(points.size() == 1) return 1;

        for(auto p : points) cout<<p[0]<<","<<p[1]<<"\n";


        int res = 0;
        vector<int> current = points[0];

        for(int i = 1;i<points.size();i++){
            if(points[i][0]<current[0] || points[i][0]>current[1]){
                current = points[i];
                res++;
            }
            else{
                current[1] = min ( current[1], points[i][1]);
            }
        }

        return res+1;
    }
};