class Solution {
public:
    
    unordered_map<string,vector<pair<string,double>>> c;
    
    pair<bool,double> search(string& a, string& b, unordered_set<string>& visited, double v){
        if(visited.count(a)==0){
            visited.insert(a);
            for(auto i:c[a]){
                double k = v*i.second;
                if(i.first==b){
                    return {true,k};
                }
                
                pair<bool,double> p = search(i.first,b,visited,k);
                if(p.first){
                    return p;
                }
            }
        }
        
        return {false,-1.0};
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        int n = equations.size();
        
        vector<double> ans;
        
        for(int i=0;i<n;i++){
            c[equations[i][0]].push_back({equations[i][1],values[i]});
            c[equations[i][1]].push_back({equations[i][0],1.0/values[i]});   
        }
            
        for(auto q:queries){
            unordered_set<string> visited;
            if(q[0]==q[1] && c.count(q[0])){
                ans.push_back(1.0);
            }else{
                pair<bool,double> p = search(q[0],q[1],visited,1.0);
                double x = p.second;
                ans.push_back(x);
            }
        }
        
        return ans;
    }
};
