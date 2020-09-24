class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
     vector<string> res;
        set<string> s;
        int i,j;
        for(i=0;i<words.size();i++) {
            for(j=0;j<words.size();j++) {
                if(i==j) continue;
                size_t x = words[i].find(words[j]);
                if(x!=string::npos) {
                    s.insert(words[i].substr(x,words[j].size()));
                }
            }
        }
        
        for(auto it = s.begin();it!=s.end();it++) {
            res.push_back(*it);
        }
        return res;
    }
};
