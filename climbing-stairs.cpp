class Solution {
public:
    
    int climbStairs(int n) {
        
        int a = 1, b = 1;
        
        if(n<=1){
            return a;
        }
        
        int c;
        
        for(int i=1;i<n;i++){
            c = a+b;
            a = b;
            b = c;
        }
        
        return b;
    }
};
