//Brute Force
//TC - O((n+m)log(n+m)) for sorting + O(n+m) for iteration + O(n+m) for copying
//SC - O(n+m) for the v array

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        vector<int> v(m+n);
        int ind = 0;
        
        for(int i=0;i<m;i++) v[ind++] = nums1[i];
        for(int i=0;i<n;i++) v[ind++] = nums2[i];
        sort(v.begin(),v.end());
        nums1 = v;
    }
};


//Two Pointer Approach
//TC - O(n+m)
//SC - O(1)

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int i=m-1,j=n-1,ind=m+n-1;
        
        while(i>=0 && j>=0){
            if(nums1[i]<nums2[j]) nums1[ind--] = nums2[j--];
            else nums1[ind--] = nums1[i--];
        }
        
        while(j>=0) nums1[ind--] = nums2[j--];
    }
};
