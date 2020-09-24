class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int res = 0;
        unordered_map<int,int> m; // value <-> index
        unordered_map<int,int> m1; // value <-> occurrence 
        int i;
        for(i=0;i<nums.size();i++) {
            if(m.find(nums[i])==m.end()) m.insert({nums[i],i}),m1.insert({nums[i],1});
            else {
                res+=m1.at(nums[i]);
                m1.at(nums[i])++;
            }
        }
        return res;
    }
};