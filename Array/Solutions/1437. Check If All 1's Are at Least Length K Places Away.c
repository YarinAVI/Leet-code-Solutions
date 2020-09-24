bool kLengthApart(int* nums, int numsSize, int k){
    int i=0,j;
    if(numsSize==1) return true;
    while(nums[i]==0) {
        i++;
        if(i==numsSize) return true;
    }
    while(1) {
        j=i+1;
        while(nums[j]==0) {
            j++;
            if(j==numsSize) return true;
        }
        if(((j-1) - i) <k) return false;
        i=j;
        if(i==numsSize-1) return true;
    }
    return 0;
}