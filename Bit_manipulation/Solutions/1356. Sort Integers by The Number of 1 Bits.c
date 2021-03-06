

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void *a,const void *b) {
    size_t x = __builtin_popcount((*(int*)a));
    size_t y = __builtin_popcount(*(int*)b);
    if(x==y) return (*(int*)a) - (*(int*)b);
    else if(x>y) return 1;
    else return -1;
}
int* sortByBits(int* arr, int arrSize, int* returnSize){
    (*returnSize) = arrSize;
    qsort(arr,arrSize,sizeof(int),cmp);
    return arr;
}