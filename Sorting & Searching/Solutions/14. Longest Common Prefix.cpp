class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        if(strs.size()==0) return res;
        sort(strs.begin(),strs.end(),cmp);
        
        int i,j;
/*        for(i=0;i<strs.size();i++) {
            for(j=0;j<strs[i].size();j++) cout<< strs[i][j];
            cout << endl;
        }
        */
        int min_lenght = INT_MAX;
        for(i=0;i<strs.size();i++) {
            if(strs[i].size() < min_lenght) min_lenght = strs[i].size();
        }
        for(i=0;i<min_lenght;i++) {
            for(j=0;j<strs.size()-1;j++) if(strs[j][i]!=strs[j+1][i]) return res;
            res+=strs[0][i];
        }
        return res;
    }
    static bool cmp(string &a,string &b) {
        return a<b;
    }
};