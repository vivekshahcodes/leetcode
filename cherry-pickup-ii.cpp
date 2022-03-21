class Solution {
public:
    
    int maxCherries(int r, int c1, int c2, int n, int m, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){
        
        if(c1<0 || c2<0 || c1>=m || c2>=m || (c1==c2)){
            return -1e9;
        }
        
        if(dp[r][c1][c2]!=-1){
            return dp[r][c1][c2];
        }
        
        if(r==n-1){
            return dp[r][c1][c2] = grid[r][c1] + grid[r][c2];
        }
        
        int ans = -1e9;
        
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                int curr = maxCherries(r+1,c1+i,c2+j,n,m,grid,dp) + grid[r][c1] + grid[r][c2];
                ans = max(ans,curr);
            }
        }
        
        return dp[r][c1][c2] = ans;
        
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (m,-1)));
        
        return maxCherries(0,0,m-1,n,m,grid,dp);
    }
};
