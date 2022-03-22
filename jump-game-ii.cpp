class Solution {
public:
    
    int minJumps(int i, int n, vector<int>& nums, vector<int>& dp){
        
        if(i==n-1){
            return 0;
        }
        
        if(dp[i]!=1e8){
            return dp[i];
        }
        
        int curr = nums[i];
        
        for(int j=1;j<=curr;j++){
            if(i+j<n){
                dp[i] = min(dp[i],minJumps(i+j,n,nums,dp)+1);
            }
        }
        
        return dp[i];
        
    }
    
    int jump(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dp(n,1e8);
        
        return minJumps(0,n,nums,dp);
    }
};
