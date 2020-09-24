class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int i,j;
        vector<vector<string>> res;
        if(strs.size()==1) {
            res.push_back(strs);
            return res;
        }
        vector<string> empty_s;
        for(i=0;i<strs.size();i++) if(strs[i]=="") empty_s.push_back(strs[i]);
        if(!empty_s.empty()) res.push_back(empty_s);
        
        for(i=0;i<strs.size()-1;i++) {
            if(strs[i]=="") continue;
            int h1[26] = {0};
            for(int k=0;k<strs[i].size();k++)h1[strs[i][k]-'a']++;
            vector<string> temp;
            temp.push_back(strs[i]);
            for(j=i+1;j<strs.size();j++) {
                int h2[26] = {0};
                for(int k=0;k<strs[j].size();k++) {
                    h2[strs[j][k]-'a']++;
                }
                if(!memcmp(&h1,&h2,26*sizeof(int))) {
                    temp.push_back(strs[j]);
                    strs[j]="";
                } 
            }
            res.push_back(temp);
        }
        if(strs[strs.size()-1]!="") res.push_back({strs[strs.size()-1]});
        return res;
    }
};