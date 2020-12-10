class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> m;
        for(int i=0;i<arr.size();i++) {
           m[arr[i]]++;
        }
        int max = -1;
        for(auto it = m.begin();it!=m.end();it++) {
            if(it->first==it->second && it->first >max) max = it->first;
        }
        return max;
    }
};