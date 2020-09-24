class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
    vector<string> map ={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        vector<string> converted;
        unordered_map<string,bool> h_map;
        int i;
        int j;
        int res = 0;
        for(i=0;i<words.size();i++) {
            string temp;
            for(j=0;j<words[i].size();j++) {
                temp+=map[words[i][j]-'a'];
            }
            converted.push_back(temp);
        }
       
        for(i=0;i<converted.size();i++) {
            if(h_map.find(converted[i])==h_map.end()) res++, h_map.insert({converted[i],true});
            else continue;
        }
        return res;
        
    }
};