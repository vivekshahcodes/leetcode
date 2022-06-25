//Recursion
//TC - O(2^nm)
//SC - O(n+m) for the stack space

class Solution {
public:
    
    int minSum(int n, int m, vector<vector<int>>& grid){
        
        if(n<0 || m<0){
            return INT_MAX;
        }
        
        if(n==0 && m==0){
            return grid[0][0];
        }
        
        int up = minSum(n-1,m,grid);
        int left = minSum(n,m-1,grid);
        
        return min(up,left)+grid[n][m];
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        return minSum(n-1,m-1,grid);
    }
};


//Memoization
//TC - O(n*m)
//SC - O(n+m) for the stack space + O(n*m) for the dp array

class Solution {
public:
    
    int minSum(int n, int m, vector<vector<int>>& grid, vector<vector<int>>& dp){
        
        if(n<0 || m<0){
            return INT_MAX;
        }
        
        if(n==0 && m==0){
            return grid[0][0];
        }
        
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        
        int up = minSum(n-1,m,grid,dp);
        int left = minSum(n,m-1,grid,dp);
        
        return dp[n][m] = min(up,left)+grid[n][m];
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dp(n, vector<int> (m, -1));
        
        return minSum(n-1,m-1,grid,dp);
    }
};


//Tabulation
//TC - O(n*m)
//SC - O(n*m) for the dp array

class Solution {
public:
    
    int minPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dp(n, vector<int> (m, 0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0){
                    dp[i][j] = grid[i][j];
                }else{
                    int up, left;
                    up = left = INT_MAX;
                    
                    if(i>0)
                        up = dp[i-1][j];
                    
                    if(j>0)
                        left = dp[i][j-1];

                    dp[i][j] = min(up,left) + grid[i][j];
                }
            }
        }
        
        return dp[n-1][m-1];
    }
};


//Space Optimization
//TC - O(n*m)
//SC - O(m)

class Solution {
public:
    
    int minPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<int> prev(m,0);
        
        for(int i=0;i<n;i++){
            
            vector<int> curr(m,0);
            
            for(int j=0;j<m;j++){
                
                if(i==0 && j==0){
                    curr[j] = grid[i][j];
                }else{
                    int up, left;
                    up = left = INT_MAX;
                    
                    if(i>0)
                        up = prev[j];
                    
                    if(j>0)
                        left = curr[j-1];

                    curr[j] = min(up,left) + grid[i][j];
                }
            }
            
            prev = curr;
        }
        
        return prev[m-1];
    }
};
