class Solution {
public:
    
    int countWays(int i, int n, string &s, vector<int>& dp){
        
        if(i==n){
            return 1;
        }
        
        if(dp[i]!=-1){
            return dp[i];
        }
        
        int one = 0;
        if(s[i]!='0'){
            one = countWays(i+1,n,s,dp);
        }
        int two = 0;
        if(i<n-1){
            if(s[i]=='1' || (s[i]=='2' && (s[i+1]-'0')<=6 )){
                two = countWays(i+2,n,s,dp);
            }
        }
        
        return dp[i] = one+two;
    }
    
    int numDecodings(string s) {
        
        int n = s.length();
        vector<int> dp(n,-1);
        
        return countWays(0,n,s,dp);
    }
};
