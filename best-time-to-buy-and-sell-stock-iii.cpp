class Solution {
public:
    
    int maximumProfit(int i, int n, vector<int>& prices, int trans, vector<vector<int>>& dp){
        
        if(i==n || trans==5){
            return 0;
        }
        
        if(dp[i][trans]!=-1){
            return dp[i][trans];
        }
        
        if(trans&1){
            int pick = maximumProfit(i+1,n,prices,trans+1,dp)-prices[i];
            int notPick = maximumProfit(i+1,n,prices,trans,dp);
            return dp[i][trans] = max(pick,notPick);
        }
        
        int pick = maximumProfit(i+1,n,prices,trans+1,dp)+prices[i];
        int notPick = maximumProfit(i+1,n,prices,trans,dp);
        
        return dp[i][trans] = max(pick,notPick);
    }
    
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        vector<vector<int>> dp(n, vector<int> (5,-1));
        
        return maximumProfit(0,n,prices,1,dp);
    }
};
