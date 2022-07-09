//Recursion
//TC - O(2^n), more precisely, O(1.618^n)
//SC - O(n) for the stack space

class Solution {
public:
    int fib(int n) {
        
        if(n<=1) return n;
        return fib(n-1)+fib(n-2);
    }
};


//Memoization
//TC - O(n)
//SC - O(n) for stack space + O(n) for the dp array

class Solution {
public:
    
    int fibonacci(int n, vector<int>& dp){
        
        if(n<=1) return n;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = fibonacci(n-1,dp) + fibonacci(n-2,dp);
    }
    
    int fib(int n) {
        
        vector<int> dp(n+1,-1);
        return fibonacci(n,dp);
    }
};


//Tabulation
//TC - O(n)
//SC - O(n) for the dp array

class Solution {
public:
    int fib(int n) {
        
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        
        for(int i=2;i<=n;i++) dp[i] = dp[i-1] + dp[i-2];
        
        return dp[n];
    }
};


//Space Optimization
//TC - O(n)
//SC - O(1)

class Solution {
public:
    int fib(int n) {
        
        int a = 0, b = 1, c = 1;
        
        if(n==0) return 0;
        
        for(int i=2;i<=n;i++){
            c = a + b;
            a = b;
            b = c;
        }
        
        return c;
    }
};
