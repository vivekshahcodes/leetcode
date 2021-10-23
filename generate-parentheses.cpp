class Solution {
public:
    
    vector<string> v;
    
    void genPar(int n, int i, int open, int close, string output){
        
        if(i == 2*n){
            v.push_back(output);
            return;
        }
        
        if(open < n){
            genPar(n, i+1, open+1, close, output+"(");
        }
        
        if(close < open){
            genPar(n, i+1, open, close+1, output+")");
        }
        
    }
    
    vector<string> generateParenthesis(int n) {
        
        genPar(n, 0, 0, 0, "");
        
        return v;
    }
};
