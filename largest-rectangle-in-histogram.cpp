class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        vector<int> left(n), right(n);
        
        stack<int> l,r;
        
        for(int i=0;i<n;i++){
            int curr = heights[i];
            
            while(!l.empty() && heights[l.top()]>=curr){
                l.pop();
            }
            
            if(l.empty()){
                left[i] = -1;
                l.push(i);
            }else{
                left[i] = l.top();
                l.push(i);
            }
        }
        
        for(int i=n-1;i>=0;i--){
            int curr = heights[i];
            
            while(!r.empty() && heights[r.top()]>=curr){
                r.pop();
            }
            
            if(r.empty()){
                right[i] = n;
                r.push(i);
            }else{
                right[i] = r.top();
                r.push(i);
            }
        }
        
        int ans = 0;
        
        for(int i=0;i<n;i++){
            ans = max(ans,heights[i]*(right[i]-left[i]-1));
        }
        
        return ans;
    }
};
