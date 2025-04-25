class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int x,y;
        for(string s : tokens){
            if(s == "+") {
                y = st.top(); st.pop();
                x = st.top(); st.pop();

                st.push(x+y);
            }
            else if(s == "-"){
                y = st.top(); st.pop();
                x = st.top(); st.pop();

                st.push(x-y);
            }
            else if(s == "*"){
                y = st.top(); st.pop();
                x = st.top(); st.pop();

                st.push(x*y);
            }
            else if(s == "/"){
                y = st.top(); st.pop();
                x = st.top(); st.pop();

                st.push(x/y);
            }
            else st.push(stoi(s));
        }

        return st.top();
    }
};