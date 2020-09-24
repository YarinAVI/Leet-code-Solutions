//https://leetcode.com/problems/running-sum-of-1d-array/submissions/

int* runningSum(int* nums, int numsSize, int* returnSize){
int *res= (int*)malloc(numsSize*sizeof(int));
    *returnSize=numsSize;
    int tmp=0,i,j,k=0;
    for(i=0;i<numsSize;i++) tmp+=nums[i];
    //res[numsSize-1]=tmp;
    for(j=numsSize-1,i=numsSize-1;i>=0;i--,j--) {
      res[i]=tmp;
        tmp-=nums[j];
    }
    return res;
}