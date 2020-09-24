// we simply do binary search..
// if the while loop ends and we didnt find the number then we check if the right pointer is lower than left pointer we return
// left, else we return right
int searchInsert(int* nums, int numsSize, int target){
    int r=numsSize-1,l=0;
    int m;
    while(r>=l) {
        m = l + (r-l)/2;
        if(target==nums[m]) return m;
        else if(nums[m]>target) r=m-1;
        else l=m+1;
    }
    //printf("%d %d",r,l);
    if(r<l) {
        return l;
    }
    return r;
}