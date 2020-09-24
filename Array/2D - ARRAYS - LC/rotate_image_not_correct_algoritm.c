#include <stdio.h>
//for(i=0;i<matrixSize;i++) printf("%d ",b[i]);
int matrix[4][4] = {
{5,1,9,11},
{2,4,8,10},
{13,3,6,7},
{15,14,12,16},
};
void rotate(int matrixSize){
int i,t,f,j,g=0,s=matrixSize-1;
int b[matrixSize];
//while(g>=0) {
for(i=matrixSize-1-g,f=0,j=0;j<matrixSize;j++,f++) b[f]=matrix[j][i];//backup the column
for(i=0,j=s,f=0;f<matrixSize-1;i++,f++) matrix[i][j]=matrix[g][f];//copying row to column
matrix[i][j]=b[0];
// now swap B(in Reversed) with the row in S position
//after that we place B on Row in G location and then we repeat the process
for(i=s,j=matrixSize-1,f=0;j>=0;f++,j--) {
     t=matrix[i][f];
     matrix[i][f]=b[j];
     b[j]=t; // after this we need to reverse B since we swaped it in reverse order
}
for(i=0,j=matrixSize-1;i<j;i++,j--){

}





for(i=0;i<matrixSize;i++) {
    for(j=0;j<matrixSize;j++) {
        printf("%d ",matrix[i][j]);
    }
    printf("\n");
}
for(i=0;i<matrixSize;i++) printf("\n%d ",b[i]);
//for(i=0;i<matrixSize;i++) printf("%d",matrix[i][3]);
//}
}
int main () {
int matrixSize=sizeof(matrix)/sizeof(matrix[0]);
// columnSize=rowSize in this problem

rotate(matrixSize); // we dont need matrixColSize since columnSize= RowsSize!
}
