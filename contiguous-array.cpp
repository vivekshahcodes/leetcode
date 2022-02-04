class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        int n = nums.size(), count = 0, ans = 0;
        unordered_map<int,int> m;
        
        m[0] = 0;
        
        for(int i=0;i<n;i++){
            
            if(nums[i]){
                count++;
            }else{
                count--;
            }
            
            if(m.count(count)){
                int x = m[count];
                ans = max(ans,i-x+1);
            }else{
                m[count] = i+1;
            }
        }
        
        return ans;
    }
};
