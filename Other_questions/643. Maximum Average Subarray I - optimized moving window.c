#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
//https://leetcode.com/problems/maximum-average-subarray-i/
// this algorithm is the moving window but OPTIMIZED ( we add the next value to the sum and remove the 1 before the last from the sum and because of that we dont need to calculate the whole window every iteration)

double findMaxAverage(int* nums, int numsSize, int k){
double avg=INT_MIN,aux=0;
    int i,r=0;
    for(i=0;i<k;i++) aux+=nums[i];
    if(aux>avg) avg=aux;
    //aux=0;
    for(i=0;i+k<=numsSize-1;i++,r++) {
        aux=aux+nums[i+k] - nums[r];
        if(aux>avg)avg=aux;
    }
    return avg/k;
}

int main () {
int arr[6] = {0,1,1,3,3};
printf("\n%lf ",findMaxAverage(arr,5,4));
}

/// test cases::
///https://leetcode.com/submissions/detail/353540022/testcase/
///https://leetcode.com/submissions/detail/353545256/testcase/
