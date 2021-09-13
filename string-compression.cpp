class Solution {
public:
    int compress(vector<char>& chars) {
        
        int curr = 1, ind = 1;
        char prev = chars[0];
        
        for(int i=1;i<chars.size();i++){
            
            if(chars[i]==prev){
                
                curr++;
                
                if(i == chars.size()-1){
                    
                    string temp = to_string(curr);
                    
                    for(int i = 0; i < temp.length(); i++){
                        
                        chars[ind] = temp[i];
                        ind++;
                        
                    }
                }
                
            }else{
                
                prev = chars[i];
                
                if(curr > 1){
                    
                    string temp = to_string(curr);
                
                    for(int i = 0; i < temp.length(); i++){
                        
                        chars[ind] = temp[i];
                        ind++;
                        
                    }
                }
                
                chars[ind] = prev;
                
                ind++;
                
                curr = 1;
            }
        }
        
        return ind;
    }
};
