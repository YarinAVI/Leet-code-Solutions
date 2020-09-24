int* decompressRLElist(int* nums, int numsSize, int* returnSize){
    int i,j,k,size=0;
    for(i=0;i<numsSize-1;i+=2) size+=nums[i];
    int *res =(int*)malloc(sizeof(int)*size);
    *returnSize=size;
    //printf("%d",size);
    for(k=0,i=0,j=1;j<numsSize;j+=2,i+=2) {
        while(nums[i]) res[k++] = nums[j],nums[i]--;
    }
    return res;    
}