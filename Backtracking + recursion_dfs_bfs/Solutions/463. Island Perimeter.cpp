class Solution {
public:
    int dfs(vector<vector<int>> &grid,int i,int j,int res) {
        if(i<0||i==grid.size() || j<0 ||j==grid[i].size() || grid[i][j]==0 || grid[i][j] ==-1) return 0;
        res=4;
        grid[i][j] = -1;
        if(i+1<grid.size()) {
            if(grid[i+1][j]==1 || grid[i+1][j]==-1) res--;
            res+=dfs(grid,i+1,j,res);
        }
        if(i-1>-1) {
            if(grid[i-1][j]==1 || grid[i-1][j]==-1) res--;
            res+=dfs(grid,i-1,j,res);
        }
        if(j+1<grid[i].size()) {
            if(grid[i][j+1]==1 || grid[i][j+1]==-1) res--;
            res+=dfs(grid,i,j+1,res);
        }
        if(j-1>-1) {
            if(grid[i][j-1]==1 || grid[i][j-1]==-1) res--;
            res+=dfs(grid,i,j-1,res);
        }
        return res;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int i,j;
        int res=0;
        for(i=0;i<grid.size();i++) {
            for(j=0;j<grid[i].size();j++) {
                if(grid[i][j]==1) {
                    res = dfs(grid,i,j,res);
                }
            }
        }
        return res;
    }
};