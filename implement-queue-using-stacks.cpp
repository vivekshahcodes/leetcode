class MyQueue {
public:
    stack<int> a,b;
    
    void push(int x) {
        a.push(x);
    }
    
    int pop() {
        while(a.size()>1){
            int x = a.top();
            a.pop();
            b.push(x);
        }
        int ans = a.top();
        a.pop();
        
        while(!b.empty()){
            int x = b.top();
            b.pop();
            a.push(x);
        }
        
        return ans;
    }
    
    int peek() {
        while(a.size()>1){
            int x = a.top();
            a.pop();
            b.push(x);
        }
        int ans = a.top();
        
        while(!b.empty()){
            int x = b.top();
            b.pop();
            a.push(x);
        }
        
        return ans;
    }
    
    bool empty() {
        if(a.size()==0){
            return true;
        }
        return false;
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
