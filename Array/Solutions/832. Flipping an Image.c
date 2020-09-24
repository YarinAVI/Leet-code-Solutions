
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** flipAndInvertImage(int** A, int ASize, int* AColSize, int* returnSize, int** returnColumnSizes){
    int i,j,k;
    int temp;
    *returnSize = ASize;
    for(i=0;i<ASize;i++) {
        for(j=0,k=*AColSize-1;j<k;j++,k--) {
            temp =A[i][j];
            A[i][j] = A[i][k];
            A[i][k] = temp;
        }
    }
    for(i=0;i<ASize;i++) {
        for(j=0;j<*AColSize;j++,k--) {
            A[i][j] = !A[i][j];
        }
    }
    *returnColumnSizes = AColSize;
    return A;
}