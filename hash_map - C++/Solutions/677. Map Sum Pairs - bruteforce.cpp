class MapSum {
public:
    /** Initialize your data structure here. */
    unordered_map<string,int> m;
    MapSum() {
    }
    
    void insert(string key, int val) {
        if(m.find(key) == m.end()) {
            m.insert({key,val});
        } 
        else {
            m.at(key) = val;
        }
    }
    int sum(string prefix) {
        int res = 0;
        for(auto i = m.begin();i!=m.end();i++) {
            if(i->first.substr(0,prefix.size())==prefix) res+=i->second;
        }
        return res;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */