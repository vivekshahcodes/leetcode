class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char,int> m;
        int ans = 0, curr = 0;
        
        for(int i=0;i<s.length();i++){
            
            if(m[s[i]]<1){
                m[s[i]] = i+1;
                curr++;
            }else{
                if(m[s[i]]>=i+1-curr){
                    curr = i+1-m[s[i]];
                }else{
                    curr++;
                }
                
                m[s[i]] = i+1;
            }
            
            ans = max(ans,curr);
        }
        
        return ans;
    }
};
