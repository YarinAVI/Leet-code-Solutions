class Solution {
public:
    string arrangeWords(string text) {
        vector<pair<string,int>> temp;
        string res;
        int i=0,j=0;
        text[0] = tolower(text[0]);
        pair<string,int> x;
        
        
        while(j<text.size()) {
            pair<string,int> t;
            while(text[j]!=' ' && j<text.size())j++;
            t.first =text.substr(i,j-i);
            t.second = i;
            temp.push_back(t);
            j++,i=j;
        }
        sort(temp.begin(),temp.end(),cmp);
        (temp[0].first)[0] = toupper((temp[0].first)[0]);
        
        //for(i=0;i<temp.size();i++) cout<<temp[i] + " ";
        for(i=0;i<temp.size();i++) {
            res+=temp[i].first;
            res+=' ';
        }
        res.pop_back();
        return res;
    }
    static bool cmp(pair<string,int> &a,pair<string,int> &b) {
        if(a.first.size()==b.first.size()) {
            return a.second < b.second;
        }
        else 
            return a.first.size() <b.first.size();
    }
};