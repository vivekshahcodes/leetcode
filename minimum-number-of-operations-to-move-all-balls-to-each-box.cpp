class Solution {
public:
    vector<int> minOperations(string boxes) {
        
        int n = boxes.length();
        vector<int> v(n);
        
        for(int i=0;i<n;i++){
            int leftIndex = i-1;
            int currDistance = 0;
            while(leftIndex>=0){
                if(boxes[leftIndex]=='1'){
                    currDistance += i-leftIndex;
                }
                leftIndex--;
            }
            int rightIndex = i+1;
            while(rightIndex<n){
                if(boxes[rightIndex]=='1'){
                    currDistance += rightIndex-i;
                }
                rightIndex++;
            }
            v[i] = currDistance;
        }
        
        return v;
    }
};
