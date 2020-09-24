

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void* b) {
    if(*(int*)a%2==0 && *(int*)b%2==0) return 0;
    else if(*(int*)a%2!=0 && *(int*)b%2==0) return 1;
    else return -1;
}
int* sortArrayByParity(int* A, int ASize, int* returnSize){
    *returnSize=ASize;
qsort(A,ASize,sizeof(int),cmp);
    return A;
}