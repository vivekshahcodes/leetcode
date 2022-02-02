class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        int patternLength = p.length();
        int stringLength = s.length();
        
        if(stringLength<patternLength){
            return{};
        }

        map<char,int> patternMap;
        
        for(int i=0;i<patternLength;i++){
            patternMap[p[i]]++;
        }
        
        int matchingElements = 0;
        map<char,int> stringMap;
        
        for(int i=0;i<patternLength;i++){
            stringMap[s[i]]++;
            if(stringMap[s[i]]<=patternMap[s[i]]){
                matchingElements++;
            }
        }
        
        int i=0,j=patternLength-1;
        
        vector<int> startingIndices;
        
        while(j<stringLength){
            if(matchingElements==patternLength){
                startingIndices.push_back(i);
            } 
            stringMap[s[i]]--;
            if(stringMap[s[i]]<patternMap[s[i]]){
                matchingElements--;
            }
            i++;
            j++;
            if(j==stringLength){
                break;
            }
            stringMap[s[j]]++;
            if(stringMap[s[j]]<=patternMap[s[j]]){
                matchingElements++;
            }
        }
        
        return startingIndices;
        
    }
};
