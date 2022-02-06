class Solution {
public:
    int findNumbers(vector<int>& nums) {
        
        int n = nums.size(), ans = 0;
        
        for(int i=0;i<n;i++){
            int x = (int)log10(nums[i])+1;
            if(x%2==0){
                ans++;
            }
        }
        
        return ans;
    }
};
