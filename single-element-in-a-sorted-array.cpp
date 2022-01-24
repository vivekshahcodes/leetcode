class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n = nums.size();
        
        int l = -1, r = n-1;
        
        while(l+1<r){
            
            int m = l + (r-l)/2;
            
            if(m&1){
                if(nums[m-1]==nums[m]){
                    l = m;
                }else{
                    r = m;
                }
            }else{
                if(nums[m+1]==nums[m]){
                    l = m;
                }else{
                    r = m;
                }
            }
        }
        
        return nums[r];
    }
};
