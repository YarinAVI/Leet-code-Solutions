class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int i;
        unordered_map<int,int> map;
        for(i=0;i<nums.size();i++) {
            if(map.find(nums[i])!=map.end()) return true;
            else map.insert({nums[i],i});
        }
        return false;
    }
};