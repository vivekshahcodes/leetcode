class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        
        int n = arr.size(), i = n-1;
        
        while(i>=0){
            
            if(arr[i]==0){
                for(int j=n-1;j>=i+1;j--){
                    arr[j] = arr[j-1];
                }
            }
            
            i--;
        }
    }
};
