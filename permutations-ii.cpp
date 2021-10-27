class Solution {
public:
    
    vector<vector<int>> v;
    set<vector<int>> s;
    
    void permutations(vector<int>& nums, int i){
        
        if(i == nums.size()){
            
            if(s.count(nums) == 0){
                v.push_back(nums);
                s.insert(nums);
            }
            
            return;
        }
        
        for(int j = i; j < nums.size(); j++){
            swap(nums[i], nums[j]);
            permutations(nums,i+1);
            swap(nums[i], nums[j]);       
        }
        
        return;
    }
        
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        permutations(nums,0);
        
        return v;
    }
};
