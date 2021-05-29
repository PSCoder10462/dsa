class MinStack {
private:
    vector<int> v; int t;
public:
    /** initialize your data structure here. */ 
    MinStack() {
        t = -1;
    }
    
    void push(int val) {
        v.push_back(val);
        t++;
    }
    
    void pop() {
        v.pop_back(); 
        --t;
    }
    
    int top() {
        return v[t];
    }
    
    int getMin() {
         int minn = v[0];
            for (int x: v) minn = min(minn, x);
         return minn;
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
