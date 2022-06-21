class Solution {
public:
    
    int findParent(int x, vector<int>& parent){
        if(x==parent[x]){
            return x;
        }
        return parent[x] = findParent(parent[x],parent);
    }
    
    void unionn(int u, int v, vector<int>& parent, vector<int>& rank){
        u = findParent(u,parent);
        v = findParent(v,parent);
        
        if(rank[u]<rank[v]){
            parent[u] = v;
        }else if(rank[v]<rank[u]){
            parent[v] = u;
        }else{
            parent[v] = u;
            rank[u]++;
        }
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();
        vector<int> parent(n+1);
        
        for(int i=1;i<=n;i++){
            parent[i] = i;
        }
        
        vector<int> rank(n+1,0);
        vector<int> extraEdge;
        
        for(auto i:edges){
            if(findParent(i[0],parent)==findParent(i[1],parent)){
                extraEdge.push_back(i[0]);
                extraEdge.push_back(i[1]);
            }else{
                unionn(i[0],i[1],parent,rank);
            }
        }
        
        return extraEdge;
    }
};
