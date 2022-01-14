class Solution {
public:
    int myAtoi(string s) {
        
        int i = 0;
        int n = s.length();
        int ans = 0;
        
        while(s[i]==' ' && i<n){
            i++;
        }
        
        bool negative = false;
        
        if(i<n && (s[i]=='+' || s[i]=='-')){
            if(s[i]=='-'){
                negative = true;
            }
            i++;
        }
        
        while(i<n){
            
            int c = s[i] - '0';
            
            if(c < 0 || c > 9) break;
            
            if(negative){
                
                if(ans >= (INT_MIN + c) / 10){
                    ans = ans * 10 - c;
                }else{
                    return INT_MIN;
                }
            }else{
                
                if(ans <= (INT_MAX - c) / 10){
                    ans = ans * 10 + c;
                }else{
                    return INT_MAX;
                }
            }
            
            i++;
            
        }
        
        return ans;
        
        
    }
};
