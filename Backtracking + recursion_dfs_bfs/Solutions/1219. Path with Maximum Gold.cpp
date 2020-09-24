#include <vector>
#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <stack>
using namespace std;
class Solution {
public:
    int dfs(vector<vector<int>> &grid, int i,int j) {
        if(i>=grid.size() || i<0 || j<0 || j>=grid[i].size() || grid[i][j]==0) return 0;
       int res = 0;
       int temp = grid[i][j];
        grid[i][j]=0;
        res = max(res,temp+dfs(grid,i+1,j));
        res = max(res,temp+dfs(grid,i-1,j));
        res = max(res,temp+dfs(grid,i,j+1));
        res = max(res,temp+dfs(grid,i,j-1));
        grid[i][j] = temp;
        return res;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        std::ios::sync_with_stdio(false);
        int res =  0;
        int max = res;
        int i,j;
        for(i=0;i<grid.size();i++) {
            for(j=0;j<grid[i].size();j++) {
                if(grid[i][j]!=0)  {
                    res = dfs(grid,i,j);
                if(res>max) max =res;
                }
            }
        }
        return max;
    }
};

int main () {
    vector<vector<int>> grid = {
        {1,0,7},
        {2,0,6},
        {3,4,5},
        {0,3,0},
        {9,0,20}
    };
    Solution s;
    s.getMaximumGold(grid);
}