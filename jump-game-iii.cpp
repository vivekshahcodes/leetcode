class Solution {
public:
    
    bool isPossible(int i, int n, vector<int>& arr, vector<bool>& visited, vector<int>& dp){
        
        if(arr[i]==0){
            return dp[i] = true;
        }else{
            visited[i] = true;
        }
        
        if(dp[i]!=-1){
            return dp[i];
        }
        
        bool right = false;
        if(i+arr[i]<n && !visited[i+arr[i]]){
            right = isPossible(i+arr[i],n,arr,visited,dp);
        }
        bool left = false;
        if(i-arr[i]>=0 && !visited[i-arr[i]]){
            left = isPossible(i-arr[i],n,arr,visited,dp);
        }
        
        return dp[i] = left||right;
    }
    
    bool canReach(vector<int>& arr, int start) {
        
        int n = arr.size();
        vector<bool> visited(n,false);
        
        vector<int> dp(n,-1);
        
        return isPossible(start,n,arr,visited,dp);
    }
};
