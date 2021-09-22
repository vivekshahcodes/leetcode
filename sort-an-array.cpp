void merge(vector<int>& nums, int l,int r){
    
    int i = l;
    int m = l + (r-l)/2;
    int j = m+1;
    int start = 0;
    vector<int> temp;
    
    while(i<=m && j<=r){
        
        if(nums[i]<=nums[j]){
            temp.push_back(nums[i]);
            i++;
        }else{
            temp.push_back(nums[j]);
            j++;
        }
    }
    
    while(i<=m){
        temp.push_back(nums[i]);
        i++;
    }
    
    while(j<=r){
        temp.push_back(nums[j]);
        j++;
    }
    
    int k = 0;
    
    for(int i=l;i<=r;i++){
        nums[i] = temp[k];
        k++;
    }
    
}

void mergesort(vector<int>& nums, int l, int r){
    
    if(l>=r){
        return;
    }
    
    int m = l + (r-l)/2;
    
    mergesort(nums,l,m);
    mergesort(nums,m+1,r);
    merge(nums,l,r);
}

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        
        int l = 0, r = nums.size()-1;
        
        mergesort(nums,l,r);
    
        return nums;
    }
};
