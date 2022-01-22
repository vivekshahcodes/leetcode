class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.length(), start = -1, longestSubstr = 0;
        unordered_map<char,int> m;
        
        for(int i=0;i<n;i++){
            
            if(m.count(s[i]) && m[s[i]]>start){ 
                start = m[s[i]]; 
            }
             
            m[s[i]] = i;
            int currSubstr = i-start;
            longestSubstr = max(longestSubstr,currSubstr);
        }
        
        return longestSubstr;
    }
};
