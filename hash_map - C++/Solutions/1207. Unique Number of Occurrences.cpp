class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        unordered_set<int>s;
        for(auto v:arr){
            mp[v]++;
        }
        for(auto i:mp){
            s.insert(i.second);
        }
        return s.size()==mp.size();
    }
};