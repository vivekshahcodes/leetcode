class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        
        int ans = 0;
        int curr = 0;
        
        for(int i=0;i<accounts.size();i++){
            for(auto j:accounts[i]){
                curr += j;
            }
            ans = max(ans,curr);
            curr = 0;
        }
        
        return ans;
    }
};
