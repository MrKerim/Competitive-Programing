string editor(string input){
    string res = "";
    for(char c : input){
        if(c != '#') res += c;
        else if(res.size()>0) res.pop_back();
    }
    return res;
}

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        if(editor(s) == editor(t)) return true;
        return false;
    }
};