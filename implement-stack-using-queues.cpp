class MyStack {
public:
    queue<int> a,b;
    
    void push(int x) {
        a.push(x);
    }
    
    int pop() {
        while(a.size()>1){
            int x = a.front();
            a.pop();
            b.push(x);
        }
        
        int ans = a.front();
        a.pop();
        
        swap(a,b);
        
        return ans;
    }
    
    int top() {
        while(a.size()>1){
            int x = a.front();
            a.pop();
            b.push(x);
        }
        
        int ans = a.front();
        a.pop();
        b.push(ans);
        
        swap(a,b);
        
        return ans;
        
    }
    
    bool empty() {
        if(a.empty()){
            return true;
        }
        return false;
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
