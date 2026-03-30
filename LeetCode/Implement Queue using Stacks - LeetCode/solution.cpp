class MyQueue {
public:

    stack<int> s;
    stack<int> s_temp;

    MyQueue() {
    }
    
    void push(int x) {
        
        while(!s.empty()){
            int t = s.top();
            s.pop();

            s_temp.push(t);
        }

        s_temp.push(x);

        while(!s_temp.empty()){
            int t = s_temp.top();
            s_temp.pop();

            s.push(t);
        }


    }
    
    int pop() {
        int x = s.top();
        s.pop();
        return x;
    }
    
    int peek() {
        return s.top();
    }
    
    bool empty() {
        return s.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */