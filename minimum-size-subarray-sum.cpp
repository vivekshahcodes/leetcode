class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n = nums.size(), total = 0, i = 0, ans = INT_MAX;
        
        for(int j=0;j<n;j++){
            total += nums[j];
            while(total-nums[i]>=target){
                total -= nums[i];
                i++;
            }
            
            if(total>=target){
                ans = min(ans,j-i+1);
            }
        }
        
        if(ans==INT_MAX){
            return 0;
        }
        
        return ans;
    }
};
