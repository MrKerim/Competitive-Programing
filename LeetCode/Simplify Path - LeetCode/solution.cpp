int op(string s){
    if(s == ".") return 1;
    else if(s == "..") return 2;
    else return 0;
}

pair<string,int> token(string s,int i){
    while(s[i]=='/') i++;
    string res = "";
    while(s[i] != '/' && s[i] != '\0') res+=s[i++];
    return make_pair(res,i);
}

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        pair<string,int> current = token(path,0);

        while(current.first != ""){
            if(op(current.first) == 2){
                if(!st.empty()) st.pop();
            }
            else if(op(current.first) == 0){
                st.push(current.first);
            }
            current = token(path,current.second);
        }

        string res = "";
        while(!st.empty()){
            if(res != "")
            res = st.top() + "/" + res;
            else res = st.top()+ res;
            st.pop();
        }

        return "/" + res;
    }
};