class Solution {
public:
    
    void markBorders(vector<vector<char>>& board, int i, int j, int n, int m){
        
        if(i >= 0 && j >= 0 && i < n && j < m && board[i][j] == 'O'){
            
            board[i][j] = 'B';
            markBorders(board, i, j+1, n, m);
            markBorders(board, i+1, j, n, m);
            markBorders(board, i-1, j, n, m);
            markBorders(board, i, j-1, n, m);
        }
        
        return;
    }
    
    void solve(vector<vector<char>>& board) {
        
        int n = board.size();
        int m = board[0].size();
        
        for(int i = 0; i < n; i++){
            
            markBorders(board, i, 0, n, m);
            markBorders(board, i, m-1, n, m);
            
        }
        
        for(int j = 0; j < m; j++){
            
            markBorders(board, 0, j, n, m);
            markBorders(board, n-1, j, n, m);
        }
        
        for(int i = 0; i < n; i++){
            
            for(int j = 0; j < m; j++){
                
                if(board[i][j] == 'B'){      
                    board[i][j] = 'O';
                    
                }else{
                    board[i][j] = 'X';
                }
            }
        }
        
        return;
    }
};
