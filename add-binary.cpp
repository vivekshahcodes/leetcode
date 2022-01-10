class Solution {
public:
    string addBinary(string a, string b) {
        
        int n = a.length();
        int m = b.length();
        
        int i = n-1, j = m-1;
        int carry = 0;
        string ans;
        
        while(i>=0 && j>=0){
            
            if(a[i]=='0' && b[j]=='0'){
                if(carry == 1){
                    ans = "1"+ans;
                    carry = 0;
                }else{
                    ans = "0"+ans;
                }
            }else if(a[i]=='0' && b[j]=='1'){
                if(carry == 1){
                    ans = "0"+ans;
                }else{
                    ans = "1"+ans;
                }
            }else if(a[i]=='1' && b[j]=='0'){
                if(carry == 1){
                    ans = "0"+ans;
                }else{
                    ans = "1"+ans;
                }
            }else{
                if(carry == 1){
                    ans = "1"+ans;
                }else{
                    ans = "0"+ans;
                    carry = 1;
                }
            }
            
            i--;
            j--;
        }
        
        while(i>=0){
            if(carry == 1){
                if(a[i]=='0'){
                    ans = "1"+ans;
                    carry = 0;
                }else{
                    ans = "0"+ans;
                }
            }else{
                string curr;
                curr.push_back(a[i]);
                ans = curr+ans;
            }
            
            i--;
        }
        
        while(j>=0){
            if(carry == 1){
                if(b[j]=='0'){
                    ans = "1"+ans;
                    carry = 0;
                }else{
                    ans = "0"+ans;
                }
            }else{
                string curr;
                curr.push_back(b[j]);
                ans = curr+ans;
            }
            
            j--;
        }
        
        if(carry == 1){
            ans = "1"+ans;
        }
        
        return ans;
    }
};
