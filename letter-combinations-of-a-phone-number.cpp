class Solution {
public:
    
    vector<string> keypad = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    void allCombinations(int i, string digits, string &curr, vector<string>& v){
        
        if(i==digits.length()){
            v.push_back(curr);
            return;
        }
        
        int currDigit = digits[i]-'0';
        
        for(int c=0;c<keypad[currDigit].length();c++){
            curr.push_back(keypad[currDigit][c]);
            allCombinations(i+1,digits,curr,v);
            curr.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0){
            return {};
        }
        vector<string> v;
        string curr;
        allCombinations(0,digits,curr,v);
        return v;
    }
};
