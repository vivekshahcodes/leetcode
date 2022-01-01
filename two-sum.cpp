class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        unordered_map<int,int> m;
        
        for(int i=0;i<n;i++){
            int curr = nums[i];
            int req = target - curr;
            if(m.count(req)){
               return {m[req],i}; 
            }
            m[curr] = i;
        }
        
        return {-1,-1};
    }
};
