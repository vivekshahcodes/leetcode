class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int arr[32] = {0};
        int neg = 0, intmin = 0;
        
        for(int i = 0; i < nums.size(); i++){
            
            if(nums[i]==INT_MIN){
                intmin++;
                continue;
            }
            
            int x = 0;
            
            if(nums[i]<0) neg++;
            
            while(abs(nums[i]) > 0){
                
                arr[x] += abs(nums[i])&1;
                nums[i] = (abs(nums[i]) >> 1);
                x++;
                
            }
        }
        
        int ans = 0;
        
        for(int i = 0; i < 31; i++){
            
            if(arr[i] % 3 != 0){
                ans += pow(2,i);
            }
        }
        
        if(intmin % 3 != 0){
            return INT_MIN;
        }
        
        if(neg%3==0){
            return ans;
        }
        
        return -ans;
    }
};
