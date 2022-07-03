//Brute Force
//TC - O(n^2)
//SC - O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        vector<int> ans;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]+nums[j]==target){
                    ans.push_back(i);
                    ans.push_back(j);
                    break;
                }
            }
        }
        
        return ans;
    }
};


//Two Pointers Approach
//TC - O(nlogn) for sorting
//SC - O(n) for the temp array

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        vector<int> ans, temp;
        temp = nums;
        
        sort(temp.begin(),temp.end());
        
        int i = 0, j = n-1;
        
        while(i<j){
            if(temp[i]+temp[j]==target){
                ans.push_back(temp[i]);
                ans.push_back(temp[j]);
                break;
            }else if(temp[i]+temp[j]<target){
                i++;
            }else{
                j--;
            }
        }
        
        bool n1 = false, n2 = false;
        
        for(int i=0;i<n;i++){
            if(!n1 && nums[i]==ans[0]){
                ans[0] = i;
                n1 = true;
            }else if(!n2 && nums[i]==ans[1]){
                ans[1] = i;
                n2 = true;
            }
        }
        
        return ans;
    }
};


//Hashmap Solution
//TC - O(n)
//SC - O(n) for the hashmap

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        vector<int> ans;
        unordered_map<int,int> m;
        
        for(int i=0;i<n;i++){
            if(m.count(target-nums[i])){
                ans.push_back(m[target-nums[i]]);
                ans.push_back(i);
                break;
            }
            m[nums[i]] = i;
        }
        
        return ans;
    }
};
