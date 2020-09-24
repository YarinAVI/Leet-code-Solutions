class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = {-1,-1};
        int l=0,r=nums.size()-1,m;
        // find left most
        while(l<=r) {
            m=l+(r-l)/2;
            if(nums[m]==target) {
                res[0]=m;
                r=m-1;
            }
            else if(nums[m]>target) r=m-1;
            else if(nums[m]<target) l=m+1;
        }
        // find right most
        l=0,r=nums.size()-1;
        while(l<=r) {
            m=l+(r-l)/2;
            if(nums[m]==target) {
                res[1]=m;
                l=m+1;
            }
            else if(nums[m]>target) r=m-1;
            else if(nums[m]<target) l=m+1;
        }
        return res;
    }
};