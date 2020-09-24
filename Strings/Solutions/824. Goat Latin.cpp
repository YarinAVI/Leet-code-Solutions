class Solution {
public:
    string toGoatLatin(string S) {
        string res;
        int i=0,j;
        int c=1;
        while(S[i]==' ') i++;
        for(;i<S.size();) {
            if(S[i]=='a' ||S[i]=='e' ||S[i]=='i' ||S[i]=='o' ||S[i]=='u' || S[i]=='A' ||S[i]=='E' ||S[i]=='I' ||S[i]=='O' ||S[i]=='U') {
                j=i;
                while(S[j]!=' ' && j<S.size())j++;
                res+=S.substr(i,j-i);
                res+="ma";
                while(S[j]==' ' && j<S.size()) j++;
                i=j;
                for(j=0;j<c;j++) res+='a';
                res+=' ';
            }
            else {
                j=i;
                while(S[j]!=' ' && j<S.size())j++;
                if(j-i>1) {
                    res+=S.substr(i+1,j-i-1);
                    res+=S[i];
                } 
                else res+=S.substr(i,j-i);
                res+="ma";
                while(S[j]==' ' && j<S.size()) j++;
                i=j;
                for(j=0;j<c;j++) res+='a';
                res+=' '; 
            }
            //cout<< res << endl;
            c++;
        }
        res.pop_back();
        return res;
    }
};