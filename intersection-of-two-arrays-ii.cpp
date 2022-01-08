class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        int m = nums2.size();
        
        map<int,int> m1;
        
        for(int i=0;i<n;i++){
            int x = nums1[i];
            m1[x]++;
        }
        
        vector<int> common;
        
        for(int i=0;i<m;i++){
            int x = nums2[i];
            if(m1[x]>0){
                common.push_back(x);
                m1[x]--;
            }
        }
        
        return common;
    }
};
