class Solution {
public:
    
    int lengthOfBinaryRep(int n){
        
        int length = 0;
        
        while(n>>1){
            length++;
            n = n>>1;
        }
        
        return length;
    }
    
    int bitwiseComplement(int n) {
        
        int x = lengthOfBinaryRep(n);
        x += 1;
        
        int allOnes = (1<<x)-1;
        
        return allOnes^n;
    }
};
