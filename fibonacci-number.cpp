class Solution {
public:
    int fib(int n) {
        
        if(n <= 1){
            return n;
        }
        
        int a = 0, b = 1, x;
        
        for(int i = 2; i <= n; i++){
            
            x = a + b;
            a = b;
            b = x;
        }
        
        return b;
    }
};
