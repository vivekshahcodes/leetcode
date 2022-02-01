class Solution {
public:
    
    int maxPossibleGold(vector<vector<int>>& grid, int i, int j, int n, int m){
        
        if(grid[i][j]==0 || i>=n || j>=m || i<0 || j<0){
            return 0;
        }
        
        int up,down,left,right;
        up=down=left=right = 0;
        int value = grid[i][j];
        grid[i][j] = 0;
        
        if(i+1<n){
            down = maxPossibleGold(grid,i+1,j,n,m)+value;
        }
        
        if(j+1<m){
            right = maxPossibleGold(grid,i,j+1,n,m)+value;
        }
        
        if(i-1>=0){
            up = maxPossibleGold(grid,i-1,j,n,m)+value;
        }
        
        if(j-1>=0){
            left = maxPossibleGold(grid,i,j-1,n,m)+value;
        }
        
        grid[i][j] = value;
        
        return max(max(up,down),max(left,right));
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        int ans = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0) continue;
                ans = max(ans,maxPossibleGold(grid,i,j,n,m));
            }
        }
        
        return ans;
    }
};
