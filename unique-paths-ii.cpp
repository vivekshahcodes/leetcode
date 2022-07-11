//Recursion
//TC - O(2^nm)
//SC - O(m*n) for the stack space

class Solution {
public:
    
    int countPaths(int i, int j, int n, int m, vector<vector<int>>& obstacleGrid){
        
        if(i>=n || j>=m || obstacleGrid[i][j]==1) return 0;
        if(i==n-1 && j==m-1) return 1;
        
        return countPaths(i+1,j,n,m,obstacleGrid) + countPaths(i,j+1,n,m,obstacleGrid);
        
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        
        return countPaths(0,0,n,m,obstacleGrid);
    }
};


//Memoization
//TC - O(n*m)
//SC - O(n*m) for the stack space + O(n*m) for the dp array

class Solution {
public:
    
    int countPaths(int i, int j, int n, int m, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp){
        
        if(i>=n || j>=m || obstacleGrid[i][j]==1) return 0;
        if(i==n-1 && j==m-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        
        return dp[i][j] = countPaths(i+1,j,n,m,obstacleGrid,dp) + countPaths(i,j+1,n,m,obstacleGrid,dp);
        
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        
        vector<vector<int>> dp(n, vector<int> (m,-1));
        
        return countPaths(0,0,n,m,obstacleGrid,dp);
    }
};


//Tabulation
//TC - O(n*m)
//SC - O(n*m) for the dp array

class Solution {
public:
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        
        vector<vector<int>> dp(n, vector<int> (m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(obstacleGrid[i][j]==1){
                    dp[i][j] = 0;
                }else if(i==0 && j==0){
                    dp[i][j] = 1;
                }else{
                    if(i>0) dp[i][j] += dp[i-1][j];
                    if(j>0) dp[i][j] += dp[i][j-1];
                }
                
            }
        }
        
        return dp[n-1][m-1];
    }
};


//Space Optimization
//TC - O(n*m)
//SC - O(m) for the temp and prev arrays

class Solution {
public:
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        
        vector<int> prev(m,0);
        
        for(int i=0;i<n;i++){
            vector<int> temp(m,0);
            for(int j=0;j<m;j++){
                
                if(obstacleGrid[i][j]==1){
                    temp[j] = 0;
                }else if(i==0 && j==0){
                    temp[j] = 1;
                }else{
                    if(i>0) temp[j] += prev[j];
                    if(j>0) temp[j] += temp[j-1];
                }
                
            }
            prev = temp;
        }
        
        return prev[m-1];
    }
};
