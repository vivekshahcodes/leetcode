class Solution {
public:
    char findTheDifference(string s, string t) {
        
        int n = s.length(), m = t.length();
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        
        int i=0,j=0;
        
        while(i<n && j<m){
            if(s[i]!=t[j]){
                return t[j];
            }
            i++;
            j++;
        }
        
        return t[j];
    }
};
