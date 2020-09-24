class Solution {
public:
    string thousandSeparator(int n) {
        if(n<1000) return std::to_string(n);
        string k = std::to_string(n);
        reverse(k.begin(),k.end());
        string res;
        int i;
        for(i=k.size()-1;i>=0;i--) {
            res+=k[i];
            if(i %3 == 0 ) res+='.';
        }
        res.pop_back();
        return res;
    }
};