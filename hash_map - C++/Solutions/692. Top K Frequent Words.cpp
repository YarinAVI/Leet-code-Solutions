class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int i;
        vector<string> res;
        unordered_map<string,int> umap;
        vector<pair<string,int>> temp;
        int x=0;
        for(i=0;i<words.size();i++) {
            if(umap.find(words[i])==umap.end()) umap.insert({words[i],1});
            else umap.at(words[i])++;
        }
        for(auto j=umap.begin();j!=umap.end();j++) {
            pair<string,int> t1;
            t1.first = j->first;
            t1.second = j->second;
            temp.push_back(t1);
        }
        sort(temp.begin(),temp.end(),cmp);
        for(i=0;i<k;i++) res.push_back(temp[i].first);
        return res;
    }
    static bool cmp(pair<string,int> &a, pair<string,int> &b) {
        if(a.second == b.second) return a.first<b.first;
        return a.second > b.second;
    }
};