class Solution {
public:
    bool wordPattern(string &pattern, string &str) {
    if (pattern.size() ==0 || str.size()==0) return false;
    unordered_map<char,string> map;
    unordered_map<string,char> map_str;
        int i =0, j=0,k=0;
        while(str[i]==' ' && i<str.size()) i++;
        k=i;
        while(j<pattern.size() && k<str.size()) {
            //not found
            if(map.find(pattern[j])==map.end()) {
                // add char to hashmap
                while(str[i]!=' ' && i <str.size()) i++;
                if(map_str.find(str.substr(k,i-k) ) != map_str.end()) { 
                    if(map_str.at(str.substr(k,i-k))!=pattern[j]) return false;
                }
                map.insert({pattern[j],str.substr(k,i-k)});
                map_str.insert({str.substr(k,i-k),pattern[j]});
                i++,k=i;
            }
            //found
            else {
                while(str[i]!=' ' && i<str.size()) i++;
                if(map.at(pattern[j]) !=str.substr(k,i-k)) return false;
                i++,k=i;
            }
            j++;
        }
        if(j<pattern.size() || k<str.size()) return false;
        return true;
    }
};