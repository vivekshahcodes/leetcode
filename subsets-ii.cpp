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
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<vector<int>> ans;
        
        set<vector<int>> s;
        
        for(int i = 0; i < (1 << n); i++){
            
            vector<int> v = generateSubset(i,nums);
            
            sort(v.begin(),v.end());
            
            if(s.count(v) == 0){
                
                ans.push_back(v);
                s.insert(v);
                
            }
            
        }
        
        return ans;
        
    }
};
