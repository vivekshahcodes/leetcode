class Solution {
public:
    
    void dfs(int s, int p, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &tin, vector<int> &low, int &timer, vector<vector<int>>& bridges){
        
        visited[s] = true;
        tin[s] = low[s] = timer++;
        
        for(int i:adj[s]){
            if(i==p){
                continue;
            }else if(visited[i]){
                low[s] = min(low[s],tin[i]);
            }else{
                dfs(i,s,adj,visited,tin,low,timer,bridges);
                low[s] = min(low[s],low[i]);
                
                if(low[i]>tin[s]){
                    bridges.push_back({s,i});
                }
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<bool> visited(n,false);
        vector<int> tin(n), low(n);
        int timer = 0;
        
        vector<vector<int>> adj(n);
        
        for(auto i:connections){
            int a = i[0], b = i[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        vector<vector<int>> bridges;
        
        dfs(0,-1,adj,visited,tin,low,timer,bridges);
        
        for(int i=0;i<n;i++){
            cout<<tin[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<n;i++){
            cout<<low[i]<<" ";
        }
        cout<<endl;
        
        return bridges;
    }
};
