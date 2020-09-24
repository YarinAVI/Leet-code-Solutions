int cmp (const void *a,const void *b) {
    return (*(int*)a-*(int*)b);
}
int findPairs(int* nums, int numsSize, int k){
    //if(numsSize==0) return 0;
qsort(nums,numsSize,sizeof(int),cmp);
    int i=0,j=1,counter=0;
    if(k!=0) {
    while(j<numsSize) {
        if(nums[j]==nums[i]) i++,j++; // if dups then continue because we care only about 1 instance of that number
        // now start checking pairs
        else { 
            while(j<numsSize) {
                if(nums[j]!=nums[j-1]) {
                    if(nums[j]-nums[i]==k) counter++;
                }
                j++;
            }
            i++,j=i+1;
        }
    }
    }
    else {
        while(j<numsSize) {
            if(nums[i]==nums[j]) {
                counter++;
                while(j<numsSize && nums[i]==nums[j]) i++,j++;
            }
            else i++,j++;
        }
    }
    return counter;
}