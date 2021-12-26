class Solution {
public:
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        int n = points.size();
        vector<pair<int,int>> distanceArray;
        
        for(int i=0;i<n;i++){
            int x = points[i][0];
            int y = points[i][1];
            int distance = (x*x) + (y*y);
            distanceArray.push_back({distance,i});
        }
        
        sort(distanceArray.begin(),distanceArray.end());
        
        vector<vector<int>> result;
        
        for(int i=0;i<k;i++){
            int index = distanceArray[i].second;
            result.push_back(points[index]);
        }
        
        return result;
    }
};
