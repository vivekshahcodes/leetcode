class Solution {
public:
    string minWindow(string s, string t) {
        
        unordered_map<char,int> str, pattern;
        
        for(int i=0;i<t.length();i++){
            pattern[t[i]]++;
        }
        
        int c = 0, start = 0;
        int windowStart = -1, windowSize = -1, minSoFar = INT_MAX;
        
        for(int i=0;i<s.length();i++){
            
            str[s[i]]++;
            
            if(pattern[s[i]]>=str[s[i]]){
                c++;
            }
            
            if(c==t.length()){
                
                while(str[s[start]]>pattern[s[start]]){
                    str[s[start]]--;
                    start++;
                }
                
                int windowSize = i-start+1;
                
                if(windowSize<minSoFar){
                    windowStart = start;
                    minSoFar = windowSize;
                }
            }
        }
        
        if(minSoFar == INT_MAX){
            return "";
        }else{
            return s.substr(windowStart,minSoFar);
        }
    }
};
