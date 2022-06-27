//Recursion
//TC - O(3^n)
//SC - O(n) for the stack space

class Solution {
public:
    
    int maxCherries(int i, int j, int k, int n, int m, vector<vector<int>>& grid){
        
        if(i==n || j<0 || j>=m || k<0 || k>=m){
            return 0;
        }
        
        int ans = 0;
        
        for(int x=-1;x<=1;x++){
            for(int y=-1;y<=1;y++){
                ans = max(ans,maxCherries(i+1,j+x,k+y,n,m,grid));
            }
        }
        
        if(j==k){
            ans += grid[i][j];
        }else{
            ans += grid[i][j] + grid[i][k];
        }
        
        return ans;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        return maxCherries(0,0,m-1,n,m,grid);
    }
};


//Memoization
//TC - O(n*m*m) * 9
//SC - O(n*m*m) for the dp array + O(n) for the stack space

class Solution {
public:
    
    int maxCherries(int i, int j, int k, int n, int m, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){
        
        if(i==n || j<0 || j>=m || k<0 || k>=m){
            return 0;
        }
        
        if(dp[i][j][k]!=-1){
            return dp[i][j][k];
        }
        
        int ans = 0;
        
        for(int x=-1;x<=1;x++){
            for(int y=-1;y<=1;y++){
                ans = max(ans,maxCherries(i+1,j+x,k+y,n,m,grid,dp));
            }
        }
        
        if(j==k){
            ans += grid[i][j];
        }else{
            ans += grid[i][j] + grid[i][k];
        }
        
        return dp[i][j][k] = ans;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<vector<int>>> dp (n,vector<vector<int>> (m, vector<int> (m, -1)));
        
        return maxCherries(0,0,m-1,n,m,grid,dp);
    }
};


//Tabulation
//TC - O(n*m*m) * 9;
//SC - O(n*m*m) for the dp array

class Solution {
public:
    
    int cherryPickup(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<vector<int>>> dp (n,vector<vector<int>> (m, vector<int> (m, 0)));
        
        for(int j=0;j<m;j++){
            for(int k=0;k<m;k++){
                if(j==k){
                    dp[n-1][j][k] = grid[n-1][j];
                }else{
                    dp[n-1][j][k] = grid[n-1][j] + grid[n-1][k];
                }
            }
        }
        
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<m;j++){
                for(int k=0;k<m;k++){
                    
                    int add; 
                    if(j==k)
                        add = grid[i][j];
                    else
                        add = grid[i][j] + grid[i][k];
                    
                    for(int x=-1;x<=1;x++){
                        for(int y=-1;y<=1;y++){
                            if(j+x<m && j+x>=0 && k+y<m && k+y>=0){
                                dp[i][j][k] = max(dp[i][j][k], dp[i+1][j+x][k+y]+add);
                            }
                        }
                    }
                }
            }
        }
        
        return dp[0][0][m-1];
        
    }
};


//Space Optimization
//TC - O(n*m*m) * 9;
//SC - O(m*m) for the curr and next arrays

class Solution {
public:
    
    int cherryPickup(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> curr(m, vector<int> (m,0)), next(m, vector<int> (m,0));
        
        for(int j=0;j<m;j++){
            for(int k=0;k<m;k++){
                if(j==k){
                    next[j][k] = grid[n-1][j];
                }else{
                    next[j][k] = grid[n-1][j] + grid[n-1][k];
                }
            }
        }
        
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<m;j++){
                for(int k=0;k<m;k++){
                    
                    int add; 
                    if(j==k)
                        add = grid[i][j];
                    else
                        add = grid[i][j] + grid[i][k];
                    
                    for(int x=-1;x<=1;x++){
                        for(int y=-1;y<=1;y++){
                            if(j+x<m && j+x>=0 && k+y<m && k+y>=0){
                                curr[j][k] = max(curr[j][k], next[j+x][k+y]+add);
                            }
                        }
                    }
                }
            }
            next = curr;
        }
        
        return next[0][m-1];
        
    }
};
