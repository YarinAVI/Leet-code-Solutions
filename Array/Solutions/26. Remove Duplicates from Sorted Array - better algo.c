#include <stdio.h>
int removeduplicates(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    int i = 0;
    for (int j = 1; j < numsSize; j++) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1;
}

int main () {
               //0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
 int nums[16] = {1,2,3,3,3,3,3,5,6,8,8,  9, 9,10,15,20};
 int numsSize = sizeof(nums)/sizeof(nums[0]);
 int i;
printf("New Size is :%d ",numsSize=removeduplicates(nums,numsSize));
printf("New array is:\n");
for(i=0;i<numsSize;i++) printf("%d ",nums[i]);
}