class Solution {
public:
    
    bool isCyclic(int s, vector<int>adj[], vector<bool>& visited, vector<bool>& inDfs){
	
        visited[s] = true;
        inDfs[s] = true;

        for(auto i:adj[s]){
            if(!visited[i]){
                if(isCyclic(i,adj,visited,inDfs)){
                    return true;
                }
            }else if(inDfs[i]){
                return true;
            }
        }

        inDfs[s] = false;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> adj[numCourses+1];
        
        for(auto i:prerequisites){
            int a = i[0];
            int b = i[1];
            adj[b].push_back(a);
        }
        
        vector<bool> visited(numCourses+1,false), inDfs(numCourses+1,false);
        
        bool hasCycle = false;
        
        for(int i=1;i<=numCourses;i++){
            if(!visited[i]){
                hasCycle |= isCyclic(i,adj,visited,inDfs);
            }
        }
        
        return !hasCycle;
    }
};
