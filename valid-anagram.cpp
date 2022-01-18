class Solution {
public:
    bool isAnagram(string s, string t) {
        
        map<char,int> hashMap;
        
        int n = s.length();
        int m = t.length();
        
        if(n!=m) return false;
        
        for(int i=0;i<n;i++){
            hashMap[s[i]]++;
        }
        
        for(int i=0;i<m;i++){
            if(hashMap[t[i]]){
                hashMap[t[i]]--;
            }else{
                return false;
            }
        }
        
        return true;
        
    }
};
