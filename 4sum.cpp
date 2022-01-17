class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        vector<vector<int>> ans;
        
        for(int i=0;i<n-3;i++){
            
            for(int j=i+1;j<n-2;j++){
                
                int l = j+1;
                int r = n-1;
                int x = target-(nums[i]+nums[j]);
                
                while(l<r){
                    if(nums[l]+nums[r]==x){
                        ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                        l++;
                        r--;
                        
                        while(l<n && nums[l]==nums[l-1]){
                            l++;
                        }
                        
                        while(r>=0 && nums[r]==nums[r+1]){
                            r--;
                        }
                        
                    }else if(nums[l]+nums[r]>x){
                        r--;
                        while(r>=0 && nums[r]==nums[r+1]){
                            r--;
                        }
                    }else{
                        l++;
                        while(l<n && nums[l]==nums[l-1]){
                            l++;
                        }
                    }
                }
                
                while(i+1<n && nums[i]==nums[i+1]){
                    i++;
                }
                
                while(j+1<n && nums[j]==nums[j+1]){
                    j++;
                }
                
            }
        }
        
        return ans;
    }
};
