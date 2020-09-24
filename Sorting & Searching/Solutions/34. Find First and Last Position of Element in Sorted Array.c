

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int *res = malloc(2*sizeof(int));
    *returnSize =2;
    res[0]=-1,res[1] = -1;
    int l=0,r=numsSize-1,m;
    // find left most
    while(l<=r) {
        int m = l+(r-l)/2;
        if(nums[m]==target) {
            res[0]=m;
            r=m-1;
        }
        else if(nums[m]>target) r=m-1;
        else if(nums[m]<target) l=m+1;
        
    }
    l=0,r=numsSize-1;
        while(l<=r) {
        int m = l+(r-l)/2;
        if(nums[m]==target) {
            res[1]=m;
            l=m+1;
        }
        else if(nums[m]>target) r=m-1;
        else if(nums[m]<target) l=m+1;
    }
    return res;
}