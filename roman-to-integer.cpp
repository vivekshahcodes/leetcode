class Solution {
public:
    
    bool checkException(char c, char d){
        
        if(c=='I' && (d=='V' || d=='X')){
            return true;
        }
        
        if(c=='X' && (d=='L' || d=='C')){
            return true;
        }
        
        if(c=='C' && (d=='D' || d=='M')){
            return true;
        }
        
        return false;
    }
    
    int romanToInt(string s) {
        
        unordered_map<char,int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        
        int ans = 0;
        
        if(s.length()==1)
            return m[s[0]];
        
        int curr = 1;
        
        for(int i=0;i<s.length();i++){
            
            if(checkException(s[i],s[i+1])){
                ans += m[s[i+1]]-m[s[i]];
                i++;
            }else{
                ans += m[s[i]];
            }            
        }
        
        return ans;
    }
};
