class Solution {
public:
    
    int lcs(int i, int j, int n, string &s, string &t, vector<vector<int>>& dp){
        
        if(i==n || j==n){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(s[i]==t[j]){
            return dp[i][j] = 1 + lcs(i+1,j+1,n,s,t,dp);
        }
        
        int first = lcs(i+1,j,n,s,t,dp);
        int second = lcs(i,j+1,n,s,t,dp);
        
        return dp[i][j] = max(first,second);
    }
    
    int minInsertions(string s) {
        
        int n = s.length();
        string t = s;
        reverse(t.begin(),t.end());
        
        vector<vector<int>> dp(n, vector<int>(n,-1));
        
        return n-lcs(0,0,n,s,t,dp);
    }
};
