class Solution {
public:
    vector<vector<int>> validCombinations;
    
    void combinationFinder(vector<int>& candidates, int i, int k, int curr, int n, vector<int> v){
        
        if(i==9){
            if(curr==n && v.size()==k){
                validCombinations.push_back(v);
            }
            return;
        }
        
        if(curr>n || v.size()>k){
            return;
        }
        
        v.push_back(candidates[i]);
        combinationFinder(candidates,i+1,k,curr+candidates[i],n,v);
        v.pop_back();
        combinationFinder(candidates,i+1,k,curr,n,v);
        
        return;
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<int> v;
        vector<int> candidates = {1,2,3,4,5,6,7,8,9};
        combinationFinder(candidates,0,k,0,n,v);
        
        return validCombinations;
    }
};
