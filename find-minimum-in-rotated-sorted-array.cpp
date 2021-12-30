class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n = nums.size();
        int l = 0, r = n;
        
        int firstElement = nums[0];
        
        while(l+1<r){
            
            int m = l + (r-l)/2;
            int currentElement = nums[m];
            
            if(currentElement<firstElement){
                r = m;
            }else{
                l = m;
            }
        }
        
        if(r==n){
            return nums[0];
        }else{
            return min(nums[0],nums[r]);
        }
    }
};
