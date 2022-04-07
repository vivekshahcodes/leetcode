class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        int n = stones.size();
        priority_queue<int> q;
        
        for(int i=0;i<n;i++){
            q.push(stones[i]);
        }
        
        while(q.size()>1){
            int x = q.top();
            q.pop();
            int y = q.top();
            q.pop();
            
            if(x>y){
                q.push(x-y);
            }
        }
        
        if(q.size()==0){
            return 0;
        }else{
            return q.top();
        }
    }
};
