int countNegatives(int** grid, int gridSize, int* gridColSize){
int res =0;
    for(int i =0;i<gridSize;i++) {
        if(grid[i][0]<0) {
            res+=*gridColSize;
            continue;
        }
        else if(grid[i][(*gridColSize)-1]>0) continue;
        else { // find left most minus
            int left =0, right = (*gridColSize)-1;
            int index = -1;
            while(left<=right) {
                int middle = (right-left)/2 + left;
                if(grid[i][middle]<0) index = middle, right = middle-1;
                else if(grid[i][middle]>=0) left = middle+1;
            }
            if(index!=-1) res += (*gridColSize)-index;
        }
    }
    return res;
}