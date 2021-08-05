class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> ans;
        unordered_map<int,int> m;
        
        m[nums[0]] = 1;
        
        for(int i=1;i<nums.size();i++){
            if(m[target-nums[i]]){
                ans.push_back(m[target-nums[i]]-1);
                ans.push_back(i);
                break;
            }
            m[nums[i]] = i+1;
        }
        
        return ans;
    }
};
