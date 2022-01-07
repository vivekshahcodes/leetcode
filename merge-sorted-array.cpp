class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int ind = m+n-1;
        int i = m-1;
        int j = n-1;
        
        while(i>=0 && j>=0 && ind>=0){
            
            if(nums1[ind]!=0){
                ind--;
                continue;
            }
            
            if(nums1[i]>nums2[j]){
                swap(nums1[i],nums1[ind]);
                i--;
                ind--;
            }else{
                nums1[ind] = nums2[j];
                nums2[j] = 0;
                ind--;
                j--;
            }
        }
        
        i = 0;
        j = 0;
        
        while(j<n && nums2[j]!=0){
            nums1[i] = nums2[j];
            i++;
            j++;
        }
    }
};
