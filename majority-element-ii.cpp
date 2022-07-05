//Hashmap Solution
//TC - O(n)
//SC - O(n) for the hashmap

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        vector<int> ans;
        int n = nums.size();
        unordered_map<int,int> m;
        
        for(int x:nums) m[x]++;
        for(auto x:m) if(x.second>(n/3)) ans.push_back(x.first);
        
        return ans;
    }
};


//Modified Boyer Moore Voting Algorithm
//TC - O(n)
//SC - O(1)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        vector<int> ans;
        int n = nums.size(), freq1 = 0, freq2 = 0, candidate1 = -1, candidate2 = -1;
        
        for(int x:nums){
            if(x==candidate1){
                freq1++;
            }else if(x==candidate2){
                freq2++;
            }else if(freq1==0){
                candidate1 = x;
                freq1 = 1;
            }else if(freq2==0){
                candidate2 = x;
                freq2 = 1;
            }else{
                freq1--;
                freq2--;
            }
        }
        
        freq1 = 0, freq2 = 0;
        for(int x:nums){
            if(x==candidate1) freq1++;
            else if(x==candidate2) freq2++;
        }
        
        if(freq1>(n/3)) ans.push_back(candidate1);
        if(freq2>(n/3)) ans.push_back(candidate2);
        
        return ans;
    }
};
