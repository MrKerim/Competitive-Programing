class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());

        int res = 0;
        int n = citations.size();
        int index = 0;
        while(index < n){
            if(res+1 > citations[index]){
                index++;
                continue;
            }

            int remaining = n - index ;
            if(remaining >= res + 1) {
                res++;
                continue;
            }
            index++;
        }

        return res;
    }
};