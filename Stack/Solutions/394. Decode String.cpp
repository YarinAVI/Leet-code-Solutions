class Solution {
public:
    string decodeString(string s) {
        stack<int> number_stack;
        string res;
        int i=0,j;
        while(i<s.size()) {
            if(s[i]>='0' && s[i]<='9') {
                number_stack.push(stoi(s.substr(i,s.size())));
                while(s[i]>='0' && s[i]<='9') i++;
            }
            else if(s[i]> '9' && s[i] !=']') {
                res.push_back(s[i]);
                i++;
            }
            else if(s[i]==']') {
                string temp;
                while(res.back() !='[') temp += res.back(),res.pop_back();
                res.pop_back(); // getting rid of the '['
                // now temp holds the word in reverse order, we have to parse it into res, stack.top() times
                int k = number_stack.top();
                number_stack.pop();
                while(k>0) {
                  for(j=temp.size()-1;j>=0;j--) res+=temp[j];
                  k--;
                }
                i++;
            }
        }
        return res;
    }
};