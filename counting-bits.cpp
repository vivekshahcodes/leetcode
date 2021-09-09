class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> v;
        
        for(int i=0;i<=n;i++){
            
            int ans = 0;
            int x = i;
            
            while(x>0){
                ans++;
                x &= x-1;
            }
            
            v.push_back(ans);
        }
        
        return v;
    }
};
