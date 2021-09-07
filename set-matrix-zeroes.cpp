class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int r = matrix.size();
        int c = matrix[0].size();
        
        bool firstRow = false, firstCol = false;
        
        if(matrix[0][0]==0){
            firstRow = true;
            firstCol = true;
        }
        
        for(int i=0;i<r;i++){
            if(matrix[i][0]==0){
                firstCol = true;
                break;
            }
        }
        
        for(int j=0;j<c;j++){
            if(matrix[0][j]==0){
                firstRow = true;
                break;
            }
        }
        
        for(int i=1;i<r;i++){
            for(int j=1;j<c;j++){
                if(matrix[i][j]==0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        
        for(int i=r-1;i>=1;i--){
            for(int j=c-1;j>=1;j--){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j] = 0;
                }
            }
        }
        
        if(firstRow){
            for(int j=0;j<c;j++){
                matrix[0][j] = 0;
            }
        }
        
        if(firstCol){
            for(int i=0;i<r;i++){
                matrix[i][0] = 0;
            }
        }
    }
};
