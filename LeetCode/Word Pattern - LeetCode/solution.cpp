pair<string,int> iter(string s,int i){
    if(s[i] == '\0') return make_pair("\0",i);
    string res;
    while(s[i] != ' ' && s[i] != '\0'){
        res += s[i];
        i++;
    }
    if(s[i] != '\0') i++;
    return make_pair(res,i);
}

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp;
        pair<string,int> strIter= make_pair("dummy",0);

        for(int i = 0;i<pattern.length();i++){
            char input = pattern[i];
            strIter = iter(s,strIter.second);
            if(strIter.first == "\0") return false;
            string target = strIter.first;

            if(mp.find(input) != mp.end()){
                if(mp[input] != target) return false;
            }
            else{
                for(auto mpIter : mp)
                    if(mpIter.second == target) return false;
                
                mp[input] = target;
            }

        }
    
    strIter = iter(s,strIter.second);
    if(strIter.first == "\0") return true;
    return false;

    }
};