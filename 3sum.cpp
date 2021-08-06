class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> ans;
        
        if(nums.size()==0){
            return ans;
        }
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size()-1;i++){
            
            int l = i+1;
            int r = nums.size()-1;
            
            while(l<r){
                if(nums[l]+nums[r]==-nums[i]){
                    ans.push_back({nums[i],nums[l],nums[r]});
                    int a = nums[l];
                    int b = nums[r];
                    while(l<r && nums[l]==a){
                        l++;
                    }
                    while(l<r && nums[r]==b){
                        r--;
                    }
                }else if(nums[l]+nums[r]<-nums[i]){
                    l++;
                }else{
                    r--;
                }
            }
            
            while(i<nums.size()-1 && nums[i]==nums[i+1]){
                i++;
            }
        }
        
        return ans;
    }
};
