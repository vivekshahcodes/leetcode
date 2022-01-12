class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        int n = nums.size();
        int firstNonNeg = n;
        
        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                firstNonNeg = i;
                break;
            }
        }
        
        int i = firstNonNeg;
        int j = i-1;
        
        vector<int> sortedArray;
        
        while(i<n && j>=0){
            int x = abs(nums[j]);
            int y = nums[i];
            
            if(y<=x){
                sortedArray.push_back(y*y);
                i++;
            }else{
                sortedArray.push_back(x*x);
                j--;
            }
        }
        
        while(i<n){
            int x = nums[i];
            sortedArray.push_back(x*x);
            i++;
        }
        
        while(j>=0){
            int y = nums[j];
            sortedArray.push_back(y*y);
            j--;
        }
        
        return sortedArray;
        
    }
};
