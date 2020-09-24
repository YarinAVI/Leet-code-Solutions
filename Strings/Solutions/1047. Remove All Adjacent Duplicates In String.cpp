class Solution {
public:
    string removeDuplicates(string S) {
        string res;
        int i=0,j=1;
        while(j<=S.size()) {
            if(res.empty()) res.push_back(S[i]),i++,j++;
            else if(S[i]!=S[j]) {
                if(res.back()==S[i]) res.pop_back(),i++,j++;
                else res.push_back(S[i]),i++,j++;
                
            }
            else i+=2,j+=2;
        }
        return res;
    }
};