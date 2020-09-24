void sortColors(int* nums, int numsSize){
int red=0,white=0,blue=0;
    int i;
    for(i=0;i<numsSize;i++) {
        switch (nums[i])
        {
        case 0:
            red++;
        break;
        case 1:
            white++;
        break;
        case 2:
            blue++;
        break;    
        }
    }
    i=0;
    while(red) nums[i++]=0,red--;
    while(white) nums[i++]=1,white--;
    while(blue) nums[i++]=2,blue--;
    return;
}