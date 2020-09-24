#include <stdio.h>
#include <stdbool.h>
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/110/sorting-and-searching/806/
// search in 2d array where the rows are sorted and the columns are sorted
/*int matrix[5][5] = {
  {1,   4,  7, 11, 15},
  {2,   5,  8, 12, 19},
  {3,   6,  9, 16, 22},
  {10, 13, 14, 17, 24},
  {18, 21, 23, 26, 30},


};*/

/*int matrix [1][1] = {
{-5},
};*/

/*int matrix[1][3] = {
    {1,3,5},
};*/




bool searchMatrix(int **matrix,int matrixRowSize, int matrixColSize, int target) {
     int rl=0, rh=matrixRowSize-1,cl=0,ch=matrixColSize-1;
    int m,rc=0,cc=0;
    // top row
    while(rl<=rh && cl <= ch) {
    while(cl<=ch) {
        m = cl + (ch-cl)/2;
        if(matrix[rl][m]==target) return true;
        else if(matrix[rl][m]>target) ch = m-1, m = cl +(ch-cl)/2;
        else if (matrix[rl][m]<target) cl = m+1, m = cl+(ch-cl)/2;
    }
    // lower row;
    cl=0+cc,ch=matrixColSize-1-cc; // remember we need to add a factor here
    while(cl<=ch) {
                m = cl + (ch-cl)/2;
        if(matrix[rh][m]==target) return true;
        else if(matrix[rh][m]>target) ch = m-1, m = cl +(ch-cl)/2;
        else if(matrix[rh][m]<target) cl = m+1, m = cl+(ch-cl)/2;
    }
    cl=0+cc,ch=matrixColSize-1-cc;
    // lower column
    while(rl<=rh) {
        m = rl + (rh-rl) /2;
        if(matrix[m][cl]==target) return true;
        else if(matrix[m][cl]>target) rh = m-1, m = rl + (rh-rl) /2;
        else if(matrix[m][cl]<target) rl = m+1, m = rl +(rh-rl) /2;
    }
    rl=0+rc,rh=matrixRowSize-1-rc;
    //upper column
    while(rl<=rh) {
        m = rl + (rh-rl) /2;
        if(matrix[m][ch]==target) return true;
        else if(matrix[m][ch]>target) rh = m-1, m = rl + (rh-rl) /2;
        else if(matrix[m][ch]<target) rl = m+1, m = rl +(rh-rl) /2;
    }
    cc++,rc++;
    rl=0+rc,rh=matrixRowSize-1-rc;
    cl=0+cc,ch=matrixColSize-1-cc;
    }
    return false;
}

int main () {

int matrix[5][5] = {
  {1,   4,  7, 11, 15},
  {2,   5,  8, 12, 19},
  {3,   6,  9, 16, 22},
  {10, 13, 14, 17, 24},
  {18, 21, 23, 26, 30},
};

int **matrixptr = matrix;
printf("%d",searchMatrix(matrixptr,5,5,0));


}
