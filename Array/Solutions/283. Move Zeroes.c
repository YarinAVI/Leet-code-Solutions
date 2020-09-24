
//https://leetcode.com/explore/featured/card/top-interview-questions-easy/92/array/567/
void moveZeroes(int* nums, int numsSize){
int i=0,j=1,t;
    while(j<=numsSize-1 && i<=numsSize-1) {
        while(nums[i]!=0 && i<numsSize-1)i++;
        while(nums[j]==0 && j<numsSize-1)j++;
        if(i>j) j=i+1;
            else t=nums[j],nums[j]=nums[i],nums[i]=t,i++,j++;
    }
}//[1,0,1]