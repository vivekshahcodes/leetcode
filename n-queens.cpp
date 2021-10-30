class Solution {
public:
    
    vector<vector<string>> ans;
    bitset<25> col, d1, d2;
    
    bool isValid(int a[][11], int i, int j, int n){
        
        if(col[j] || d1[i+j] || d2[i-j+n]){
            return false;
        }
        
        return true;
    }
    
    bool nQueens(int a[][11], int i, int n){
        
        if(i == n){
            
            vector<string> v;
            
            for(int x = 0; x < n; x++){
                
                string s;
                
                for(int y = 0; y < n; y++){
                    
                    if(a[x][y] == 1){
                        s.push_back('Q');
                    }else{
                        s.push_back('.');
                    }
                    
                }
                
                v.push_back(s);
                
            }
            
            ans.push_back(v);
            
            return false;
        }
        
        for(int j = 0; j < n; j++){
            
            if(isValid(a,i,j,n)){
                
                a[i][j] = 1;
                col[j] = true;
                d1[i+j] = true;
                d2[i-j+n] = true;
                
                bool subProblem = nQueens(a,i+1,n);
                
                if(subProblem){
                    return true;
                }
                
                a[i][j] = 0;
                col[j] = false;
                d1[i+j] = false;
                d2[i-j+n] = false;
            }
        }
        
        return false;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        int a[11][11] = {0};
        
        nQueens(a,0,n);
        
        return ans;
    }
};
