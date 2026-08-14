class Solution {
public:
    int maximumLengthSubstring(string s) {
        

        if(s.length() < 2){
            return 2;
        }

        int maxLen = 2;
        int currentLen = 1;
        unordered_map<char,int> mp;

        int l = 0;
        int r = 1;

        mp[s[l]]++;

        while(l<r && r<s.length() ){
            if( mp[s[r]] < 2 ){
                mp[s[r]]++;
                r++;
                currentLen++;
                maxLen = max(maxLen,currentLen);
                continue;
            }
            
            mp[s[l]]--;
            l++;
            currentLen--;
        }

        return maxLen;
    }
};