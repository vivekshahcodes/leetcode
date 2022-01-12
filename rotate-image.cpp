class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i<j){
                    int x = matrix[i][j];
                    matrix[i][j] = matrix[j][i];
                    matrix[j][i] = x;
                }
            }
        }
        
        int l = 0, r = n-1;
        
        while(l<r){
            for(int i=0;i<n;i++){
                int x = matrix[i][l];
                matrix[i][l] = matrix[i][r];
                matrix[i][r] = x;
            }
            l++;
            r--;
        }
        
    }
};
