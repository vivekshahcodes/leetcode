class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size();
        int start = 0, currentGas = 0, totalGas = 0, totalCost = 0;
        
        for(int i=0;i<n;i++){
            totalGas += gas[i];
            totalCost += cost[i];
            currentGas += gas[i]-cost[i];
            
            if(currentGas<0){
                start = i+1;
                currentGas = 0;
            }
        }
        
        if(totalCost<=totalGas){
            return start;
        }
        
        return -1;
        
    }
};
