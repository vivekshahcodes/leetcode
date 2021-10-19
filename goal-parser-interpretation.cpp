class Solution {
public:
    string interpret(string command) {
        
        string s;
        
        for(int i = 0; i < command.length(); i++){
            if(command[i]=='G'){
                s.push_back('G');
            }else if(command[i+1]=='a'){
                s += "al";
                i+=3;
            }else{
                s.push_back('o');
                i++;
            }
        }
        
        return s;
    }
};
