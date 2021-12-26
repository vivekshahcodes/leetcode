class Solution {
public:
    
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,-1,0,1};
    
    void dfs(vector<vector<int>>& image, int sr, int sc, int currColor, int newColor, int n, int m){
        
        if(sr<0 || sc<0 || sr>=n || sc>=m){
            return;
        }
        
        if(image[sr][sc]!=currColor){
            return;
        }
        
        image[sr][sc] = newColor;
        
        for(int i=0;i<4;i++){
            if(currColor!=newColor){
                dfs(image,sr+dx[i],sc+dy[i],currColor,newColor,n,m);
            }
        }
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int n = image.size();
        int m = image[0].size();
        int currColor = image[sr][sc];
        
        dfs(image,sr,sc,currColor,newColor,n,m);
        
        return image;
    }
};
