//Brute Force
//TC - O(n)
//SC - O(n) for the v array

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> v;
        
        for(int i=0;i<n;i++) if(nums[i]!=0) v.push_back(nums[i]);
        
        int pending = n-v.size();
        while(pending--) v.push_back(0);
        nums = v;
    }
};


//Space Optimization
//TC - O(n)
//SC - O(1)

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int n = nums.size(), i = 0;
        
        for(int j=0;j<n;j++) if(nums[j]!=0) swap(nums[i++],nums[j]);
    }
};
