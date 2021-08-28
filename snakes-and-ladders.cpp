class Solution {
public:
    
    void bfs(int s, vector<int> adj[], bool visited[], int dist[]){
        
        queue<int> q;
        visited[s] = true;
        q.push(s);
        
        while(!q.empty()){
            
            int x = q.front();
            q.pop();
            
            for(auto i:adj[x]){
                if(!visited[i]){
                    visited[i] = true;
                    dist[i] = dist[x] + 1;
                    q.push(i);
                }
            }
        }
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        
        vector<int> v;
        
        v.push_back(0);
        
        bool flag = true;
        
        for(int i=board.size()-1;i>=0;i--){
            
            if(flag){
                for(int j=0;j<board.size();j++){
                    v.push_back(board[i][j]);
                }
                flag = false;
            }else{
                for(int j=board.size()-1;j>=0;j--){
                    v.push_back(board[i][j]);
                }
                flag = true;
            }
            
        }
        
        int n = board.size()*board.size();
        
        vector<int> adj[n+1];
        bool visited[n+1];
        int dist[n+1];
        memset(visited,false,sizeof(visited));
        memset(dist,-1,sizeof(dist));
        
        dist[1] = 0;
        
        for(int i=1;i<=n;i++){
            for(int j = i+1; j<=min(i+6,n); j++){
                if(v[j]==-1){
                    adj[i].push_back(j);
                }else{
                    adj[i].push_back(v[j]);
                }
            }
        }
        
        bfs(1,adj,visited,dist);
        
        return dist[n];
    }
};
