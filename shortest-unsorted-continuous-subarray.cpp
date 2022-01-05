class Solution {
public:
    
    bool isOutOfOrder(vector<int>& nums, int i){

        int n = nums.size();

        if(i==0){
            return nums[i]>nums[1];
        }else if(i==n-1){
            return nums[i]<nums[n-2];
        }else{
            return nums[i]<nums[i-1] || nums[i]>nums[i+1];
        }
    }
    
    int findUnsortedSubarray(vector<int>& nums){

        int n = nums.size();
        if(n==1) return 0;
        
        int smallest = INT_MAX;
        int largest = INT_MIN;

        for(int i=0;i<n;i++){
            if(isOutOfOrder(nums,i)){
                int x = nums[i];
                smallest = min(smallest,x);
                largest = max(largest,x);
            }
        }

        if(smallest==INT_MAX){
            return 0;
        }

        int index,left,right;
        index = 0;

        while(index<n){
            if(smallest>=nums[index]){
                index++;
            }else{
                left = index;
                break;
            }
        }

        index = n-1;

        while(index>=0){
            if(largest<=nums[index]){
                index--;
            }else{
                right = index;
                break;
            }
        }

        return right-left+1;
    }
};
