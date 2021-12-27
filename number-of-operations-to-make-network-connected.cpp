class Solution {
public:
    
    void dfs(int s, vector<int> adj[], bool visited[]){
        
        visited[s] = true;
        
        for(auto i:adj[s]){
            if(!visited[i]){
                dfs(i,adj,visited);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        int m = connections.size();
        
        if(m<n-1) return -1;
        
        vector<int> adj[n];
        bool visited[n];
        memset(visited,false,sizeof(visited));
        
        for(int i=0;i<m;i++){
            int x = connections[i][0];
            int y = connections[i][1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        
        int components = 0;
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                components++;
                dfs(i,adj,visited);
            }
        }     
        
        return components-1;
        
    }
};
