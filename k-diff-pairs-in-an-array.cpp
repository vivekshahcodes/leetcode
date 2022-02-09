class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        int n = nums.size(), ans = 0;
        unordered_map<int,int> hashMap;
        
        for(int i=0;i<n;i++){
            int curr = nums[i];
            hashMap[curr]++;
        }
        
        for(int i=0;i<n;i++){
            int curr = nums[i];
           
            if(k==0){
                if(hashMap[curr]==2){
                    ans++;
                    hashMap[curr]--;
                }else if(hashMap[curr]>2){
                    hashMap[curr]--;
                }
                continue;
            }
            
            if(hashMap[curr]>1){
                hashMap[curr]--;
                continue;
            }
            
            if(hashMap[curr+k]>0){
                ans++;
            }
        }
        
        return ans;
    }
};
