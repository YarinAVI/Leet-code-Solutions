

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize){
    int max = INT_MIN;
    *returnSize=candiesSize;
    char *res =(char*)calloc(candiesSize,sizeof(int));
    int i=0;
    for(i=0;i<candiesSize;i++) {
        if(candies[i]>max) max=candies[i];
    }
   // printf("%d",max);
    for(i=0;i<candiesSize;i++) {
        printf("%d ",candies[i]+extraCandies);
        if((candies[i]+extraCandies)>=max) {
            res[i]=true;
        }
        
        else res[i]=false;
    }
    return res;
}