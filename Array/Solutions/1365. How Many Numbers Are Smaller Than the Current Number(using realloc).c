int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize){
    int *res = NULL;
    (*returnSize) =0;
    int i,j;
    for(i=0;i<numsSize;i++) {
        int c = 0;
        for(j=0;j<numsSize;j++) {
            if(j==i) continue;
            if(nums[i]>nums[j]) c++;
        }
        res =(int*)realloc(res,++(*returnSize)*sizeof(int));
        res[(*returnSize)-1] = c;
    }
    return res;
}