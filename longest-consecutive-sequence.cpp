class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_map<int,int> m;
        
        if(nums.size()==0){
            return 0;
        }
        
        for(auto i:nums){
            if(m[i]==0){
                m[i]++;
            }
        }
        
        int ans = 1;
        
        for(auto i:m){
            
            if(m.count(i.first-1)){
                continue;
            }
            
            int a = i.first+1;
            
            while(m.count(a)){
                m[a] = m[a-1] + 1;
                ans = max(ans,m[a]);
                a++;
            }
            
        }
        
        return ans;
    }
};
