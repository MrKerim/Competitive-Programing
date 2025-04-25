class MinStack {
public:
    stack<int> st;
    stack<int> min_st;

    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(min_st.empty()){
            min_st.push(val);
            return;
        }
        int min = min_st.top();
        if(val<min) min_st.push(val);
        else min_st.push(min);
    }
    
    void pop() {
        if(st.empty()) return;
        st.pop();
        min_st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_st.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */