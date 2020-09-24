int pivotIndex(int* nums, int numsSize){
    int i=0,s1=0,s2=0;
    for(i=0;i<numsSize;i++) s2+=nums[i];
    for(i=0;i<numsSize;i++) {
        s2-=nums[i];
        if(s1==s2) return i;
        s1+=nums[i];
        
    }
    return -1;
}