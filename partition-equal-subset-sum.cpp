class Solution {
public:
    
    bool isPossible(int i, int k, vector<int>& nums, vector<vector<int>>& dp){
        
        if(dp[i][k]!=-1){
            return dp[i][k];
        }
        
        if(k==0){
            return true;
        }
        
        if(i==0){
            return nums[0]==k;
        }
        
        bool pick = false;
        if(k-nums[i]>=0){
            pick = isPossible(i-1,k-nums[i],nums,dp);
        }
        bool notPick = isPossible(i-1,k,nums,dp);
        
        return dp[i][k] = pick|notPick;
    }
    
    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
        
        int total = 0;
        for(int i=0;i<n;i++){
            total += nums[i];
        }
        
        if(total&1) return false;
        
        int target = total/2;
        
        vector<vector<int>> dp(n, vector<int> (target+1, -1));
        
        return isPossible(n-1,target,nums,dp);
    }
};
