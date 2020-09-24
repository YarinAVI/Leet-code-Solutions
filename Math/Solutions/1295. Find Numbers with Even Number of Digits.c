

int findNumbers(int* nums, int numsSize){
int i,res=0;
    for(i=0;i<numsSize;i++) {
        int x = floor(log10(nums[i]))+1;
        if(x%2==0) res++;
    }
    return res;
}