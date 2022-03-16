class Solution {
public:
    
    int maxAmount(vector<int>& nums) {
        
        int n = nums.size();
        int a = 0, b = nums[0], c;
        
        for(int i=1;i<n;i++){
            c = max(nums[i] + a, b);
            a = b;
            b = c;
        }
        
        return b;
    }
    
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n==1) return nums[0];
        
        vector<int> first,second;
        
        for(int i=0;i<n;i++){
            if(i!=0){
                first.push_back(nums[i]);
            }
            if(i!=n-1){
                second.push_back(nums[i]);
            }
        }
        
        return max(maxAmount(first),maxAmount(second));
    }
};
