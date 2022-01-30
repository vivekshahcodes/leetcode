class Solution {
public:
    vector<vector<int>> allSubsequences;
    
    void validCombinations(vector<int>& candidates, int i, int n, int total, int target, vector<int> currentSubsequence){
        
        if(total==target){
            allSubsequences.push_back(currentSubsequence);
            return;
        }
        
        for(int ind=i;ind<n;ind++){
            if(ind>i && candidates[ind]==candidates[ind-1]){
                continue;
            }
            if(total>target){
                break;
            }
            currentSubsequence.push_back(candidates[ind]);
            validCombinations(candidates,ind+1,n,total+candidates[ind],target,currentSubsequence);
            currentSubsequence.pop_back();
        }
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        int n = candidates.size();
        sort(candidates.begin(),candidates.end());
        
        vector<int> currentSubsequence;
        
        validCombinations(candidates,0,n,0,target,currentSubsequence);
        
        return allSubsequences;
    }
};
