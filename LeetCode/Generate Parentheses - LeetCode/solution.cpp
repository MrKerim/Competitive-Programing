class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s="";
        string s2= "";
        while(n--) {s+="("; s2+=")";}
        s = s + s2;
        

        do {
            res.push_back(s);
        } while (next_permutation(s.begin(), s.end()));

        stack<char> st;
        vector<string> sol;
        for(string s : res){
            bool addToSol = true;
            for(char c : s){
                if(c == '(') st.push(c);
                else if(st.empty()) {addToSol=false; break;}
                else st.pop();
            }
            if(st.empty() && addToSol) sol.push_back(s);
        }

        return sol;
    }
};