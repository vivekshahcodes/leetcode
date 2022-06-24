//Recursion
//TC - O(2^n), more precisely, O(1.6186^n)
//SC - O(n) for the stack space

class Solution {
public:
    
    int maxAmount(int n, vector<int>& nums){
        
        if(n < 0){
            return 0;
        }
        
        int pick = maxAmount(n - 2,nums) + nums[n];
        int notPick = maxAmount(n - 1,nums);
        
        return max(pick, notPick);
    }
    
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        return maxAmount(n - 1, nums);
    }
};


//Memoization
//TC - O(n)
//SC - O(n) for the stack space + O(n) for the dp array

class Solution {
public:
    
    int maxAmount(int n, vector<int>& nums, vector<int>& dp){
        
        if(n < 0){
            return 0;
        }
        
        if(dp[n] != -1){
            return dp[n];
        }
        
        int pick = maxAmount(n - 2, nums, dp) + nums[n];
        int notPick = maxAmount(n - 1, nums, dp);
        
        return dp[n] = max(pick, notPick);
    }
    
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dp(n, -1);
        
        return maxAmount(n - 1, nums, dp);
    }
};


//Tabulation
//TC - O(n)
//SC - O(n) for the dp array

class Solution {
public:
    
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dp(n);
        
        dp[0] = nums[0];
        
        for(int i=1;i<n;i++){
            
            int pick = nums[i];
            if(i-2 >= 0) 
                pick += dp[i-2];
            
            int notPick = dp[i-1];
            
            dp[i] = max(pick,notPick);
        }
        
        return dp[n-1];
    }
};

//Space Optimization
//TC - O(n)
//SC - O(1)

class Solution {
public:
    
    int rob(vector<int>& nums) {
        
        int n = nums.size();
    
        int a = 0, b = nums[0], c = nums[0];
        
        for(int i=1;i<n;i++){
            
            int pick = nums[i];
            if(i-2 >= 0) 
                pick += a;
            
            int notPick = b;
            
            c = max(pick,notPick);
            a = b;
            b = c;
        }
        
        return c;
    }
};
