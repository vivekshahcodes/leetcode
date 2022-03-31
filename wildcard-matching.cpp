class Solution {
public:
    
    bool isMatching(int i, int j, int n, int m, string &s, string &p, vector<vector<int>>& dp){
        
        if(i==n && j==m){
            return true;
        }
        
        if(i==n){
            for(int x=j;x<m;x++){
                if(p[x]!='*'){
                    return false;
                }
            }
            return true;
        }
        
        if(j==m){
            return false;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(s[i]==p[j] || p[j]=='?'){
            return dp[i][j] = isMatching(i+1,j+1,n,m,s,p,dp);
        }else if(p[j]=='*'){
            return dp[i][j] = isMatching(i+1,j+1,n,m,s,p,dp) || isMatching(i+1,j,n,m,s,p,dp) || isMatching(i,j+1,n,m,s,p,dp);
        }
        
        return dp[i][j] = false;
    }
    
    bool isMatch(string s, string p) {
        
        int n = s.length();
        int m = p.length();
        
        vector<vector<int>> dp(n, vector<int> (m,-1));
        
        return isMatching(0,0,n,m,s,p,dp);
    }
};
