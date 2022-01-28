class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        int n = nums.size(), positive = 0, negative = 0;
        
        vector<int> finalArray(n);
        
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                finalArray[positive*2] = nums[i];
                positive++;
            }else{
                finalArray[negative*2+1] = nums[i];
                negative++;
            }
        }
        
        return finalArray;
    }
};
