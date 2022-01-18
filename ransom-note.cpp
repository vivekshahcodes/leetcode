class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        int n = ransomNote.size();
        int m = magazine.size();
        
        map<char,int> hashMap;
        
        for(int i=0;i<m;i++){
            char c = magazine[i];
            hashMap[c]++;
        }
        
        for(int i=0;i<n;i++){
            char c = ransomNote[i];
            if(hashMap[c]){
                hashMap[c]--;
            }else{
                return false;
            }
        }
        
        return true;
    }
};
