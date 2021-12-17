class Solution {
public:
    
    int dp[10001];
    
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        
        for(int i = 1; i <= amount; i ++){
            
            dp[i] = INT_MAX-1;
            
            for(int c : coins){
                
                if(i - c >= 0)
                    dp[i] = min(dp[i], dp[i - c]);
                
            }
            
            dp[i]++;
        }
        
        if(dp[amount] == INT_MAX) return -1;
        
        return dp[amount];
    }
};
