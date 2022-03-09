class Solution {
public:
    string simplifyPath(string path) {
        
        int n = path.length();
        stack<string> s;
        vector<string> v;
        string curr;
        
        for(int i=1;i<n;i++){
            if(path[i]=='/'){
                if(!curr.empty()){
                    v.push_back(curr);
                    curr.clear();
                }
            }else{
                curr.push_back(path[i]);
            }
        }
        
        if(!curr.empty()){
            v.push_back(curr);
        }
        
        for(string str:v){
            if(str=="."){
                continue;
            }else if(str==".."){
                if(!s.empty()){
                    s.pop();
                }
            }else{
                s.push(str);
            }
        }
        
        string ans;
        
        if(s.empty()){
            return "/";
        }
        
        while(!s.empty()){
            string x = s.top();
            s.pop();
            ans = "/" + x + ans;
        }
        
        return ans;
        
    }
};
