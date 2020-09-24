#include <stdio.h>
// by yarin Avisidris, leet code problem rotate matrix 90 degree
/*int matrix[8][8] = {
  {5,3,2,5,1,3,2,5},
  {4,3,4,1,2,3,4,1},
  {2,6,8,9,3,6,8,9},
  {6,7,0,3,4,7,0,1},
  {5,3,2,5,5,3,2,5},
  {4,3,4,1,4,3,4,1},
  {2,6,8,9,2,6,8,9},
  {6,7,0,1,6,7,1,1},

};*/
/*int matrix[3][3] = {
{1,2,3},
{4,5,6},
{7,8,9},
};*/
/*int matrix[4][4] = {
{1,2,3,4},
{5,6,7,8},
{9,1,2,3},
{4,5,6,7},
};
/*int matrix[5][5] = {
{1,2,3,4,5},
{5,6,7,8,6},
{9,1,2,3,7},
{4,5,6,7,8},
{1,2,3,4,5},
};*/
int matrix[2][2] = {
{1,2},
{3,4},
};
//rotating symmetrical matrix, even and odd.
void rotate(int matrixSize, int* matrixColSize){
int rotor[matrixSize-2];
int t,f,i,j; // we gonna use is_odd later
int chp=matrixSize-1,rlp=0; // column pointer high, row pointer low.
int clp=0,rhp = matrixSize-1; // Column pointer low, row pointer high.
// by the "spider Algorithm" we first solve the rotation for the edges of the matrix, and reduce the rows and columns by two recursively
// CHP decrease,RLP increase,CLP increase,RHP Decrease!
//Start by Solving Edges(4 Numbers)
while(chp>=clp) {
t=matrix[rlp][chp];
matrix[rlp][chp]=matrix[rhp][chp];
matrix[rhp][chp]=t;
t=matrix[rlp][chp];//
matrix[rlp][chp]=matrix[rhp][clp];
matrix[rhp][clp]=t;
t=matrix[rlp][clp];
matrix[rlp][rlp]=matrix[rlp][rhp];
matrix[rlp][rhp]=t;
// after all these lines, edges has been solved and the next time we gonna solve the edges of smaller matrix.
// now the fun begins :)

for(i=rlp,f=0,j=clp+1;j<chp;j++,f++) rotor[f]=matrix[i][j];// here we backup the first row rotor,remember CLP goes up, CHP goes down!
// now swap procedure starts
for(i=rhp-1,f=clp+1,j=clp;i>rlp;i--,f++)  matrix[rlp][f]=matrix[i][j];

for(i=rlp+1,f=0,j=chp;i<rhp;i++,f++) {
    t=rotor[f];
    rotor[f]=matrix[i][j];
    matrix[i][j]=t;
}
for(i=chp-1,j=rhp,f=0;i>clp;i--,f++) {
    t=rotor[f];
    rotor[f]=matrix[j][i];
    matrix[j][i]=t;
}

for(i=rhp-1,j=clp,f=0;i>rlp;i--,f++) {
    matrix[i][j]=rotor[f];
}
chp--,clp++,rlp++,rhp--; // its very important to note this line, each pointer has important job in this solution
}
for(i=0;i<matrixSize;i++) {
    for(j=0;j<matrixSize;j++) {
        printf("%d ",matrix[i][j]);
    }
    printf("\n");
}
}



int main () {

int matrixSize=sizeof(matrix)/sizeof(matrix[0]);
// matrixColSize equals to MatrixSize since the matrix is Symmetric - important note
rotate(matrixSize,matrixSize); //
}
