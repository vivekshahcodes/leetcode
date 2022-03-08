class Solution {
public:
    
    int largestHistogram(vector<int>& v){
        
        int n = v.size();
        vector<int> left(n), right(n);
        stack<int> l,r;
        
        for(int i=0;i<n;i++){
            int curr = v[i];
            
            while(!l.empty() && v[l.top()]>=curr){
                l.pop();
            }
            
            if(l.empty()){
                left[i] = -1;
                l.push(i);
            }else{
                left[i] = l.top();
                l.push(i);
            }
        }
        
        for(int i=n-1;i>=0;i--){
            int curr = v[i];
            
            while(!r.empty() && v[r.top()]>=curr){
                r.pop();
            }
            
            if(r.empty()){
                right[i] = n;
                r.push(i);
            }else{
                right[i] = r.top();
                r.push(i);
            }
        }
        
        int ans = 0;
        
        for(int i=0;i<n;i++){
            ans = max(ans,v[i]*(right[i]-left[i]-1));
        }
        
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> v(n, vector<int> (m));
        
        for(int j=0;j<m;j++){
            v[0][j] = matrix[0][j]-'0';
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='0'){
                    v[i][j] = 0;
                }else{
                    v[i][j] = v[i-1][j]+1;
                }
            }
        }
        
        int ans = 0;
        
        for(int i=0;i<n;i++){
            ans = max(ans,largestHistogram(v[i]));
        }
        
        return ans;
    }
};
