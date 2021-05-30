class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        map<int,int> m;
        
        int ans = 0;
        
        for(auto i:nums){
            ans += m[i];
            m[i]++;
        }
        
        return ans;
    }
};
