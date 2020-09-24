#include <stdio.h>
int removeduplicates(int* nums, int numsSize) {
if(numsSize==1) return 1;
if (numsSize==0) return 0;
int f=0;
int c=0,i=f,j=f+1;
while(j<=numsSize-1) {
i=f;
c=0;
while(nums[i]!=nums[j]) if(j!=numsSize-1) i++,j++; else return j+1;
while(nums[i]==nums[j]) {
    c++;
    if(j!=numsSize-1) j++;
    else {
        nums[i+1]=nums[j];
        return numsSize-c;
    }
}
nums[++i]=nums[j];
f=i;
while(j<numsSize-1) nums[++i]=nums[++j];
numsSize-=c;
j=f+1;
}
return numsSize;
}

int main () {
 int nums[16] = {1,2,3,3,3,3,3,5,6,8,8,9,9,10,15,20};
 int numsSize = sizeof(nums)/sizeof(nums[0]);
 int i;
printf("New Size is :%d ",numsSize=removeduplicates(nums,numsSize));
printf("New array is:\n");
for(i=0;i<numsSize;i++) printf("%d ",nums[i]);
}
