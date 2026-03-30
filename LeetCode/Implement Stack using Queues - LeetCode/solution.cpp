class MyStack {
public:

    queue<int> que;
    queue<int> que_temp;

    MyStack() {

    }
    
    void push(int x) {
        
        que_temp.push(x);

        while(!que.empty()){

            int t = que.front();
            que.pop();

            que_temp.push(t);
            
        }

        queue<int> temp = que;
        que = que_temp;
        que_temp = temp;
    }
    
    int pop() {
        int x = que.front();
        que.pop();
        return x;
    }  
    
    int top() {
        return que.front();
    }
    
    bool empty() {
        return que.empty();
    }

};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */