class Solution {
public:
    
    static bool comp(vector<int>& a, vector<int>& b){
        return a[1]>b[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        sort(boxTypes.begin(),boxTypes.end(),comp);
        
        int ans = 0;
        
        for(auto i:boxTypes){
            int x = min(truckSize,i[0]);
            ans += x*i[1];
            truckSize -= x;
            if(truckSize==0) break;
        }
        
        return ans;
    }
};
