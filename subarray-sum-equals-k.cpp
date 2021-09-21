class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int,int> m;
        
        m[0] = 1;
        
        int total = 0, ans = 0;
        
        for(int i=0;i<nums.size();i++){
            total += nums[i];
            ans += m[total-k];
            m[total]++;
        }
        
        return ans;
    }
};
