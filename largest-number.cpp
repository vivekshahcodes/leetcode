bool comp(string a, string b){
    return a+b>b+a;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        string ans;
        
        vector<string> v;
        
        for(int i=0;i<nums.size();i++){
            v.push_back(to_string(nums[i]));
        }
        
        sort(v.begin(),v.end(),comp);
        
        for(string i:v){
            ans += i;
        }
        
        string finalAns;
        
        int i = 0;
        
        while(i<ans.length() && ans[i]=='0'){
            i++;
        }
        
        for(int j=i;j<ans.length();j++){
            finalAns += ans[j];
        }
        
        if(finalAns.length()==0){
            finalAns += "0";
        }
        
        return finalAns;
        
    }
};
