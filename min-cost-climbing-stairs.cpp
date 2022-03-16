class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        vector<int> dp(n+1,-1);
        
        int a = cost[0];
        int b = cost[1];
        int c;
        
        for(int i=2;i<n;i++){
            c = min(a,b)+cost[i];
            a = b;
            b = c;
        }
        
        return min(a,b);
    }
};
