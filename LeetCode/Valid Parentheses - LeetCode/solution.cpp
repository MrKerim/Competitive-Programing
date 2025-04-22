char corr(char inp){
    if(inp == '(') return ')';
    else if(inp == '[') return ']';
    else if(inp == '{') return '}';
    else return '/0';
}

bool isOpen(char inp){
    if(inp == '(' || inp == '[' || inp == '{') return true;
    else return false;
}

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char c : s){
            if(isOpen(c)) st.push(corr(c));
            else if(!st.empty()){
                if(st.top() != c) return false;
                else st.pop();
            }
            else return false;
        }

        if(st.empty()) return true;
        else return false;
    }
};