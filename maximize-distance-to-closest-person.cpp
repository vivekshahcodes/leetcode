class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        
        int ans = 1;
        int n = seats.size();
        int zeroCount = 0;
        bool zero = false;
        
        for(int i=0;i<n;i++){
            if(seats[i]==0){
                if(zero){
                    zeroCount++;
                    ans = max(ans,(zeroCount+1)/2);
                }else{
                    zero = true;
                    zeroCount++;
                }
                
            }else{
                if(zero){
                    zero = false;
                    zeroCount = 0;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(seats[i]==1){
                ans = max(ans,i);
                break;
            }
        }
        
        for(int i=n-1;i>=0;i--){
            if(seats[i]==1){
                ans = max(ans,n-1-i);
                break;
            }
        }
        
        return ans;
    }
};
