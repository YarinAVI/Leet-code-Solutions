

int findMaxConsecutiveOnes(int* nums, int numsSize){
    int res = INT_MIN;
    if(numsSize == 1 && nums[0] == 1) return 1;
    for(int i=0;i<numsSize;i++) {
        int counter = 0;
        if(nums[i] == 1){
            counter++;
        
        while(i<numsSize-1 && nums[i] == nums[i+1] && nums[i] == 1) counter++,i++;
        }
        if(counter > res) res = counter;
    }
    return res;
}