#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>
int* plusOne(int* digits, int digitsSize, int* returnSize){
    unsigned long long int number=0,temp;
    int i=0,j=0;
    for(i=digitsSize-1;i>=0;i--,j++) {
        printf("%f\n",digits[j]*pow(10,i));
       number = number+(unsigned long long int)(digits[j]*pow(10,i)); // we must use here typecasing for the result of the digits[j]*pow(10,i) or else it wont work( very important to note this)
       printf("%llu\n",number);
    }
    //printf("%llu\n",number);
    number++,j=0;
    printf("\n%llu",number);
    temp=number;
    while(number>0) number/=10,j++;
    int * res= (int*)malloc(j*sizeof(int));
    *returnSize=j;
    j-=1;
    while(j>=0) res[j]=temp%10,j--,temp/=10;
    return res;
}
int main () {
int arr1[19] = {6,1,4,5,3,9,1,1,9,5,1,8,6,7,1,5,5,4,3};
int arr2[20] = {1,8,4,4,6,7,4,4,0,7,3,7,0,9,5,5,1,6,1,5}; /// 2^64 max value of unsigned long long
int s1 = sizeof(arr1)/sizeof(arr1[0]);
int s2=sizeof(arr2)/sizeof(arr2[0]);
int retsize=0,i;
int *res=plusOne(arr2,s2,&retsize);
for(i=0;i<retsize;i++) printf("%d ",*res++);
}
