//Brute Force
//TC - O(n^2)
//SC - O(n)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size(), profit=0;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                profit = max(prices[j]-prices[i], profit);
            }
        }
        
        return profit;
    }
};


//Linear Solution
//TC - O(n)
//SC - O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size(), buyPrice = prices[0], profit = 0;
        
        for(int i=1;i<n;i++){
            if(prices[i]>buyPrice) profit = max(prices[i]-buyPrice,profit);
            else buyPrice = prices[i];
        }
        
        return profit;
    }
};
