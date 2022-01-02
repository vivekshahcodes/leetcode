class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        
        int n = time.size();
        
        for(int i=0;i<n;i++){
            time[i]%=60;
        }
        
        unordered_map<int,int> m;
        int ans = 0;
        
        for(int i=0;i<n;i++){
            int curr = time[i];
            int req = 60-curr;
            if(m.count(req)){
                ans+=m[req];
            }
            m[curr]++;
        }
        
        int x = m[0];
        x--;
        ans += (x*(x+1))/2; 
        
        return ans;
    }
};
