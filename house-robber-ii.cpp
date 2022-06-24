//Recursion
//TC - O(2^n), more precisely, O(1.618^n)
//SC - O(n) for the call stack

class Solution {
public:
    
    int maxAmount(int i, int n, vector<int>& nums){
        
        if(i > n){
            return 0;
        }
        
        int pick = maxAmount(i + 2, n, nums) + nums[i];
        int notPick = maxAmount(i + 1, n, nums);
        
        return max(pick, notPick);
    }
    
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return nums[0];
        int first = maxAmount(0, n - 2, nums);
        int second = maxAmount(1, n - 1, nums);
        
        return max(first, second);
    }
};


//Memoization
//TC - O(n)
//SC - O(n) for the call stack + O(n) for the dp array

class Solution {
public:
    
    int maxAmount(int i, int n, vector<int>& nums, vector<int>& dp){
        
        if(i > n){
            return 0;
        }
        
        if(dp[i] != -1){
            return dp[i];
        }
        
        int pick = maxAmount(i + 2, n, nums, dp) + nums[i];
        int notPick = maxAmount(i + 1, n, nums, dp);
        
        return dp[i] = max(pick, notPick);
    }
    
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp(n, -1);
        
        int first = maxAmount(0, n - 2, nums, dp);
        
        for(int i = 0; i < n; i ++){
            dp[i] = -1;
        }
        
        int second = maxAmount(1, n - 1, nums, dp);
        
        return max(first, second);
    }
};


//Tabulation
//TC - O(n)
//SC - O(n) for the dp array

class Solution {
public:
    
    int maxAmount(int i, int n, vector<int>& nums){
        
        vector<int> dp(n + 1, 0);
        dp[i] = nums[i];
        
        for(int j = i + 1; j <= n; j ++){
            int pick = nums[j];
            if(j - 2 >= 0){
                pick += dp[j - 2];
            }
            int notPick = dp[j - 1];
            dp[j] = max(pick, notPick);
        }
        
        return dp[n];
    }
    
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return nums[0];
        int first = maxAmount(0, n - 2, nums);
        int second = maxAmount(1, n - 1, nums);
        
        return max(first, second);
    }
};


//Space Optimization
//TC - O(n)
//SC - O(1)

class Solution {
public:
    
    int maxAmount(int i, int n, vector<int>& nums){
        
        int a = 0, b = nums[i], c = nums[i];
        
        for(int j = i + 1; j <= n; j ++){
            c = max(nums[j] + a, nums[i]);
            a = b;
            b = c;
        }
        
        return c;
    }
    
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return nums[0];
        int first = maxAmount(0, n - 2, nums);
        int second = maxAmount(1, n - 1, nums);
        
        return max(first, second);
    }
};
