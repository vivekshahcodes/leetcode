class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> ans;
        
        sort(intervals.begin(),intervals.end());
        
        int f,s;
        
        for(int i=0;i<intervals.size();i++){
            
            if(i==0){
                
                f = intervals[i][0];
                s = intervals[i][1];
                
                if(i==intervals.size()-1){
                    ans.push_back({f,s});
                }
                
            }else{
                
                if(intervals[i][0]<=s){
                    
                    s = max(s,intervals[i][1]);
                    
                }else{
                    
                    ans.push_back({f,s});
                    
                    f = intervals[i][0];
                    s = intervals[i][1];
                }
                
                if(i==intervals.size()-1){
                    ans.push_back({f,s});
                }
                
            }
        }
        
        return ans;        
        
    }
};
