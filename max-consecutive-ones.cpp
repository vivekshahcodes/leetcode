class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int n = nums.size(), maxConsecutiveOnes = 0, currentConsecutiveOnes = 0;
        
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                currentConsecutiveOnes++;
                maxConsecutiveOnes = max(maxConsecutiveOnes,currentConsecutiveOnes);
            }else{
                currentConsecutiveOnes = 0;
            }
        }
        
        return maxConsecutiveOnes;
    }
};
