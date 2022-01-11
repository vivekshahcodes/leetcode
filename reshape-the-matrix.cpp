class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
            
        int n = mat.size();
        int m = mat[0].size();
        
        if(n*m != r*c){
            return mat;
        }
        
        vector<vector<int>> newMatrix(r,vector<int>(c));
        
        int newI = 0, newJ = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                newMatrix[newI][newJ] = mat[i][j];
                newJ++;
                if(newJ==c){
                    newJ = 0;
                    newI++;
                }
            }
        }
        
        return newMatrix;
    }
};
