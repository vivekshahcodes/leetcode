class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int i = 0, j = height.size()-1, ans = 0;
        
        while(i<j){
            
            int x = j-i;
            int m = min(height[i],height[j]);
            
            ans = max(ans,x*m);
            
            if(height[i]==m){
                i++;
            }else{
                j--;
            }
        }
        
        return ans;
    }
};
