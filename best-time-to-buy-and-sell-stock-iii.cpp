class Solution {
public:
    
    int maximumProfit(int i, int n, vector<int>& prices, bool canBuy, int cap, vector<vector<vector<int>>>& dp){
        
        if(i==n || cap==0){
            return 0;
        }
        
        if(dp[i][canBuy][cap]!=-1){
            return dp[i][canBuy][cap];
        }
        
        if(canBuy){
            int pick = maximumProfit(i+1,n,prices,false,cap,dp)-prices[i];
            int notPick = maximumProfit(i+1,n,prices,true,cap,dp);
            return dp[i][canBuy][cap] = max(pick,notPick);
        }
        
        int pick = maximumProfit(i+1,n,prices,true,cap-1,dp)+prices[i];
        int notPick = maximumProfit(i+1,n,prices,false,cap,dp);
        
        return dp[i][canBuy][cap] = max(pick,notPick);
    }
    
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (3, -1)));
        
        return maximumProfit(0,n,prices,true,2,dp);
    }
};
