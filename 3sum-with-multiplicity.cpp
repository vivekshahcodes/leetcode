class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        
        int n = arr.size(), m = 1e9+7;
        long ans = 0;
        
        sort(arr.begin(),arr.end());
        
        for(int i=0;i<n;i++){
            
            int t = target-arr[i];
            int j = i+1, k = n-1;
            
            while(j<k){
                
                if(arr[j]+arr[k]<t){
                    j++;
                }else if(arr[j]+arr[k]>t){
                    k--;
                }else if(arr[j]!=arr[k]){
                    
                    int left = 1, right = 1;
                    
                    while(j+1<k && arr[j]==arr[j+1]){
                        left++;
                        j++;
                    }
                    
                    while(k-1>j && arr[k]==arr[k-1]){
                        right++;
                        k--;
                    }
                    
                    ans = (ans+(left*right))%m;
                    j++;
                    k--;
                }else{
                    int x = k-j+1;
                    ans = (ans+(x*(x-1))/2)%m;
                    break;
                }
            }
        }
        
        return int(ans);
    }
};
