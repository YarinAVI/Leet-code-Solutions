class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        while(s[i]==' ' && i<s.size()) i++;
        int j=i;
        while(j<s.size()) {
            while(s[j]!=' ' && j<s.size()) j++;
            rev_word(s,i,j-1);
            j++,i=j;
        }
        return s;
    }
private:
    void rev_word(string &source,int i,int j) {
        char t;
        while(i<j) {
            t = source[i];
            source[i] = source[j];
            source[j] = t;
            i++,j--;
        }
    }
};