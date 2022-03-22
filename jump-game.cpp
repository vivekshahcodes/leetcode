class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();
        int maxPos = 0;
        
        for(int i=0;i<=maxPos;i++){
            if(i==n-1){
                return true;
            }
            maxPos = max(maxPos,i+nums[i]);
        }
        
        return false;
    }
};
