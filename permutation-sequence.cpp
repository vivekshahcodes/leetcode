class Solution {
public:
    void getFactorial(int n, vector<int>& factorial){
        
        int curr = 1;
        for(int i=1;i<=n;i++){
            curr*=i;
            factorial[i] = curr;
        }
    }
    
    void findKthPermutation(int n, int k, vector<int>& factorial, string &ans, vector<int>& v){
        
        if(n==1){
            ans += to_string(v[0]);
            return;
        }
        
        int block = k/factorial[n-1];
        
        if(k%factorial[n-1]==0){
            block--;
        }
        
        ans += to_string(v[block]);
        v.erase(v.begin()+block);
        k -= factorial[n-1]*block;
        
        findKthPermutation(n-1,k,factorial,ans,v);
    }
    
    string getPermutation(int n, int k) {
        
        if(n==1) return "1";
        
        vector<int> factorial(n+1);
        getFactorial(n,factorial);
        
        vector<int> v(n);
        for(int i=0;i<n;i++){
            v[i] = i+1;
        }
        
        string ans;
        
        findKthPermutation(n,k,factorial,ans,v);
        
        return ans;
    }
};
