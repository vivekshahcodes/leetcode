class Solution {
public:
    string removeKdigits(string num, int k) {
        
        int n = num.length();
        int finalLength = n-k;
        
        if(k==0){
            return num;
        }
        
        string s;
        s.push_back(num[0]);
        
        for(int i=1;i<n;i++){
            
            while(k>0 && s.length()>0 && num[i]<s[s.length()-1]){
                s.pop_back();
                k--;
            }
            s.push_back(num[i]);
            if(s.length()==1 && s[0]=='0'){
                s.pop_back();
            }
        }
        
        while(k>0 && !s.empty()){
            s.pop_back();
            k--;
        }
        
        if(s.length()==0) return "0";
        
        return s;
    }
};
