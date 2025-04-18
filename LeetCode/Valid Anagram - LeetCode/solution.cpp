class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mp;

        if(s.length() != t.length()) return false;

        for(char c : s) mp[c]++;
        for(char c : t){
            if(mp[c] == 0) return false;
            mp[c]--;
        }

        return true;
    }
};