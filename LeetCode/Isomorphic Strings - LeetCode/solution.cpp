class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp;
        unordered_map<char,bool> check;

        for(int i = 0;i<s.length();i++){
            char input = s[i];
            char target = t[i];
            if(mp[input]){
                if(mp[input] != target) return false;
            }
            else{
                if(check[target]) return false;
                else {
                    mp[input] = target;
                    check[target] = true;
                }
            }
        }


        return true;
    }
};