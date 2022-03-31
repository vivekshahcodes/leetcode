class Solution {
public:
    
    int maximumProfit(int i, int n, vector<int>& prices, bool canBuy, vector<vector<int>>& dp){
        
        if(i==n){
            return 0;
        }
        
        if(dp[i][canBuy]!=-1){
            return dp[i][canBuy];
        }
        
        if(canBuy){
            int pick = maximumProfit(i+1,n,prices,false,dp)-prices[i];
            int notPick = maximumProfit(i+1,n,prices,true,dp);
            
            return dp[i][canBuy] = max(pick,notPick);
        }
        
        int pick = maximumProfit(i+1,n,prices,true,dp)+prices[i];
        int notPick = maximumProfit(i+1,n,prices,false,dp);
        
        return dp[i][canBuy] = max(pick,notPick);
    }
    
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2,-1));
        
        return maximumProfit(0,n,prices,true,dp);
    }
};
