//Recursion
//TC - O(2^n), more precisely, O(1.618^n)
//SC - O(n) for the stack space

class Solution {
public:
    int climbStairs(int n) {
        
        if(n == 0 || n == 1){
            return 1;
        }
        
        return climbStairs(n-1) + climbStairs(n-2);
    }
};


//Memoization
//TC - O(n)
//SC - O(n) for the stack space + O(n) for the dp array

class Solution {
public:
    
    int totalWays(int n, vector<int>& dp){
        
        if(n==0 || n==1){
            return 1;
        }
        
        if(dp[n] != -1){
            return dp[n];
        }
        
        return totalWays(n-1,dp) + totalWays(n-2,dp);
    }
    
    int climbStairs(int n) {
        
        vector<int> dp(n+1,-1);
        return totalWays(n,dp);
    }
};


//Tabulation
//TC - O(n)
//SC - O(n) for the dp array

class Solution {
public:
    int climbStairs(int n) {
        
        vector<int> dp(n+1);
        dp[0] = dp[1] = 1;
        
        for(int i=2;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[n];
    }
};


//Space Optimization
//TC - O(n)
//SC - O(1)

class Solution {
public:
    int climbStairs(int n) {
        
        int a = 1, b = 1, c = 1;
        
        for(int i=2;i<=n;i++){
            c = a + b;
            a = b;
            b = c;
        }
        
        return c;
    }
};
