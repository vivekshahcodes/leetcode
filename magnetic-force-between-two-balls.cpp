class Solution {
public:
    
    bool isGood(int mid, vector<int>& position, int n, int m){
        
        int prev = position[0];
        int balls = 1;
        
        for(int i = 1; i < n; i++){
            
            if(position[i] - prev >= mid){
                prev = position[i];
                balls++;
            }
            
            if(balls >= m){
                return true;
            }
        }
        
        return false;
    }
    
    int binarySearch(vector<int>& position, int n, int m){
        
        int l = 0, r = position[n-1];
        
        while(l + 1 < r){
            
            int mid = l + (r - l)/2;
            
            if(isGood(mid, position, n, m)){
                l = mid;
            }else{
                r = mid;
            }
        }
        
        return l;
    }
    
    int maxDistance(vector<int>& position, int m) {
        
        int n = position.size();
        
        sort(position.begin(),position.end());
        
        int ans = binarySearch(position, n, m);
        
        return ans;
    }
};
