class Solution {
public:
    vector<int> minOperations(string boxes) {
        
        int n = boxes.length();
        vector<int> v(n,0);
        
        int curr = 0, total = 0;
        
        for(int i=1;i<n;i++){
            if(boxes[i-1]=='1'){
                curr++;
            }
            total += curr;
            v[i] += total;            
        }
        
        curr = 0, total = 0;
        
        for(int i=n-1;i>=0;i--){
            if(boxes[i+1]=='1'){
                curr++;
            }
            total += curr;
            v[i] += total;
        }
        
        return v;
    }
};
