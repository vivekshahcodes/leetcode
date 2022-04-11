class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> v(n, vector<int>(m));
        
        k%=(m*n);
        int row = k/m;
        int col = k%m;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                v[row][col++] = grid[i][j];
                if(col==m){
                    row++;
                    col = 0;
                }
                if(row==n){
                    row = 0;
                    col = 0;
                }
            }
        }
        
        return v;
    }
};
