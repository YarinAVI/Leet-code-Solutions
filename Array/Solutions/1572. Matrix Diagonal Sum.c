

int diagonalSum(int** mat, int matSize, int* matColSize){
    int i,j;
    int res =0;
    for(i=0;i<matSize;i++) res+=mat[i][i];
    for(i=matSize-1,j=0;i>=0;i--,j++) res+=mat[i][j];
    if(matSize%2!=0) res-=mat[matSize/2][matSize/2];
    return res;
}