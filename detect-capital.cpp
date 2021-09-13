class Solution {
public:
    bool detectCapitalUse(string word) {
        
        bool one = false, two = false, three = false;
        
        if(isupper(word[0])){
            
            one = true;
            three = true;
            
        }else{
            
            two = true;
        }
        
        int u = 0, l = 0;
        
        for(int i=1;i<word.length();i++){
            
            if(isupper(word[i])){
                
                u++;
                two = false;
                three = false;
                
            }else{
                
                l++;
                one = false;
                
            }
        }
        
        return one||two||three;
    }
};
