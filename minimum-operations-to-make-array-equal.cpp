class Solution {
public:
    int minOperations(int n) {
        
        int ans = 0;
        
        if(n&1){
            int curr = 2;
            while(curr < n){
                ans += curr;
                curr += 2;
            }
        }else{
            int curr = 1;
            while(curr < n){
                ans += curr;
                curr += 2;
            }
        }
        
        return ans;
    }
};
