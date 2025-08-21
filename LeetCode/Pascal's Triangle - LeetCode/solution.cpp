class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int > > result;
        vector<int> prev(1,1);
        result.push_back(prev);

        for(int i = 2;i<=numRows;i++){
            vector<int> current(i,1);

            for(int j = 1;j<current.size()-1;j++) current[j] = prev[j] + prev[j-1];
            result.push_back(current);
            prev = current;
        }


        return result;
    }
};