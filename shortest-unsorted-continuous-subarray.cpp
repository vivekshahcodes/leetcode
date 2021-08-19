class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        int l = INT_MAX, r = INT_MIN;
        
        if(nums.size()==1){
            return 0;
        }
        
        for(int i=0;i<nums.size();i++){
            
            if(i==0){
                
                if(nums[i]>nums[i+1]){
                    l = min(l,nums[i]);
                    r = max(r,nums[i]);
                }
                
            }else if(i==nums.size()-1){
                
                if(nums[i]<nums[i-1]){
                    l = min(l,nums[i]);
                    r = max(r,nums[i]);
                }
                
            }else{
                
                if(nums[i]<nums[i-1] || nums[i]>nums[i+1]){
                    l = min(l,nums[i]);
                    r = max(r,nums[i]);
                }
                
            }
            
        }
        
        if(l==INT_MAX && r==INT_MIN){
            return 0;
        }
        
        int i = 0, j = nums.size()-1;
        
        while(nums[i]<=l){
            i++;
        }
        
        while(nums[j]>=r){
            j--;
        }
        
        return j-i+1;
    }
};
