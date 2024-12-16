#include <vector>

using namespace std;

class MinStack {
public:
    vector<int> originalStack;
    vector<int> minStack;
    MinStack() {
        originalStack = vector<int>();
        minStack = vector<int>();
    }
    
    void push(int val) {
        originalStack.push_back(val);

        if(originalStack.size() == 1) minStack.push_back(val);

        else minStack.push_back(min(val, minStack.back()));
        
    }
    
    void pop() {
        originalStack.pop_back();
        minStack.pop_back();
    }
    
    int top() {
        return originalStack.back();
    }
    
    int getMin() {
        return minStack.back();
    }
};
