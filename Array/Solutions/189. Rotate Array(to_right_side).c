#include <stdio.h>
void rotate(int* nums, int numsSize, int k){
int i,temp,t;
if (numsSize <= 1 || k == 0) return;
if(numsSize==2&& numsSize%2!=0) {
    temp=nums[1];
    nums[1]=nums[0];
    nums[0]=temp;
    return;
}


while(k) {
i=0;
temp=nums[i+1];
nums[i+1]=nums[i];
for(i=2;i<numsSize;i++){
    t=nums[i];
    nums[i]=temp;
    temp=t;
}
nums[0]=temp;
k--;
}
return;
}
int main () {
int arr[5] = {1,2,3,4,5};
int i,s=sizeof(arr)/sizeof(arr[0]);


rotate(arr,s,491541840);
for(i=0;i<s;i++) printf("%d ",arr[i]);
return 0;
}
