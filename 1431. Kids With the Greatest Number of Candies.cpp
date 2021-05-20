class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
        vector<bool> ans;
        
        int g = 0;
        
        for(auto i:candies){
            g = max(g,i);
        }
        
        for(auto i:candies){
            if(i+extraCandies>=g){
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }
        }
        
        return ans;
    }
};
