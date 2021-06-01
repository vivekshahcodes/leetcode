class Solution {
public:
    int maxProfit(vector<int>& prices) {
       
        int curr = prices[0], ans = 0;

        if(prices.size()==1){
            cout<<ans;
        }else{
            for(auto i:prices){
                if(i<curr){
                    curr = i;
                }else{
                    ans = max(ans,i-curr);
                }
            }
        }

        return ans;
        
    }
};
