class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        int n = trips.size();
        vector<int> maxPassengers(1002,0);
        
        for(int i=0;i<n;i++){
            int passengers = trips[i][0];
            int l = trips[i][1];
            int r = trips[i][2];
            maxPassengers[l] += passengers;
            maxPassengers[r] -= passengers;
        }
        
        int maxPossiblePassengers = maxPassengers[0];
        
        for(int i=1;i<=1000;i++){
            maxPassengers[i] += maxPassengers[i-1];
            maxPossiblePassengers = max(maxPossiblePassengers, maxPassengers[i]);
        }
        
        if(capacity>=maxPossiblePassengers){
            return true;
        }
        
        return false;
        
    }
};
