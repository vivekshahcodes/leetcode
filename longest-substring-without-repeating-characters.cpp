class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.length();
        unordered_map<char,int> m;
        int start = -1;
        int longestSubstr = 0;
        
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
