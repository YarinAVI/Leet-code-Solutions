class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        std::unordered_map <string,int> occ;
        int i=0;
        vector<string> res;
        while(i+9 < s.size()) {
            if(occ.find(s.substr(i,10)) == occ.end()) {
                occ.insert({s.substr(i,10),1});
            }
            else occ.at(s.substr(i,10))++;
            i++;
        }
        for(auto it=occ.begin();it!=occ.end();it++) {
            if(it->second > 1) res.push_back(it->first);
        }
        return res;
        
    }
};