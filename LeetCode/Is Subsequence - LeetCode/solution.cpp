class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_index = 0;
        int t_index = 0;
        while(t_index<t.length() && s_index < s.length()){
            if(t[t_index] == s[s_index]) s_index++;
            t_index++;
        }

        if(s_index == s.length()) return true;
        return false;
    }
};