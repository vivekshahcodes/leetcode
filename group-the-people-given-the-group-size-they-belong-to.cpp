class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        
        int n = groupSizes.size();
        unordered_map<int,vector<int>> m;
        vector<vector<int>> groups;
        
        for(int i=0;i<n;i++){
            int groupSize = groupSizes[i];
            m[groupSize].push_back(i);
            if(m[groupSize].size()==groupSize){
                groups.push_back(m[groupSize]);
                m.erase(groupSize);
            }
        }
        
        return groups;
        
    }
};
