class Solution {
public:
    
    int lis(int i, int l, int n, vector<int>& nums, vector<vector<int>>& dp){
        
        if(i==n){
            return 0;
        }
        
        if(dp[i][l+1]!=-1){
            return dp[i][l+1];
        }
        
        int pick = 0;
        if(l==-1 || nums[i]>nums[l]){
            pick = lis(i+1,i,n,nums,dp)+1;
        }
        int notPick = lis(i+1,l,n,nums,dp);
        
        return dp[i][l+1] = max(pick,notPick);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n+1,-1));
        return lis(0,-1,n,nums,dp);
    }
};
