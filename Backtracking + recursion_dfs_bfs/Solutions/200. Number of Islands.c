void dfs(char **grid,int gridSize,int gridColSize1,int i,int j) {
    if(i<0 || i>=gridSize || j>=gridColSize1 ||j<0 || grid[i][j]=='0') return;
    else {
        grid[i][j] = '0';
        dfs(grid,gridSize,gridColSize1,i+1,j);
        dfs(grid,gridSize,gridColSize1,i-1,j);
        dfs(grid,gridSize,gridColSize1,i,j-1);
        dfs(grid,gridSize,gridColSize1,i,j+1);
    }
    
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    int n=0,i,j;
    if(gridSize==0) return 0;
    int gridColSize1 =*gridColSize;
    for(i=0;i<gridSize;i++) {
        for(j=0;j<gridColSize1;j++) {
            if(grid[i][j]=='1') n++;
            dfs(grid,gridSize,gridColSize1,i,j);
        }
    }
    return n;
}