class Solution {
public:
    
    bool isValid(int i, int j, string &s, bool used){
        
        if(i>=j){
            return true;
        }
        
        if(s[i]==s[j]){
            return isValid(i+1,j-1,s,used);
        }
        
        if(used){
            return false;
        }
        
        return isValid(i+1,j,s,true) || isValid(i,j-1,s,true);
    }
    
    bool validPalindrome(string s) {
        
        int n = s.length();
        
        return isValid(0,n-1,s,false);
    }
};
