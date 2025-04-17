class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mp;
        for(char a : magazine) mp[a]++;
        for(char a : ransomNote){
            if(mp[a] == 0) return false;
            else mp[a]--;
        }

        return true;
    }
};