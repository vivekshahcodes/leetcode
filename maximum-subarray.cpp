class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int ans=INT_MIN, curr=0;
        
        for(auto i:nums){
            curr = max(i,curr+i);
            ans = max(ans,curr);
        }
        
        return ans;
    }
};
