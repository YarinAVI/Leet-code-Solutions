class Solution {
public:
    int hIndex(vector<int>& c) {
        int res=0;

        sort(c.begin(),c.end());
        int i;
        for(i=0;i<c.size();i++) {
            if(c[i] == 0 ) continue;
            else if(c.size() - i >c[i]) res= c[i];
            else if(c.size() - i ==c[i]) {
                res= c[i];
                return res;
            }
            else if(c.size() -i <c[i] && (c.size()-i + c.size()-i)>=c.size()) {
                if(c.size()-i > res) res = c.size()-i;
                
            }  
            
            else if(c[i]>=c.size()) {
                if(c.size()-i>res) return c.size()-i;
            }
                
        }
        return res;
    }
};