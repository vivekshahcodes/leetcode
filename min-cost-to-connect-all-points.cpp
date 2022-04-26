class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n = points.size(), cost = 0, edges = 0;
        
        vector<bool> inMST(n,false);
        vector<int> minDist(n,INT_MAX);
        minDist[0] = 0;
        
        while(edges<n){
            int currMin = INT_MAX, currNode = -1;
            
            for(int i=0;i<n;i++){
                if(!inMST[i] && currMin>minDist[i]){
                    currMin = minDist[i];
                    currNode = i;
                }
            }
            
            cost += currMin;
            inMST[currNode] = true;
            
            for(int i=0;i<n;i++){
                int w = abs(points[currNode][0]-points[i][0]) + abs(points[currNode][1]-points[i][1]);
                if(!inMST[i] && minDist[i]>w){
                    minDist[i] = w;
                }
            }
            
            edges++;
        }
        
        return cost;
    }
};
