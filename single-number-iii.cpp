class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        int x = 0;
        
        for(int i = 0; i < nums.size(); i++){
            x ^= nums[i];
        }
        
        int ind = 0;
        int n = x;
        
        while(!(n & 1)){
            n = n >> 1;
            ind++;
        }
        
        int ans = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if(((1 << ind) & nums[i]) > 0)
                ans ^= nums[i];
        }
        
        return {ans,(ans^x)};
    }
};
