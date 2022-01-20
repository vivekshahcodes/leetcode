class Solution {
public:
    string reverseWords(string s) {
        
        int n = s.length();
        
        vector<string> words;
        string currWord;
        
        for(int i=0;i<n;i++){
            if(s[i]!=' '){
                currWord += s[i];
            }else{
                if(currWord.length()>0){
                    words.push_back(currWord);
                    currWord.clear();
                }
            }
        }
        
        if(currWord.length()>0){
            words.push_back(currWord);
        }
        
        string ans;
        int noOfWords = words.size();
        
        for(int i=noOfWords-1;i>=1;i--){
            ans += words[i];
            ans.push_back(' ');
        }
        
        ans += words[0];
        
        return ans;
        
    }
};
