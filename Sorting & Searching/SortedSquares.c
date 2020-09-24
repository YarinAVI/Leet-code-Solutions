#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>
int* sortedSquares(int* A, int ASize, int* returnSize){
    int *res=(int*)malloc(ASize * sizeof(int));
    *returnSize=ASize;
    int i=0,j=ASize-1,k=ASize-1;
    while(i<=j) {
            if(A[j]>=abs(A[i])) res[k--]=pow(A[j--],2);
            else res[k--]=pow(A[i++],2);
    }
    return res;
}
int main()
{
    int i;
    int nums[7]={-3,-2,-1,0,1,2,3};
    int s=sizeof(nums)/sizeof(nums[0]);
    int returnSize1=0;
    int *result=sortedSquares(nums,s,&returnSize1);
    for(i=0;i<returnSize1;i++,result++) {
        printf("%d ",*result);
    }
}
