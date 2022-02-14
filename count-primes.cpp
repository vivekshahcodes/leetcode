class Solution {
public:
    
    int countPrimes(int n) {
        
        if(n==0) return 0;
        
        vector<int> v(n+1,1);
        
        v[0] = v[1] = 0;
        
        for(int i=4;i<=n;i+=2){
            v[i] = 0;
        }
        
        for(int i=3;i*i<=n;i++){
            if(v[i]){
                for(int j=i*i;j<=n;j+=i){
                    v[j] = 0;
                }
            }
        }
        
        for(int i=1;i<=n;i++){
            v[i] += v[i-1];
        }
        
        return v[n-1];
    }
};
