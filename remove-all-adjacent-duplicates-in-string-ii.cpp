class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        int n = s.length(), i = 0;
        vector<int> freq(n);
        string ans = s;
        
        for(int j=0;j<n;j++){
            
            ans[i] = s[j];
            
            if(i>0 && ans[i-1]==s[j]){
                freq[i] = freq[i-1] + 1;
            }else{
                freq[i] = 1;
            }
                        
            if(freq[i]==k){
                i-=k;
            }
            
            i++;
        }
        
        ans = ans.substr(0,i);
        
        return ans;
    }
};
