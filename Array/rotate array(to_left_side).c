#include <stdio.h>
void rotate(int* nums, int numsSize, int k){
int i,temp,t;
if (numsSize <= 1 || k == 0) return;
if(numsSize==2&& numsSize%2!=0) {
    temp=nums[numsSize-2];
    nums[numsSize-2]=nums[numsSize-1];
    nums[numsSize-1]=temp;
    return;
}


while(k) {
i=0;
temp=nums[numsSize-2];
nums[numsSize-2]=nums[numsSize-1];
for(i=numsSize-3;i>=0;i--){
    t=nums[i];
    nums[i]=temp;
    temp=t;
}
nums[numsSize-1]=temp;
k--;
}
return;
}
int main () {
int arr[7] = {1,2,3,4,5,6,7};
int i,s=sizeof(arr)/sizeof(arr[0]);


rotate(arr,s,2);
for(i=0;i<s;i++) printf("%d ",arr[i]);
return 0;
}
