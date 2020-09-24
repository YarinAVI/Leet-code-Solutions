class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int,int> map;
        int i;
        for(i=0;i<nums.size();i++) {
            if(map.find(target-nums[i])!=map.end()) {
                res.push_back(map.at(target-nums[i]));
                res.push_back(i);
                break;
            }
            else map.insert({nums[i],i});
        }
        return res;
    }
};