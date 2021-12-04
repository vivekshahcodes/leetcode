class Solution {
public:
    
    bool isGood(int m, vector<int>& weights, int n, int days){
        
        int d = 1, curr = 0;
        
        for(int i = 0; i < n; i++){
            
            if(weights[i] > m){
                return false;
            }
            
            if(weights[i] + curr > m){
                d++;
                curr = weights[i];
            }else{
                curr += weights[i];
            }
        }
        
        if(d <= days){
            return true;
        }
        
        return false;
    }
    
    int binarySearch(vector<int>& weights, int n, int days){
        
        int l = 0, r = 1e9;
        
        while(l + 1 < r){
            
            int m = l + (r-l)/2;
            
            if(isGood(m,weights,n,days)){
                r = m;
            }else{
                l = m;
            }
        }
        
        return r;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        
        int n = weights.size();
        
        int ans = binarySearch(weights, n, days);
        
        return ans;
        
    }
};
