//Brute Force
//TC - O(n^2)
//SC - O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        
        for(int x:nums){
            int c = 0;
            for(int y:nums){
                if(x==y) c++;
            }
            if(c>(n/2)) return x;
        }
        
        return -1;
    }
};


//Sorting Approach
//TC - O(nlogn)
//SC - O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(),nums.end());
        return nums[(n-1)/2];
    }
};


//Hashmap Approach
//TC - O(n)
//SC - O(n) for the hashmap

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int,int> m;
        
        for(int x:nums){
            m[x]++;
            if(m[x]>(n/2)) return x;
        }
        
        return -1;
    }
};


//Boyer-Moore Voting Algorithm
//TC - O(n)
//SC - O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n = nums.size(), curr = 0, candidate;
        
        for(int x:nums){
            if(curr==0) candidate = x;
            if(x==candidate) curr++;
            else curr--;
        }
        
        return candidate;
    }
};
