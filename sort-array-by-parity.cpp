class Solution {
public:
    
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        int n = nums.size();
        
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]&1){
                    swap(nums[i],nums[j]);
                }
            }
        }
        
        return nums;
    }
};
