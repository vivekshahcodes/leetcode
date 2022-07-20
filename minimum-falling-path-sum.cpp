//Recursion
//TC - O(3^n)
//SC - O(n) for the stack space

class Solution {
public:
    
    int minSum(int i, int j, int n, vector<vector<int>>& matrix){
        
        if(i==n) return 0;
        
        int first, second, third;
        first = third = 1e9;
        
        if(j-1>=0) first = minSum(i+1,j-1,n,matrix);
        second = minSum(i+1,j,n,matrix);
        if(j+1<n) third = minSum(i+1,j+1,n,matrix);
        
        return min(first,min(second,third)) + matrix[i][j];
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int ans = INT_MAX;
        
        for(int j=0;j<n;j++)  ans = min(ans,minSum(0,j,n,matrix));
        
        return ans;
    }
};


//Memoization
//TC - O(n^2)
//SC - O(n^2) for the dp array + O(n) for the stack space

class Solution {
public:
    
    int minSum(int i, int j, int n, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        
        if(i==n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int first, second, third;
        first = third = 1e9;
        
        if(j-1>=0) first = minSum(i+1,j-1,n,matrix,dp);
        second = minSum(i+1,j,n,matrix,dp);
        if(j+1<n) third = minSum(i+1,j+1,n,matrix,dp);
        
        return dp[i][j] = min(first,min(second,third)) + matrix[i][j];
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int ans = INT_MAX;
        
        vector<vector<int>> dp(n, vector<int> (n,-1));
        
        for(int j=0;j<n;j++) ans = min(ans,minSum(0,j,n,matrix,dp));
        
        return ans;
    }
};


//Tabulation
//TC - O(n^2)
//SC - O(n^2) for the dp array

class Solution {
public:
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int ans = INT_MAX;
        
        vector<vector<int>> dp(n, vector<int> (n));
        
        for(int j=0;j<n;j++) dp[n-1][j] = matrix[n-1][j];
        
        for(int i=n-2;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int first, second, third;
                first = third = 1e9;

                if(j-1>=0) first = dp[i+1][j-1];
                second = dp[i+1][j];
                if(j+1<n) third = dp[i+1][j+1];
                
                dp[i][j] = min(first, min(second, third)) + matrix[i][j];
            }
        }
        
        for(int j=0;j<n;j++) ans = min(ans, dp[0][j]);
        
        return ans;
    }
};


//Space Optimization
//TC - O(n^2)
//SC - O(n) for the next and curr arrays

class Solution {
public:
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int ans = INT_MAX;
        
        vector<int> next(n);
        
        for(int j=0;j<n;j++) next[j] = matrix[n-1][j];
        
        for(int i=n-2;i>=0;i--){
            
            vector<int> curr(n);
            
            for(int j=n-1;j>=0;j--){
                
                int first, second, third;
                first = third = 1e9;

                if(j-1>=0) first = next[j-1];
                second = next[j];
                if(j+1<n) third = next[j+1];
                
                curr[j] = min(first, min(second, third)) + matrix[i][j];
            }
            
            next = curr;
        }
        
        for(int j=0;j<n;j++) ans = min(ans, next[j]);
        
        return ans;
    }
};
