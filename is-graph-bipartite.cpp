class Solution {
public:
    
    bool dfs(int s, vector<vector<int>>& graph, int visited[], int color){
        
        visited[s] = color;
        
        for(auto i:graph[s]){
            
            if(visited[i]==0){
                int newColor = color==1?2:1;
                bool subProblem = dfs(i,graph,visited,newColor);
                if(!subProblem){
                    return false;
                }
            }else if(visited[i]==visited[s]){
                return false;
            }
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        
        int visited[n];
        memset(visited,0,sizeof(visited));
        
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                if(!dfs(i,graph,visited,1)){
                    return false;
                }
            }
        }
        
        return true;
    }
};
