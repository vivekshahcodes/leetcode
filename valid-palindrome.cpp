class Solution {
public:
    bool isPalindrome(string s) {
        
        int n = s.length();
        int i = 0, j = n-1;
        
        while(i<j){
            
            while(i<n && !isalpha(s[i]) && !isdigit(s[i])){
                i++;
            }
            
            while(j>=0 && !isalpha(s[j]) && !isdigit(s[j])){
                j--;
            }
            
            if(i>=j) break;
            
            if(isalpha(s[i])){
                s[i] = tolower(s[i]);
            }
            
            if(isalpha(s[j])){
                s[j] = tolower(s[j]);
            }
            
            if(s[i]!=s[j]){
                return false;
            }
            
            i++;
            j--;
        }
        
        return true;
    }
};
