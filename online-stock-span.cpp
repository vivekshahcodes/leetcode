class StockSpanner {
public:
    stack<pair<int,int>> s;
    int i;
    StockSpanner() {
        i = 0;
    }
    
    int next(int price) {
        if(s.empty()){
            s.push({price,i});
            i++;
            return i;
        }else{
            while(!s.empty() && s.top().first<=price){
                s.pop();
            }
            
            if(s.empty()){
                s.push({price,i});
                i++;
                return i;
            }else{
                int x = i-s.top().second;
                s.push({price,i});
                i++;
                return x;
            }
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
