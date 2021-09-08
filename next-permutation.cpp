class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int x = -1, y;
        
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                x = i;
                break;
            }
        }
        
        if(x==-1){
            reverse(nums.begin(),nums.end());
        }else{
            for(int i=nums.size()-1;i>x;i--){
                if(nums[i]>nums[x]){
                    y = i;
                    break;
                }
            }
            
            swap(nums[x],nums[y]);
            
            reverse(nums.begin()+x+1,nums.end());
        }
                
        
    }
};
