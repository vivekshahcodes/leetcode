class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        int rows[9][10] = {0}, cols[9][10] = {0}, grid[9][10] = {0};
        
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                
                char c = board[i][j];
                if(c=='.'){
                    continue;
                }else{
                    int x = c-'0'; 
                    
                    if(rows[i][x]){
                        return false;
                    }
                    rows[i][x]++;
                    
                    if(cols[j][x]){
                        return false;
                    }
                    
                    cols[j][x]++;
                    
                    int k = (i/3)*3+(j/3);
                    
                    if(grid[k][x]){
                        return false;
                    }
                    
                    grid[k][x]++;
                }
            }
        }
        
        return true;
    }
};
