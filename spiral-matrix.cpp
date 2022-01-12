class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int x[4] = {0,1,0,-1};
        int y[4] = {1,0,-1,0};
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        int visited = 0;
        
        int minI = 0, maxI = n-1, minJ = 0, maxJ = m-1;
        int i = 0, j = 0, curr = 0;
        
        vector<int> ans;
        
        while(visited<m*n){
            
            ans.push_back(matrix[i][j]);
            visited++;
            
            if(i+x[curr]<=maxI && i+x[curr]>=minI && j+y[curr]<=maxJ && j+y[curr]>=minJ){
                i += x[curr];
                j += y[curr];
            }else{
                if(i+x[curr]>maxI){
                    curr++;
                    maxJ--;
                }else if(i+x[curr]<minI){
                    curr = 0;
                    minJ++;
                }else if(j+y[curr]>maxJ){
                    curr++;
                    minI++;
                }else{
                    curr++;
                    maxI--;
                }
                
                i+=x[curr];
                j+=y[curr];
            }
            
        }  
        
        return ans;
        
    }
};
