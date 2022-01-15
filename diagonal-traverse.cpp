class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        
        vector<int> diagonallyTraversed;
        
        for(int s=0;s<=n+m-2;s++){
            
            for(int t=0;t<=s;t++){
                
                int i = t;
                int j = s-i;
                
                if(s%2==0){
                    swap(i,j);
                }
                
                if(i>=n || j>=m){
                    continue;
                }
                
                diagonallyTraversed.push_back(mat[i][j]);
                
            }   
            
        }
        
        return diagonallyTraversed;
    }
};
