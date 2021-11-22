class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        
        int dp[10001] = {0};
        
        for(int i = 1; i <= amount; i++){
            
            int curr = 10001;
            
            for(int j = 0; j < coins.size(); j++){
                
                if(i - coins[j] >= 0){
                    
                    curr = min(curr, dp[i - coins[j]]);
                }
            }
                        
            dp[i] = curr + 1;
            
        }
        
        if(dp[amount] > 10000){
            return -1;
        }
        
        return dp[amount];
        
    }
};
