
// this solution is using sort(nlogn) complexity, because we are required only K closest we can do better using heap and other solutions.. 
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(points.begin(),points.end(),cmp);
        while(points.size()>K) points.pop_back();
        return points;
    }
private:
    static bool cmp(vector<int> a,vector<int> b) {
        return sqrt(pow(a[0]-0,2) + pow(a[1]-0,2)) <sqrt(pow(b[0]-0,2) + pow(b[1]-0,2));
    }
};