class Solution {
public:
    int lcs(int i, int j, int n, int m, string& text1, string& text2, vector<vector<int>>& dp){
        
        if(i==n || j==m){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(text1[i]==text2[j]){
            return dp[i][j] = 1+lcs(i+1,j+1,n,m,text1,text2,dp);
        }
        
        int first = lcs(i+1,j,n,m,text1,text2,dp);
        int second = lcs(i,j+1,n,m,text1,text2,dp);
        
        return dp[i][j] = max(first,second);
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        
        int n = text1.length();
        int m = text2.length();
        
        vector<vector<int>> dp(n,vector<int>(m,-1));
        
        return lcs(0,0,n,m,text1,text2,dp);
    }
};
