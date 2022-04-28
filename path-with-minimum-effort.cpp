class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int n = heights.size();
        int m = heights[0].size();
        
        int d[5] = {-1, 0, 1, 0, -1};

        vector<vector<int>> efforts(n, vector<int>(m, INT_MAX));
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.emplace(0, 0);
        
        while (!q.empty()) {
            
          int effort = q.top().first;
          int x = q.top().second / 100, y = q.top().second % 100;
          q.pop();

          if (x == n - 1 && y == m - 1){
              return effort;
          }
            
          if (effort >= efforts[x][y]){
              continue;
          }
            
          efforts[x][y] = effort;

          for (int i = 0; i < 4; i++) {
              
            int nx = x + d[i], ny = y + d[i + 1];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m){
                continue;
            }
              
            int n_effort = max(effort, abs(heights[x][y] - heights[nx][ny]));
            q.emplace(n_effort, nx * 100 + ny);
          }
        }
        return -1;
    }
};
