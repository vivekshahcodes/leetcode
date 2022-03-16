class Solution {
public:
    
    int maxMoney(vector<int>& nums, int n, vector<int>& dp){
        
        if(n==0){
            return nums[0];
        }
        
        if(n<0){
            return 0;
        }
        
        if(dp[n]!=-1){
            return dp[n];
        }
        
        int pick = maxMoney(nums,n-2,dp) + nums[n];
        int notPick = maxMoney(nums,n-1,dp);
        
        return dp[n] = max(pick,notPick);
    }
    
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dp(n,-1);
        
        return maxMoney(nums,n-1,dp);
    }
};
