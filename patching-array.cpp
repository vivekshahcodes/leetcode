class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        
        int total = 0;
        int patchesRequired = 0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]>total+1 && total<n){
                patchesRequired++;
                total += total+1;
                i--;
            }else{
                total += nums[i];
            }
        }
        
        while(total<n){
            patchesRequired++;
            if(total<=(INT_MAX-1)/2){
                total = 2*total+1;
            }else{
                break;
            }
        }
        
        return patchesRequired;
    }
};
