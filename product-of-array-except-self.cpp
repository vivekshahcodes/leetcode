//Brute Force
//TC - O(n^2)
//SC - O(1)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size(), leftProduct = 1;
        vector<int> ans(n);
        
        for(int i=0;i<n;i++){
            int rightProduct = 1, j = i+1;
            while(j<n) rightProduct *= nums[j++];
            ans[i] = leftProduct * rightProduct;
            leftProduct *= nums[i];
        }
        
        return ans;
    }
};


//Optimized Solution
//TC - O(n)
//SC - O(1)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans(n,1);
        
        int curr = 1;
        for(int i=0;i<n;i++){
            ans[i] *= curr;
            curr *= nums[i];
        }
        
        curr = 1;
        for(int i=n-1;i>=0;i--){
            ans[i] *= curr;
            curr *= nums[i];
        }
        
        return ans;
    }
};
