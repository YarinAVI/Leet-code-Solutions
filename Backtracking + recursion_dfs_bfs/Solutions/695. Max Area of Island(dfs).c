int dfs(int **grid,int gridSize,int gridColSize,int i,int j) {
    if(i<0 || i>=gridSize || j<0 || j>=gridColSize || grid[i][j]!=1) return 0;
    grid[i][j] = 0;
    return (1 + dfs(grid,gridSize,gridColSize,i,j+1)+
               dfs(grid,gridSize,gridColSize,i,j-1)+
               dfs(grid,gridSize,gridColSize,i+1,j)+
               dfs(grid,gridSize,gridColSize,i-1,j));
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    if(gridSize==0) return 0;
    
int i=0,j=0;
    int max = INT_MIN;
    int x=0;
    for(i=0;i<gridSize;i++) {
        for(j=0;j<*gridColSize;j++) {
            if(grid[i][j]==1) {
                x = dfs(grid,gridSize,*gridColSize,i,j);
            }
            if(x>max) max=x;
        }
    }
    return max;
}