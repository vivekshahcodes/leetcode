//Optimal Solution
//TC - O(nlogn)
//SC - O(1)

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        
        for(int i=0;i<n;i++){
            int x = intervals[i][0], y = intervals[i][1];
            if(ans.empty()){
                ans.push_back({x,y});
            }else{
                int ansLen = ans.size();
                int prevX = ans[ansLen-1][0], prevY = ans[ansLen-1][1];
                if(x<=prevY){
                    ans.pop_back();
                    ans.push_back({prevX,max(prevY,y)});
                }else{
                    ans.push_back({x,y});
                }
            }
        }
        
        return ans;
    }
};
