class Solution {
public:
    long long binpow(long long a, long long b, long long m){
        
        long long res = 1;
        
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
        
        return (binpow(5,evenIndices,m)*binpow(4,oddIndices,m))%m;
    }
};
