class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int n = nums.size();
        unordered_map<int,int> m;
        
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        
        priority_queue<pair<int,int>> q;
        
        for(auto i:m){
            q.push({i.second,i.first});
        }
        
        vector<int> ans;
        
        while(k){
            
            pair<int,int> p = q.top();
            q.pop();
            ans.push_back(p.second);
            k--;
        }
        
        return ans;
    }
};
