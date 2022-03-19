class Solution {
public:
    
    int minSum(vector<vector<int>>& grid, int n, int m, vector<vector<int>>& dp){
        
        if(n==0 && m==0){
            return dp[n][m] = grid[n][m];
        }
        
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        
        int up,left;
        up = left = INT_MAX;
        
        if(n-1>=0){
            up = minSum(grid,n-1,m,dp);
        }
        
        if(m-1>=0){
            left = minSum(grid,n,m-1,dp);
        }
        
        return dp[n][m] = min(up,left)+grid[n][m];
        
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m,-1));
        
        return minSum(grid,n-1,m-1,dp);
    }
};
