class Solution {
public:
    
    bool isPalindrome(string s){
        int i=0, j=s.length()-1;
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        
        return true;
    }
    
    void allPartitions(int i, int n, string s, vector<string>& curr, vector<vector<string>>& v){
        
        if(i==n){
            v.push_back(curr);
            return;
        }
        
        for(int j=i;j<n;j++){
            string subString = s.substr(i,j-i+1);
            if(isPalindrome(subString)){
                curr.push_back(subString);
                allPartitions(j+1,n,s,curr,v);
                curr.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> v;
        vector<string> curr;
        int n = s.length();
        
        allPartitions(0,n,s,curr,v);
        
        return v;
    }
};
