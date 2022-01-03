class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        vector<int> trustValue(n+1,0);
        
        for(auto i:trust){
            int a = i[0];
            int b = i[1];
            trustValue[a]--;
            trustValue[b]++;
        }
        
        for(int i=1;i<=n;i++){
            if(trustValue[i]==n-1){
                return i;
            }
        }
        
        return -1;
        
    }
};
