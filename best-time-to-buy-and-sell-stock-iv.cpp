class Solution {
public:
    
    int maximumProfit(int i, int n, vector<int>& prices, int k, vector<vector<int>>& dp){
        
        if(i==n || k==0){
            return 0;
        }
        
        if(dp[i][k]!=-1){
            return dp[i][k];
        }
        
        if(k%2==0){
            int pick = maximumProfit(i+1,n,prices,k-1,dp)-prices[i];
            int notPick = maximumProfit(i+1,n,prices,k,dp);
            
            return dp[i][k] = max(pick,notPick);
        }
        
        int pick = maximumProfit(i+1,n,prices,k-1,dp)+prices[i];
        int notPick = maximumProfit(i+1,n,prices,k,dp);
        
        return dp[i][k] = max(pick,notPick);
    }
    
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
        k*=2;
        
        vector<vector<int>> dp(n, vector<int> (k+1,-1));
        
        return maximumProfit(0,n,prices,k,dp);
    }
};
