class Solution {
public:
    
    int binarySearch(vector<int>& numbers, int l, int r, int target){
        
        while(l <= r){
            
            int m = l + (r - l)/2;
            
            if(numbers[m] == target){
                return m + 1;
            }else if(numbers[m] < target){
                l = m + 1;
            }else{
                r = m - 1;
            }
        }
        
        return -1;
        
    }
    
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int n = numbers.size();
        vector<int> ans;
        
        for(int i = 0; i < n - 1; i++){
            
            int l = i + 1, r = n - 1;
            
            int ind = binarySearch(numbers, l, r, target - numbers[i]);
            
            if(ind > 0){
                ans.push_back(i + 1);
                ans.push_back(ind);
                
                return ans;
            }
        }
        
        return ans;
    }
};
