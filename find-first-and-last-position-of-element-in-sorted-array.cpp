class Solution {
public:
    
    int firstOccurrence(vector<int>& nums, int target){
        
        int l = 0, r = nums.size()-1, ans = -1;
        
        while(l <= r){
            
            int m = l + (r - l) / 2;
            
            if(nums[m] == target){      
                ans = m;
                r = m - 1;
            }else if(nums[m] < target){
                l = m + 1;                
            }else{
                r = m - 1;
            }
        }
        
        return ans;
    }
    
    int lastOccurrence(vector<int>& nums, int target){
        
        int l = 0, r = nums.size()-1, ans = -1;
        
        while(l <= r){
            
            int m = l + (r - l) / 2;
            
            if(nums[m] == target){      
                ans = m;
                l = m + 1;
            }else if(nums[m] < target){
                l = m + 1;                
            }else{
                r = m - 1;
            }
        }
        
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> ans;
        ans.push_back(firstOccurrence(nums,target));
        ans.push_back(lastOccurrence(nums,target));
        
        return ans;
        
    }
};
