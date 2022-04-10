class Solution {
public:
    int calPoints(vector<string>& ops) {
        
        stack<int> s;
        
        for(string str:ops){
            
            if(str=="C"){
                s.pop();
            }else if(str=="D"){
                int x = s.top();
                s.push(2*x);
            }else if(str=="+"){
                int x = s.top();
                s.pop();
                int y = s.top();
                s.push(x);
                s.push(x+y);
            }else{
                s.push(stoi(str));
            }
        }
        
        int sum = 0;
        while(!s.empty()){
            sum += s.top();
            s.pop();
        }
        
        return sum;
    }
};
