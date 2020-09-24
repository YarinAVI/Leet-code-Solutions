#include <stdio.h>
int majorityElement(int* nums, int numsSize){
    int i,j,c=1,k=0,s=0;
    int seen_numbers[numsSize];
    for(i=0;i<numsSize;i++) seen_numbers[i]=-307;
    for(i=0;i<numsSize;i++) {
        for(k=0;nums[i]==seen_numbers[k] &&seen_numbers[k]!=-307;k++,i++);
        seen_numbers[s++]=nums[i];
        for(j=i+1;j<numsSize;j++) {
            if(nums[i]==nums[j]) c++;
        }
        if(c>(numsSize/2)) return nums[i];
        else c=1;
    }
    return -1;
}




int main () {

int arr[5]= {8,8,7,7,7};

printf("%d",majorityElement(arr,5));


}
