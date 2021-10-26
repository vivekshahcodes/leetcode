class Solution {
public:
    
    vector<vector<int>> v;
    
    void permutations(vector<int>& nums, int i){
        
        if(i == nums.size()){
            v.push_back(nums);
            return;      
        }
        
        for(int j = i; j < nums.size(); j++){
            
            swap(nums[i], nums[j]);
            permutations(nums, i+1);
            swap(nums[i],nums[j]);
            
        }
        
        return;
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        permutations(nums,0);
        
        return v;
    }
};
