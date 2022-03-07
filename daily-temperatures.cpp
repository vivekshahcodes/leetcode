class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        int n = temperatures.size();
        stack<int> s;
        vector<int> days(n);
        
        for(int i=n-1;i>=0;i--){
            
            int temp = temperatures[i];
            
            if(s.empty()){
                days[i] = 0;
                s.push(i);
            }else{
                while(!s.empty() && temperatures[s.top()] <= temp){
                    s.pop();
                }
                
                if(s.empty()){
                    days[i] = 0;
                    s.push(i);
                }else{
                    days[i] = s.top()-i;
                    s.push(i);                                        
                }
            }
        }
        
        return days;
    }
};
