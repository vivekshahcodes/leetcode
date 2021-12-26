class Solution {
public:
    
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,-1,0,1};
    
    void floodFill(vector<vector<char>>& grid, int i, int j, int n, int m){
        
        if(i<0 || j<0 || i>=n || j>=m){
            return;
        }
        
        if(grid[i][j]=='0'){
            return;
        }
        
        grid[i][j]='0';
        
        for(int ind=0;ind<4;ind++){
            floodFill(grid,i+dx[ind],j+dy[ind],n,m);
        }
        
    }
    
    int numIslands(vector<vector<char>>& grid){
        
        int n = grid.size();
        int m = grid[0].size();
        
        int islands = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    islands++;
                    floodFill(grid,i,j,n,m);
                }
            }
        }
        
        return islands;
        
    }
};
