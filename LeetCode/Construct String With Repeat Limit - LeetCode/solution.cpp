class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        priority_queue<char> pq;
        stack<char> st;
        string res = "";
        for(char c:s) pq.push(c);
        res+=pq.top();pq.pop();
        int currentRepeat = 1;

        while(!pq.empty()){
            if(pq.top()!=res.back()){

                res+=pq.top();
                pq.pop();
                currentRepeat = 0;

                if(!st.empty())
                while(!st.empty() && currentRepeat + 1 <= repeatLimit){
                    //pq.push(st.top()); st.pop();
                    res+=st.top(); st.pop();
                    currentRepeat++;
                }
                else currentRepeat++;
            }
            else{
                if(currentRepeat + 1 <= repeatLimit){
                    res+=pq.top();pq.pop();
                    currentRepeat++;
                }
                else{
                    st.push(pq.top()); pq.pop();
                }
            }
        }

        return res;
    }
};