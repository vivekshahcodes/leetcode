class Solution {
public:
    int arrangeCoins(int n) {
        
        long long curr = 1;
        long long total = 0;
        int ans = 0;
        
        while(total < n){
            
            total += curr;
            curr++;
            ans++;
        }
        
        if(total == (long long)n){
            return ans;
        }
        
        return ans-1;
    }
};
