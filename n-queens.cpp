class Solution {
public:
    
    vector<vector<string>> ans;
    
    bool isValid(int a[][11], int i, int j, int n){
        
        for(int x = 0; x < n; x++){
            
            if(a[x][j] == 1){
                return false;
            }
        }
        
        int x = i;
        int y = j;
        
        while(x >= 0 && y >= 0){
            
            if(a[x][y] == 1){
                return false;
            }
            
            x--;
            y--;
        }
        
        x = i;
        y = j;
        
        while(x >= 0 && y < n){
            
            if(a[x][y] == 1){
                return false;
            }
            
            x--;
            y++;
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
                
                bool subProblem = nQueens(a,i+1,n);
                
                if(subProblem){
                    return true;
                }
                
                a[i][j] = 0;
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
