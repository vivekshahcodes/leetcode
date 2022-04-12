class Solution {
public:
    
    int countNeighbours(int i, int j, int n, int m, vector<vector<int>>& board){
        
        int total = 0;
        for(int x=-1;x<=1;x++){
            for(int y=-1;y<=1;y++){
                if(i+x<n && i+x>=0 && j+y<m && j+y>=0){
                    total += board[i+x][j+y];
                }                
            }
        }
        
        total -= board[i][j];
        
        return total;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<int>> v(n, vector<int> (m));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int neighbours = countNeighbours(i,j,n,m,board);
                
                if(board[i][j]==0){
                    if(neighbours==3){
                        v[i][j] = 1;
                    }else{
                        v[i][j] = 0;
                    }
                }else{
                    if(neighbours<2 || neighbours>3){
                        v[i][j] = 0;
                    }else{
                        v[i][j] = 1;
                    }
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                board[i][j] = v[i][j]; 
            }
        }
    }
};
