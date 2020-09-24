class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        sort(A.begin(),A.end(),cmp);
        return A;
    }
    static bool cmp(int a, int b) {
        if(a%2<b%2) return true;
        else return false;
}
};