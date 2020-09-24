

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* A, int ASize, int* returnSize){
    int *res=(int*)malloc(ASize * sizeof(int));
    *returnSize=ASize;
    int i=0,j=ASize-1,k=ASize-1;
    while(i<=j) {
            if(A[j]>=abs(A[i])) res[k--]=pow(A[j--],2);
            else res[k--]=pow(A[i++],2);
    }
    return res;
}