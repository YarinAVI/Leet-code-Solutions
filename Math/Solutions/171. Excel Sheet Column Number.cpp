class Solution {
public:
    int titleToNumber(string s) {
        double val;
        int j=0;
        int i=s.size()-1;
        while(i>=0) {
            val +=(s[j]-'A' +1)*pow(26,i);
            j++;
            i--;
        }
    return val;
    }
};