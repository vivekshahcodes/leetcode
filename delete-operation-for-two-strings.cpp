class Solution {
public:
    
    int lcs(int i, int j, int n, int m, string &word1, string &word2, vector<vector<int>>& dp){
        if(i==n || j==m){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(word1[i]==word2[j]){
            return dp[i][j] = 1 + lcs(i+1,j+1,n,m,word1,word2,dp);
        }
        
        int first = lcs(i+1,j,n,m,word1,word2,dp);
        int second = lcs(i,j+1,n,m,word1,word2,dp);
        
        return dp[i][j] = max(first,second);
        
    }
    
    int minDistance(string word1, string word2) {
        
        int n = word1.length();
        int m = word2.length();
        
        vector<vector<int>> dp(n, vector<int> (m,-1));
        
        int x = lcs(0,0,n,m,word1,word2,dp);
        
        return n+m-2*x;
    }
};
