class Solution {
public:
    
    void findUniqueSubsets(int i, vector<int>& nums, int n, vector<int>& currentSubset, vector<vector<int>>& uniqueSubsets){
        
        uniqueSubsets.push_back(currentSubset);
        
        for(int ind=i;ind<n;ind++){
            if(ind>i && nums[ind]==nums[ind-1]){
                continue;
            }
            currentSubset.push_back(nums[ind]);
            findUniqueSubsets(ind+1,nums,n,currentSubset,uniqueSubsets);
            currentSubset.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> uniqueSubsets;
        vector<int> currentSubset;
        
        findUniqueSubsets(0,nums,n,currentSubset,uniqueSubsets);
        
        return uniqueSubsets;
    }
};
