#include <stdio.h>
int search(int* nums, int numsSize, int target){
int l=0,r=numsSize-1;
int m = l + (r-l) /2;
while(l<=r) {
    if(nums[m]==target) return m;
    else if(nums[m]>target) r=m-1, m=l+(r-l) /2;
    else if(nums[m]<target) l=m+1, m=l+(r-l) /2;
}
return -1;
}


int main () {

    int arr[6] = {-1,0,3,5,9,12};
    printf("%d",search(arr,6,12));
}
