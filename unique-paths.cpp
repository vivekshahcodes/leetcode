class Solution {
public:
    
    int numberOfPaths(int m, int n, vector<vector<int>>& dp){
        
        if(m==0 || n==0){
            return dp[m][n] = 1;
        }
        
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        
        return dp[m][n] = numberOfPaths(m-1,n,dp)+numberOfPaths(m,n-1,dp);
    }
    
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(m, vector<int> (n,-1));
        return numberOfPaths(m-1,n-1,dp);  
        
    }
};
