class Solution {
public:
    
    unordered_set<int> row,column,diagonal,diagonal2;
    
    bool isValid(int i, int j){
        if(row.count(i) || column.count(j) || diagonal.count(j-i) || diagonal2.count(i+j)){
            return false;
        }
        return true;
    }
    
    void allSolutions(int j, int n, vector<vector<int>>& curr, vector<vector<string>>& v){
        
        if(j==n){
            vector<string> currentBoard;
            for(int r=0;r<n;r++){
                string currRow;
                for(int c=0;c<n;c++){
                    if(curr[r][c]==0){
                        currRow.push_back('.');
                    }else{
                        currRow.push_back('Q');
                    }
                }
                currentBoard.push_back(currRow);
            }
            v.push_back(currentBoard);
            return;
        }
        
        if(j>n){
            return;
        }
        
        for(int i=0;i<n;i++){
            if(isValid(i,j)){
                
                curr[i][j] = 1;
                row.insert(i);
                column.insert(j);
                diagonal.insert(j-i);
                diagonal2.insert(i+j);
                
                allSolutions(j+1,n,curr,v);
                
                curr[i][j] = 0;
                row.erase(i);
                column.erase(j);
                diagonal.erase(j-i);
                diagonal2.erase(i+j);
            }
        }
        
    }
    
    vector<vector<string>> solveNQueens(int n) {   
        vector<vector<string>> v;
        vector<vector<int>> curr(n,vector<int> (n,0));
        allSolutions(0,n,curr,v);
        return v;
    }
};
