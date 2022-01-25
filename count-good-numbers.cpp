class Solution {
public:
    int binpow(long long a, long long b, int m){
        
        int res = 1;
        
        while(b>0){    
            
            if(b&1) res = (res * a) % m;
            a = (a * a) % m;
            b >>= 1;
        }
        
        return res;
    }
    
    int countGoodNumbers(long long n) {
        
        long long evenIndices = n/2, oddIndices = n/2;
        long long m = 1e9+7;
        
        if(n&1){
            evenIndices++;
        }
        
        return int(((long long)binpow(5,evenIndices,m)*(long long)binpow(4,oddIndices,m))%m);
    }
};
