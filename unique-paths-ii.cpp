class Solution {
public:
    
    int numberOfPaths(vector<vector<int>>& obstacleGrid, int n, int m, vector<vector<int>>& dp){
        
        if(n>=0 && m>=0 && obstacleGrid[n][m]==1){
            return dp[n][m] = 0;
        }
        
        if(n==0 && m==0){
            return dp[n][m] = 1;
        }
        
        if(n<0 || m<0){
            return 0;
        }
        
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        
        return dp[n][m] = numberOfPaths(obstacleGrid,n-1,m,dp)+numberOfPaths(obstacleGrid,n,m-1,dp);
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        
        vector<vector<int>> dp(n, vector<int> (m,-1));
        
        return numberOfPaths(obstacleGrid,n-1,m-1,dp);
    }
};
