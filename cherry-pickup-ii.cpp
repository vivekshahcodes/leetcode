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
//TC -
//SC -

//Code to be added later.
