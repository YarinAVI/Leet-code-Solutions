//https://leetcode.com/problems/search-a-2d-matrix-ii/
// this optimization is basically wont execute binary search in upper row / lower row / lower column / upper column based on the fact that if the first element is bigger than target there is no need to binary search and same for last element (if its smaller than target)
bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
     int rl=0, rh=matrixRowSize-1,cl=0,ch=matrixColSize-1;
    int m,rc=0,cc=0,f=1;
    // top row
    while(rl<=rh && cl <= ch) {
        if(matrix[rl][ch]==target || matrix[rl][cl]==target) return true;
            else if(matrix[rl][ch]<target || matrix[rl][cl]>target) f=0;
    while(cl<=ch && f) {
        m = cl + (ch-cl)/2;
        if(matrix[rl][m]==target) return true;
        else if(matrix[rl][m]>target) ch = m-1, m = cl +(ch-cl)/2;
        else if (matrix[rl][m]<target) cl = m+1, m = cl+(ch-cl)/2;
    }
        f=1;
    // lower row;
    cl=0+cc,ch=matrixColSize-1-cc; // remember we need to add a factor here
    if(matrix[rh][ch]==target || matrix[rh][cl]==target) return true;
        else if(matrix[rh][ch]<target || matrix[rh][cl]>target) f=0;
        
    while(cl<=ch && f) {
                m = cl + (ch-cl)/2;
        if(matrix[rh][m]==target) return true;
        else if(matrix[rh][m]>target) ch = m-1, m = cl +(ch-cl)/2;
        else if(matrix[rh][m]<target) cl = m+1, m = cl+(ch-cl)/2;
    }
    cl=0+cc,ch=matrixColSize-1-cc,f=1;
    // lower column
        if(matrix[rh][cl]==target || matrix[rl][cl]==target) return true;
            else if(matrix[rh][cl]<target || matrix[rl][cl]>target) f=0;
    while(rl<=rh && f) {
        m = rl + (rh-rl) /2;
        if(matrix[m][cl]==target) return true;
        else if(matrix[m][cl]>target) rh = m-1, m = rl + (rh-rl) /2;
        else if(matrix[m][cl]<target) rl = m+1, m = rl +(rh-rl) /2;
    }
    rl=0+rc,rh=matrixRowSize-1-rc,f=1;
    //upper column
        if(matrix[rh][ch]==target || matrix[rl][ch]==target) return true;
            else if(matrix[rh][ch]<target || matrix[rl][ch]>target) f=0;
    while(rl<=rh && f) {
        m = rl + (rh-rl) /2;
        if(matrix[m][ch]==target) return true;
        else if(matrix[m][ch]>target) rh = m-1, m = rl + (rh-rl) /2;
        else if(matrix[m][ch]<target) rl = m+1, m = rl +(rh-rl) /2;
    }
    cc++,rc++,f=1;
    rl=0+rc,rh=matrixRowSize-1-rc;
    cl=0+cc,ch=matrixColSize-1-cc;
    }
    return false;
}