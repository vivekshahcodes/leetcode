//Solution
//TC - O(n)
//SC - O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        int buyPrice = prices[0], profit = 0;
        
        for(int i=1;i<n;i++){
            if(prices[i]>buyPrice){
                profit = max(prices[i]-buyPrice,profit);
            }else{
                buyPrice = prices[i];
            }
        }
        
        return profit;
    }
};
