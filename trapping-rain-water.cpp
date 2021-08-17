class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        int a[n], b[n], ans = 0;
        
        a[0] = height[0];
        b[n-1] = height[n-1];
        
        if(n>1){
            
            for(int i=1;i<n;i++){
                a[i] = max(height[i],a[i-1]);
            }
            
            for(int i=n-2;i>=0;i--){
                b[i] = max(height[i],b[i+1]);
            }
            
            for(int i=0;i<n;i++){
                ans += min(a[i],b[i]) - height[i];
            }
            
        }
        
        return ans;
    }
};
