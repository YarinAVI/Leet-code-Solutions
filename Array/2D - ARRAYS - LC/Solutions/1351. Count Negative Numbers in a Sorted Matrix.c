int countNegatives(int** grid, int gridSize, int* gridColSize){
    int rptr=0, cl_ptr=0,ch_ptr=*gridColSize-1;
    int minus_c=0;
    while(rptr<gridSize) {
        while(cl_ptr<=ch_ptr) {
            
            if(grid[rptr][ch_ptr]>=0) break;
            else if(grid[rptr][cl_ptr]<0) {
                minus_c+=*gridColSize-cl_ptr;
                break;
            }
            cl_ptr++;
        }
        cl_ptr=0;
        rptr++;
    }
    return minus_c;
}