class MinStack {
    stack<pair<int, int>> stk;
public:
    
    void push(int value) {
        if(stk.empty()) stk.push({value, value});
        else{
            stk.push({value, min(value, stk.top().second)});
        }
    }
    
    void pop() {
        if(stk.empty())return;
        stk.pop();
    }
    
    int top() {
        return stk.top().first;
    }
    
    int getMin() {
        return stk.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */