class Solution {
public:
    
    int countExpressions(int i, int n, int curr, int target, int total, vector<int>& nums, vector<vector<int>>& dp){
        
        if(i==n){
            if(curr==target){
                return 1;
            }
            return 0;
        }
        
        if(dp[i][curr+total]!=INT_MIN){
            return dp[i][curr+total];
        }
        
        int add = countExpressions(i+1,n,curr+nums[i],target,total,nums,dp);
        int subtract = countExpressions(i+1,n,curr-nums[i],target,total,nums,dp);
        
        return dp[i][curr+total] = add+subtract;        
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();
        int total = 0;
        for(int i=0;i<n;i++){
            total += nums[i];
        }
        
        vector<vector<int>> dp(n, vector<int>(2*total+1,INT_MIN));
        
        return countExpressions(0,n,0,target,total,nums,dp);
    }
};
