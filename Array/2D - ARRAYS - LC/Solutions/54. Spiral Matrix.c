#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>

/*int matrix[3][4] = {
    {1,2,3,4} ,
    {5,6,7,8},
    {9,10,11,12},
};
*/
int matrix[3][1] = {
    {1},
    {2},
    {3},
};
/*int matrix[2][3] = {
    {2,5,8},
    {4,0,-1},
};*/

/*int matrix[5][3] = {
    {2, 5, 8 },
    {4, 0, -1 },
    {4, 0, 1 },
    {4, 0, -1 },
    {4, 0, 1 },
};*/
int* spiralOrder(int matrixSize, int* matrixColSize, int* returnSize) {
    int msize = matrixSize * (*matrixColSize);
    *returnSize = msize;
    int* res = (int*)malloc(msize * sizeof(int));
    int k = 0;
    int hc_ptr = (*matrixColSize) - 1;

    int lc_ptr = 0;
    int hr_ptr = matrixSize - 1;
    int lr_ptr = 0;
    int i, j, f = 0;
    if (*matrixColSize == 1) {
        for (i = 0; i < matrixSize; i++, k++) res[k] = matrix[i][0];
    }
    while (1) {
        // copy upper row
        for (i = lr_ptr, j = lc_ptr; j <= hc_ptr && k < msize; j++, k++) res[k] = matrix[i][j];
        // copy right column
        //if (k > msize - 1) return res;

        for (i = lr_ptr + 1, j = hc_ptr; i < hr_ptr && k<msize; i++, k++) res[k] = matrix[i][j];
        // copy lower row
        for (i = hr_ptr, j = hc_ptr; j > lc_ptr && k < msize; j--, k++) res[k] = matrix[i][j];
        // copy left column
        for (i = hr_ptr, j = lc_ptr; i > lr_ptr && k < msize; i--, k++) res[k] = matrix[i][j];

        //if (k > msize - 1) return res;
        f++, lr_ptr++, hr_ptr--, hc_ptr--, lc_ptr++;
        if (k == msize) return res;
    }
}
int main() {
    int returnSize = 0;
    int matrixColSize = 1;
    int matrixSize = 3;
    int* res = spiralOrder(matrixSize, &matrixColSize, &returnSize);
    int i;
    for (i = 0; i < returnSize; i++) printf("%d ", res[i]);
}