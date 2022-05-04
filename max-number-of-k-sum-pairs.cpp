class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
        map<int,int> m;
        
        int n = nums.size(), ans = 0;
        
        for(int i=0;i<n;i++){
            int x = k-nums[i];
            
            if(m[x]>0){
                ans++;
                m[x]--;
            }else{
                m[nums[i]]++;
            }
        }
        
        return ans;
    }
};
