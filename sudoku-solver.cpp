class Solution {
public:
    
    bool isAvailable(vector<vector<char>>& board, int i, int j, int n, int x){
        
        for(int k = 0; k < n; k++){
            
            if(board[i][k]-'0' == x || board[k][j]-'0' == x){
                return false;
            }
        }
        
        int sx = (i/3)*3;
        int sy = (j/3)*3;
        
        for(int k = sx; k < sx+3; k++){
            for(int l = sy; l < sy+3; l++){
                
                if(board[k][l]-'0' == x){
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool sudoku(vector<vector<char>>& board, int i, int j, int n){
        
        if(i == n){
            return true;
        }
        
        if(j == n){
            return sudoku(board, i+1, 0, n);
        }
        
        if(board[i][j] != '.'){
            return sudoku(board, i, j+1, n);
        }
        
        for(int x = 1; x <= n; x++){
            
            if(isAvailable(board, i, j, n, x)){
                
                board[i][j] = x+'0';
                
                bool isValid = sudoku(board, i, j+1, n);
                
                if(isValid){
                    return true;
                }
            }
        }
        
        board[i][j] = '.';
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        
        sudoku(board,0,0,9);
        
    }
};
