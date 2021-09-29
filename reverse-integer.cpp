class Solution {
public:
    int reverse(int x) {
        
        int temp = x, ans = 0;
        
        while(temp != 0){
            
            int rem = temp%10;
            
            temp /= 10;
            
            if(ans>INT_MAX/10 || (ans==INT_MAX/10 && rem>INT_MAX%10)){
                return 0;
            }
            
            if(ans<INT_MIN/10 || (ans==INT_MIN/10 && rem<INT_MIN%10)){
                return 0;
            }
            
            ans *= 10;
            ans += rem;
        }
        
        return ans;
    }
};
