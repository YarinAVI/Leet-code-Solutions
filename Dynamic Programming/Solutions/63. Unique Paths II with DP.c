
int dfs(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize,int i,int j) {
    //printf("%d %d\n",i,j);
    if(i==obstacleGridSize-1 && j == (*obstacleGridColSize)-1) return 1;
    if(obstacleGrid[i][j]>0) return obstacleGrid[i][j];
    if((j+1)<(*obstacleGridColSize) && obstacleGrid[i][j+1]!=-1) 
        obstacleGrid[i][j]+=dfs(obstacleGrid,obstacleGridSize,obstacleGridColSize,i,j+1);
    if((i+1)<obstacleGridSize && obstacleGrid[i+1][j]!=-1)
        obstacleGrid[i][j]+=dfs(obstacleGrid,obstacleGridSize,obstacleGridColSize,i+1,j);
    
    return obstacleGrid[i][j];
}
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
    if(obstacleGrid[obstacleGridSize-1][(*obstacleGridColSize)-1] || obstacleGrid[0][0]) return 0;
    for(int i=0;i<obstacleGridSize;i++) {
        for(int j=0;j<(*obstacleGridColSize);j++) {
            if(obstacleGrid[i][j]==1) obstacleGrid[i][j] =-1;
        }
    }
    

    return dfs(obstacleGrid,obstacleGridSize,obstacleGridColSize,0,0);
}

