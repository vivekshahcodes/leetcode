class Solution {
public:
    
    vector<vector<int>> allCombinations;
    
    void validCombinations(vector<int>& candidates, int i, int n, int sum, int target, vector<int>& v){
        
        if(i==n){
            if(sum==target){
                allCombinations.push_back(v);
            }
            return;
        }
        
        if(sum>target){
            return;
        }
        
        v.push_back(candidates[i]);
        validCombinations(candidates,i,n,sum+candidates[i],target,v);
        v.pop_back();
        validCombinations(candidates,i+1,n,sum,target,v);
        
        return;        
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        int n = candidates.size();
        vector<int> v;
        
        validCombinations(candidates,0,n,0,target,v);
        
        return allCombinations;
    }
};
