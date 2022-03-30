class Solution {
public:
    
    void lcs(int n, int m, string &s, string &t, vector<vector<int>>& dp){
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
    }
    
    string shortestCommonSupersequence(string s, string t) {
        
        int n = s.length();
        int m = t.length();
        
        vector<vector<int>> dp(n+1, vector<int> (m+1,0));
        
        lcs(n,m,s,t,dp);
        
        string ans;
        
        int i = n, j = m;
        
        while(i>0 && j>0){
            if(s[i-1]==t[j-1]){
                ans.push_back(s[i-1]);
                i--;
                j--;
            }else{
                if(dp[i-1][j]>=dp[i][j-1]){
                    ans.push_back(s[i-1]);
                    i--;
                }else{
                    ans.push_back(t[j-1]);
                    j--;
                }
            }
        }
        
        while(i>0){
            ans.push_back(s[i-1]);
            i--;
        }
        
        while(j>0){
            ans.push_back(t[j-1]);
            j--;
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};
