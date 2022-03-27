class Solution {
public:
    
    int countWays(int i, int n, int amount, vector<int>& coins, vector<vector<int>>& dp){
        
        if(i==n){
            if(amount==0){
                return 1;
            }
            return 0;
        }
        
        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }
        
        int pick = 0;
        if(amount>=coins[i]){
            pick = countWays(i,n,amount-coins[i],coins,dp);
        }
        int notPick = countWays(i+1,n,amount,coins,dp);
        
        return dp[i][amount] = pick+notPick;
    }
    
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1,-1));
        
        return countWays(0,n,amount,coins,dp);
    }
};
