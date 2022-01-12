class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> v(n,vector<int>(n));
        
        int x[4] = {0,1,0,-1};
        int y[4] = {1,0,-1,0};
        
        int i=0,j=0;
        int curr = 1;
        int ind = 0;
        
        int minI = 0, maxI = n-1, minJ = 0, maxJ = n-1;
        
        while(curr<=n*n){
            
            v[i][j] = curr;
            curr++;
            
            if(i+x[ind]<=maxI && i+x[ind]>=minI && j+y[ind]<=maxJ && j+y[ind]>=minJ){
                i+=x[ind];
                j+=y[ind];
            }else{
                if(i+x[ind]>maxI){
                    ind++;
                    maxJ--;
                }else if(i+x[ind]<minI){
                    ind = 0;
                    minJ++;
                }else if(j+y[ind]>maxJ){
                    ind++;
                    minI++;
                }else{
                    ind++;
                    maxI--;
                }
                
                i+=x[ind];
                j+=y[ind];
            }
            
        }
        
        return v;
        
    }
};
