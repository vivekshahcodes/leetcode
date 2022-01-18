class Solution {
public:
    string removeDuplicates(string s) {
        
        int n = s.length();
        string ans;
        int i = 0;
        
        while(i<n){
            
            int x = ans.length();
            
            if(x==0){
                ans.push_back(s[i]);
            }else{
                char curr = ans[x-1];
                if(s[i]==curr){
                    ans.pop_back();
                }else{
                    ans.push_back(s[i]);
                }
            }
            
            i++;
        }        
        
        return ans;
    }
};
