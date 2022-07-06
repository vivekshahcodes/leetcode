//Brute Force
//m - Number of unique triplets
//TC - O((n^3)*log(m))
//SC - O(m)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> ans;
        set<vector<int>> s;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i]+nums[j]+nums[k]==0){
                        vector<int> temp{nums[i], nums[j], nums[k]};
                        sort(temp.begin(),temp.end());
                        s.insert(temp);
                    }
                }
            }
        }
        
        for(auto i:s) ans.push_back(i);
        
        return ans;
    }
};


//Optimal Solution
//TC - O(n*n)
//SC - O(1)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size(), i = 0;
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        
        while(i<n){
            int j = i+1, k = n-1;
            int curr = nums[i];
            while(j<n && k>=0 && j<k){
                if(nums[j]+nums[k]==-curr){
                    ans.push_back({curr,nums[j],nums[k]});
                    j++;
                    while(j<k && nums[j]==nums[j-1]) j++;
                    k--;
                    while(k>j && nums[k]==nums[k+1]) k--;
                }else if(nums[j]+nums[k]>-curr){
                    k--;
                }else{
                    j++;
                }
            }
            i++;
            while(i<n && nums[i]==nums[i-1]) i++;
        }
        
        return ans;
    }
};
