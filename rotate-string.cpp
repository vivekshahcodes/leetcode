class Solution {
public:
    bool rotateString(string s, string goal) {
        
        int n = s.length();
        int m = goal.length();
        
        if(n!=m) return false;
        
        for(int i=0;i<n;i++){
            
            if(s[i]==goal[0]){
                
                string t = s;
                
                reverse(t.begin()+i,t.end());
                reverse(t.begin(),t.begin()+i);
                reverse(t.begin(),t.end());
                
                if(t==goal){
                    return true;
                }
            }
        }
        
        return false;
    }
};
