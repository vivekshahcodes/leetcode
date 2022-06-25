//Recursion
//TC - O(2^nm);
//SC - O(n+m) for the stack space

class Solution {
public:
    
    int countPaths(int i, int j, int n, int m){
        
        if(i>=n || j>=m){
            return 0;
        }
        
        if(i==n-1 && j==m-1){
            return 1;
        }
        
        return countPaths(i+1,j,n,m) + countPaths(i,j+1,n,m);
    }
    
    int uniquePaths(int m, int n) {
        
        return countPaths(0,0,m,n);
    }
};


//Memoization
//TC - O(n*m)
//SC - O(n+m) for the stack space + O(n*m) for the dp array

class Solution {
public:
    
    int countPaths(int i, int j, int n, int m, vector<vector<int>>& dp){
        
        if(i>=n || j>=m){
            return 0;
        }
        
        if(i==n-1 && j==m-1){
            return 1;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        return dp[i][j] = countPaths(i+1,j,n,m,dp) + countPaths(i,j+1,n,m,dp);
    }
    
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(m, vector<int> (n,-1));
        return countPaths(0,0,m,n,dp);
    }
};


//Tabulation
//TC - O(n*m)
//SC - O(n*m) for the dp array

class Solution {
public:
    
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(m, vector<int> (n, 0));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                if(i==0 && j==0){
                    dp[0][0] = 1;
                }
                
                if(i>0){
                    dp[i][j] += dp[i-1][j];
                }
                
                if(j>0){
                    dp[i][j] += dp[i][j-1];
                }
            }
        }
        
        return dp[m-1][n-1];
    }
};


//Space Optimization
//TC - O(n*m)
//SC - O(n)

class Solution {
public:
    
    int uniquePaths(int m, int n) {
        
        vector<int> prev(n,0);
        
        for(int i=0;i<m;i++){
            vector<int> temp(n, 0);
            for(int j=0;j<n;j++){
                
                if(i==0 && j==0){
                    temp[j] = 1;
                }
                
                if(i>0){
                    temp[j] += prev[j];
                }
                
                if(j>0){
                    temp[j] += temp[j-1];
                }
            }
            prev = temp;
        }
        
        return prev[n-1];
    }
};
