class Solution {
public:
    bool isPerfectSquare(int num) {
        
        int l = 1, r = num;
        
        while(l <= r){
            
            int m = l + (r - l)/2;
            
            if(num % m == 0 && num / m == m){
                return true;
            }
            
            if(num/m < m){
                r = m - 1;
            }else{
                l = m + 1;
            }
            
        }
        
        return false;
    }
};
