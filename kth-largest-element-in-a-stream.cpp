class KthLargest {
public:
    
    priority_queue<int,vector<int>,greater<int>> q;
    int kth;
    
    KthLargest(int k, vector<int>& nums) {
        
        int n = nums.size();
        for(int i=0;i<n;i++){
            q.push(nums[i]);
        }
        kth = k;
    }    
    
    int add(int val) {
        
        q.push(val);
        while(q.size()>kth){
            q.pop();
        }  
        return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
