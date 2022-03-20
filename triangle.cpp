class Solution {
public:
    
    int minSum(vector<vector<int>>& triangle, int i, int j, int n, vector<vector<int>>& dp){
        
        if(i==n-1){
            return dp[i][j] = triangle[i][j];
        }        
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int first = triangle[i][j] + minSum(triangle,i+1,j,n,dp);
        int second = triangle[i][j] + minSum(triangle,i+1,j+1,n,dp);
        
        return dp[i][j] = min(first,second);
        
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();
        int m = triangle[n-1].size();
        
        vector<vector<int>> dp(n, vector<int>(m,-1));
        
        return minSum(triangle,0,0,n,dp);
    }
};
