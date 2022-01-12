class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n<=1) return true;
        
        bool incr = true, decr = true;
        
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]){
                incr = false;
            }else if(nums[i]>nums[i-1]){
                decr = false;
            }
        }
        
        return incr|decr;
    }
};
