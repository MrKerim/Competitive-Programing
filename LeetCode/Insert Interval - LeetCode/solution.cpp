class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size()==0) return {newInterval};

        int start = newInterval[0];
        vector<vector<int>> res;
        int i;
        for(i = 0;i<intervals.size();i++){
            if(intervals[i][1]<start) res.push_back({intervals[i][0],intervals[i][1]});
            else break;
        }


        if(i==intervals.size()) {
            res.push_back(newInterval);    
            return res;
        }

        //    x.....5   7.....12
        //  1 2 3 4 5 ---- ?    start = min (num[i],start)


        //    x......5  7......12   16......24
        //    x...e..e.......e.....e.....e.....e

        start = min(start,intervals[i][0]);
        int end = newInterval[1];
        for(;i<intervals.size();i++){
            if(intervals[i][1]>=end){
                if(intervals[i][0]<=end){
                    end = intervals[i][1];
                    i++;
                }
                
                break;
            }
        }

        res.push_back({start,end});

        for(;i<intervals.size();i++){
        res.push_back({intervals[i][0],intervals[i][1]});
        }
        return res;
    }
};