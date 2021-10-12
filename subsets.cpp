class Solution {
public:
    
    vector<int> generateSubset(int i, vector<int> nums){
        
        vector<int> sub;
        
        int ind = 0;
        
        while(i > 0){           
            if(i & 1)
                sub.push_back(nums[ind]);
            ind++;
            i = i >> 1;
        }
        
        return sub;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> ans;
        
        for(int i = 0; i < (1 << n); i++){
            ans.push_back(generateSubset(i,nums));
        }
        
        return ans;
    }
};
