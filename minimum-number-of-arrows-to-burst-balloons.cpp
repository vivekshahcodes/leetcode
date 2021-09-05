bool sortbysec(pair<int,int> a, pair<int,int> b){
        return a.second<b.second;
}

class Solution {
public:
    
    int findMinArrowShots(vector<vector<int>>& points) {
        
        int ans = 0, n = points.size(), curr;
        
        vector<pair<int,int>> v;
        
        for(auto i:points){
            v.push_back({i[0],i[1]});
        }
        
        sort(v.begin(),v.end(),sortbysec);
        
        for(int i=0;i<n;i++){
            if(i==0){
                curr = v[i].second;
                ans++;
            }else{
                if(v[i].first>curr){
                    curr = v[i].second;
                    ans++;
                }
            }
        }
        
        
        return ans;
    }
};
