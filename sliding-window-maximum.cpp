class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int> ans;
        deque<int> q;
        
        for(int i=0;i<k-1;i++){
            
            if(q.empty()){
                
                q.push_back(i);
                
            }else{
                
                while(!q.empty() && nums[q.back()]<=nums[i]){
                    q.pop_back();
                }
                
                q.push_back(i);
                
            }
        }
        
        for(int i=k-1;i<nums.size();i++){
            
            while(!q.empty() && q.front()<=(i-k)){
                q.pop_front();
            }
            
            if(q.empty()){
                
                q.push_back(i);
                
            }else{
                
                while(!q.empty() && nums[q.back()]<nums[i]){
                    q.pop_back();
                }
                
                q.push_back(i);
            }
            
            ans.push_back(nums[q.front()]);
        }
        
        return ans;
    }
};
