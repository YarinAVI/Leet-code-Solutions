//https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/
// very good question to practice 2d arrays (matrix)!!
int oddCells(int n, int m, int** indices, int indicesSize, int* indicesColSize){
    int mat[n][m];
    int i,j;
    int c_odd=0;
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            mat[i][j]=0;
        }
    }
    for(i=0;i<indicesSize;i++) {
        for(j=0;j<n;j++) {
        mat[j][indices[i][1]]++;
    }
        for(j=0;j<m;j++) {
            mat[indices[i][0]][j]++;
        }
    }
        for(i=0;i<n;i++){ 
            for(j=0;j<m;j++) {
                if(mat[i][j]%2!=0) c_odd++;
                //printf("%d ",mat[i][j]);
            }
            //printf("\n");
        }
    return c_odd;
}
