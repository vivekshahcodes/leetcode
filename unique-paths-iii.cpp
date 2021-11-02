class Solution {
public:
    
    int ans = 0;
    int totalZeros;
    
    void uniquePaths(vector<vector<int>>& grid, int i, int j, int n, int m, int count){
        
        if(i >= n || j >= m || i < 0 || j < 0){
            return;
        }
        
        if(grid[i][j] == -1){
            return;
        }
        
        if(grid[i][j] == 2){
            if(count == totalZeros){
                ans++;
            }
            return;
        }
        
        grid[i][j] = -1;
        
        uniquePaths(grid, i+1, j, n, m, count+1);
        uniquePaths(grid, i, j+1, n, m, count+1);
        uniquePaths(grid, i-1, j, n, m, count+1);
        uniquePaths(grid, i, j-1, n, m, count+1);
        
        grid[i][j] = 0;
        
        return;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int zeros = 0;
        int startX, startY;
        
        for(int i = 0; i < n; i++){
            
            for(int j = 0; j < m; j++){
                
                if(grid[i][j] == 0){
                    
                    zeros++;
                    
                }else if(grid[i][j] == 1){
                    
                    startX = i;
                    startY = j;
                }
            }
        }
        
        totalZeros = zeros+1;
        
        uniquePaths(grid, startX, startY, n, m, 0);
        
        return ans;
    }
};
