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
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        int m = isConnected[0].size();
        
        vector<int> adj[n+1];
        bool visited[n+1];
        memset(visited,false,sizeof(visited));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==j) continue;
                if(isConnected[i][j]==1){
                    adj[i+1].push_back(j+1);
                }
            }
        }
        
        int provinces = 0;
        
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                provinces++;
                dfs(i,adj,visited);
            }
        }
        
        return provinces;
    }
};
