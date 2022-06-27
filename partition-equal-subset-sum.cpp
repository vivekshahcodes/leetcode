//Recursion
//TC - O(2^n)
//SC - O(n) for the stack space

class Solution {
public:
    
    bool findSubset(int n, int k, vector<int>& nums){
        
        if(k==0) return true;
        if(k<0) return false;
        if(n<0) return false;
        
        bool pick = false;
        if(k-nums[n]>=0) pick = findSubset(n-1,k-nums[n],nums);
        bool notPick = findSubset(n-1,k,nums);
        
        return pick|notPick;
    }
    
    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
        int total = 0;
        
        for(int i=0;i<n;i++) total += nums[i];
        
        if(total&1) return false;
        return findSubset(n-1,total/2,nums);
    }
};


//Memoization
//TC - O(n*k)
//SC - O(n*k) for the dp array + O(n) for the stack space

class Solution {
public:
    
    bool findSubset(int n, int k, vector<int>& nums, vector<vector<int>>& dp){
        
        if(k==0) return true;
        if(k<0) return false;
        if(n<0) return false;
        
        if(dp[n][k]!=-1){
            return dp[n][k];
        }
        
        bool pick = false;
        if(k-nums[n]>=0) pick = findSubset(n-1,k-nums[n],nums,dp);
        bool notPick = findSubset(n-1,k,nums,dp);
        
        return dp[n][k] = pick|notPick;
    }
    
    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
        int total = 0;
        
        for(int i=0;i<n;i++) total += nums[i];
        
        if(total&1) return false;
        
        vector<vector<int>> dp(n, vector<int> ((total/2)+1, -1));
        
        return findSubset(n-1,total/2,nums,dp);
    }
};


//Tabulation
//TC - O(n*k)
//SC - O(n*k) for the dp array

class Solution {
public:
    
    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
        int total = 0;
        
        for(int i=0;i<n;i++) total += nums[i];
        
        if(total&1) return false;
        
        int k = (total/2);
        
        vector<vector<int>> dp(n, vector<int> (k+1, 0));
        
        for(int i=0;i<n;i++) dp[i][0] = true;
        
        if(nums[0]<=k) dp[0][nums[0]] = true;

        for(int i=1;i<n;i++){
            for(int j=1;j<=k;j++){
                bool pick = false;
                if(j-nums[i]>=0){
                    pick = dp[i-1][j-nums[i]];
                }
                bool notPick = dp[i-1][j];
                dp[i][j] = pick | notPick;
            }
        }
        
        return dp[n-1][k];
        
    }
};


//Space Optimization
//TC - O(n*k)
//SC - O(k) for the prev and curr arrays

class Solution {
public:
    
    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
        int total = 0;
        
        for(int i=0;i<n;i++) total += nums[i];
        
        if(total&1) return false;
        
        int k = (total/2);
        
        vector<int> prev(k+1,0), curr(k+1,0);
        prev[0] = true;
        curr[0] = true;
        
        if(nums[0]<=k) prev[nums[0]] = true;

        for(int i=1;i<n;i++){
            for(int j=1;j<=k;j++){
                bool pick = false;
                if(j-nums[i]>=0){
                    pick = prev[j-nums[i]];
                }
                bool notPick = prev[j];
                curr[j] = pick | notPick;
            }
            prev = curr;
        }
        
        return curr[k];
        
    }
};
