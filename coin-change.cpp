class Solution {
public:
    
    int dp[10001] = {0};
    
    int minCoins(vector<int>& coins, int amount){
        
        if(amount == 0){
            return 0;
        }
        
        if(dp[amount] != 0){
            return dp[amount];
        }
        
        int ans = 10001;
        
        for(int i = 0; i < coins.size(); i++){
            
            if(amount - coins[i] >= 0){
                int subProblem = minCoins(coins, amount - coins[i]);
                ans = min(ans, subProblem+1);
            }
            
        }
        
        dp[amount] = ans;
        
        return dp[amount];
        
    }
    
    int coinChange(vector<int>& coins, int amount) {
        
        int ans = minCoins(coins, amount);
        
        if(ans == 10001){
            return -1;
        }
        
        return ans;
        
    }
};
