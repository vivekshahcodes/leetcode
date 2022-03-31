class Solution {
public:
    
    int editDistance(int i, int j, int n, int m, string &s, string &t, vector<vector<int>>& dp){
        
        if(i==n && j==m){
            return 0;
        }
        
        if(i==n){
            return m-j;
        }
        
        if(j==m){
            return n-i;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(s[i]==t[j]){
            return dp[i][j] = editDistance(i+1,j+1,n,m,s,t,dp);
        }
        
        int ins = editDistance(i,j+1,n,m,s,t,dp);
        int del = editDistance(i+1,j,n,m,s,t,dp);
        int rep = editDistance(i+1,j+1,n,m,s,t,dp);
        
        return dp[i][j] = min(ins,min(del,rep))+1;
    }
    
    int minDistance(string s, string t) {
        
        int n = s.length();
        int m = t.length();
        
        vector<vector<int>> dp(n, vector<int> (m,-1));
        
        return editDistance(0,0,n,m,s,t,dp);
    }
};
