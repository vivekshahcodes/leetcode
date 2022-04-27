class Solution {
public:
    
    static const int n = 1e5+5;
    vector<int> adj[n];
    bool visited[n];
    
    void dfs(string &s, int x, vector<char>& v, vector<int>& ind){
            
        v.push_back(s[x]);
        ind.push_back(x);
        
        visited[x] = true;
        
        for(int k:adj[x]){
            if(!visited[k]){
                dfs(s,k,v,ind);
            }
        }
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        
        for(auto i:pairs){
            int src = i[0], dest = i[1];
            
            adj[src].push_back(dest);
            adj[dest].push_back(src);
        }
        
        for(int i=0;i<s.length();i++){
            if(!visited[i]){
                vector<char> v;
                vector<int> ind;
                
                dfs(s,i,v,ind);
                
                sort(v.begin(),v.end());
                sort(ind.begin(),ind.end());
                
                for(int j=0;j<v.size();j++){
                    s[ind[j]] = v[j];
                }
            }
        }
        
        return s;
    }
};
