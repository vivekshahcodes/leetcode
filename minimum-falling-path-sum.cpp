class Solution {
public:
    
    int minSum(vector<vector<int>>& matrix, int n, int m, int cols, vector<vector<int>>& dp){
        
        if(n<0){
            return 0;
        }
        
        if(m<cols && dp[n][m]!=INT_MAX){
            return dp[n][m];
        }
        
        int ans = INT_MAX;
        for(int j=0;j<cols;j++){
            if(m==cols || abs(j-m)<=1){
                ans = min(ans,minSum(matrix,n-1,j,cols,dp)+matrix[n][j]);
            }
        }
        
        if(m<cols){
            dp[n][m] = ans;
        }
        
        return ans;
        
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>> dp(n, vector<int> (m,INT_MAX));
        
        return minSum(matrix,n-1,m,m,dp);
    }
};
