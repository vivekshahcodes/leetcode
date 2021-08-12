class Solution {
public:
    int longestMountain(vector<int>& arr) {
        
        int ans = 0;
        
        for(int i=1;i<arr.size()-1;i++){
            
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
                
                int curr = 1;
                int j = i;
                
                while(j>0 && arr[j-1]<arr[j]){
                    curr++;
                    j--;
                }
                
                while(i<arr.size()-1 && arr[i+1]<arr[i]){
                    curr++;
                    i++;
                }
                
                ans = max(ans,curr);
            }
        }
        
        return ans;
    }
};
