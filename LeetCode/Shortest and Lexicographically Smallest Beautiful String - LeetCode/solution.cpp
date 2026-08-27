class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        
        int left = 0;
        int right = 0;
        int count = 0;
        int s_len = s.length();
        vector<string> vec;

        while(s[left] != '1'){
            left++;
            if(left >= s_len ) return "";
        }
        
        if(k == 1) return "1";
        right = left;

        while(right < s_len){
            
            if(s[right] != '1'){
                right++;
                continue;
            }

            
            
            count++;
            if(count < k){
                right++;
                continue;
            }

            // Count == k

            int temp_left = left;
            string temp_s = "";
            while(temp_left <= right) temp_s += s[temp_left++];
            
            vec.push_back(temp_s);

            left++;
            count--;
            right++;

            while(s[left] != '1'){
                left++;
            }
        }

        if(vec.size() == 0) return "";

        sort(vec.begin(), vec.end(), [](const string& a, const string& b) {
            if(a.size() == b.size()){
                return a < b;
            }
            return a.size() < b.size();
        });


        return vec[0];

    }
};