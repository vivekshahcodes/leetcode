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

    void dfs(int s, vector<int> adj[], vector<bool>& visited, vector<int>& ans){

        visited[s] = true;

        for(auto i:adj[s]){
            if(!visited[i]){
                dfs(i,adj,visited,ans);
            }
        }

        ans.push_back(s);
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> adj[numCourses];
        
        for(auto i:prerequisites){
            int a = i[0];
            int b = i[1];
            adj[b].push_back(a);
        }
        
        vector<bool> visited(numCourses,false), inDfs(numCourses,false);
        bool hasCycle = false;
        
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                hasCycle |= isCyclic(i,adj,visited,inDfs);
            }
        }
        
        vector<int> ans;
        
        if(hasCycle){
            return ans;
        }
        
        for(int i=0;i<numCourses;i++){
            visited[i] = false;
        }
        
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                dfs(i,adj,visited,ans);
            }
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};
