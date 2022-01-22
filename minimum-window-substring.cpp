class Solution {
public:
    string minWindow(string s, string t) {
        
        int n = s.length(), m = t.length(), start = 0, minSoFar = INT_MAX, minWindowStart = 0, c = 0;
        unordered_map<int,int> str,pattern;
        
        for(int i=0;i<m;i++){
            pattern[t[i]]++;
        }
        
        for(int i=0;i<n;i++){
            str[s[i]]++;
            if(pattern[s[i]]>=str[s[i]]){
                c++;
            }
            
            if(c==m){
                
                int startingElement = s[start];
                while(str[startingElement]>pattern[startingElement]){
                    str[startingElement]--;
                    start++;
                    startingElement = s[start];
                }
                
                int windowSize = i-start+1;
                
                if(windowSize<minSoFar){
                    minSoFar = windowSize;
                    minWindowStart = start;
                }
            }
        }
        
        if(minSoFar == INT_MAX){
            return "";
        }else{
            return s.substr(minWindowStart,minSoFar);
        }
        
    }
};
