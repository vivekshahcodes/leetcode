//Recursion
//TC - O(2^(n^2))
//SC - O(n)

class Solution {
public:
    
    int minPathSum(int i, int j, int n, vector<vector<int>>& triangle){
        
        if(i==n) return 0;
        
        int first = minPathSum(i+1,j,n,triangle) + triangle[i][j];
        int second = minPathSum(i+1,j+1,n,triangle) + triangle[i][j];
        
        return min(first,second);   
        
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();
        
        return minPathSum(0,0,n,triangle);
        
    }
};


//Memoization
//TC - O(n^2)
//SC - O(n) for the stack space + O(n^2) for the dp array

class Solution {
public:
    
    int minPathSum(int i, int j, int n, vector<vector<int>>& triangle, vector<vector<int>>& dp){
        
        if(i==n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int first = minPathSum(i+1,j,n,triangle,dp) + triangle[i][j];
        int second = minPathSum(i+1,j+1,n,triangle,dp) + triangle[i][j];
        
        return dp[i][j] = min(first,second);   
        
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        
        return minPathSum(0,0,n,triangle,dp);
        
    }
};


//Tabulation
//TC - O(n^2)
//SC - O(n^2) for the dp array

class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int> (n, 0));
        
        for(int j=0;j<n;j++) dp[n-1][j] = triangle[n-1][j];
        
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int first = dp[i+1][j] + triangle[i][j];
                int second = dp[i+1][j+1] + triangle[i][j];
                dp[i][j] = min(first,second);
            }
        }
        
        return dp[0][0];
        
    }
};


//Space Optimization
//TC - O(n^2)
//SC - O(n) for the next and curr arrays

class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();
        vector<int> next(n);
        
        for(int j=0;j<n;j++) next[j] = triangle[n-1][j];
        
        for(int i=n-2;i>=0;i--){
            vector<int> curr(n);
            for(int j=i;j>=0;j--){
                int first = next[j] + triangle[i][j];
                int second = next[j+1] + triangle[i][j];
                curr[j] = min(first,second);
            }
            next = curr;
        }
        
        return next[0];
        
    }
};
