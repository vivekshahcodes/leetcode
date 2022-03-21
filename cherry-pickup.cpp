class Solution {
public:
    
    bool flag;
    
    int maxCherries(int r1, int c1, int c2, int n, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){
        
        int r2 = r1+c1-c2;
        
        if(r1>=n || r2>=n || c1>=n || c2>=n || grid[r1][c1]==-1 || grid[r2][c2]==-1){
            return INT_MIN;
        }
        
        if(dp[r1][c1][c2]!=-1){
            return dp[r1][c1][c2];
        }
        
        if(r1==n-1 && c1==n-1){
            flag = true;
            return grid[r1][c1];
        }
        
        int curr = 0;
        
        if(r1==r2 && c1==c2){
            curr += grid[r1][c1];
        }else{
            curr += grid[r1][c1] + grid[r2][c2];
        }
        
        int first = maxCherries(r1,c1+1,c2+1,n,grid,dp);
        int second = maxCherries(r1+1,c1,c2,n,grid,dp);
        int third = maxCherries(r1+1,c1,c2+1,n,grid,dp);
        int fourth = maxCherries(r1,c1+1,c2,n,grid,dp);
        
        return dp[r1][c1][c2] = max(first,max(second,max(third,fourth)))+curr;
        
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        
        int n = grid.size();
        flag = false;
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (n, vector<int> (n,-1)));
        
        int x = maxCherries(0,0,0,n,grid,dp);
        
        if(flag){
            return x;
        }else{
            return 0;
        }
    }
};
