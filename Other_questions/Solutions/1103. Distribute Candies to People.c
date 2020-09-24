

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* distributeCandies(int candies, int num_people, int* returnSize){
    *returnSize = num_people;
    int i,k;
    int *res = (int*)calloc(num_people,sizeof(int));
    for(i=0,k=1;(candies-k)>0;candies-=k++,i++,i%=num_people) {
        res[i] += k;
    }
    
    if(candies >0) res[i] += candies;
    
    return res;
}