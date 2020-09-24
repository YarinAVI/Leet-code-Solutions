
int cmp(const void *a,const void *b) {
    return (*(int*)a-*(int*)b);
}
int minMoves2(int* nums, int numsSize){
    int res= 0;
    qsort(nums,numsSize,sizeof(int),cmp);
    int i;
    int m = (numsSize-1)/2;
    for(i=m+1;i<numsSize;i++) {
        res+=nums[i]-nums[m];
    }
    for(i=0;i<m;i++) {
        res+=nums[m]-nums[i];
    }
    return res;
}