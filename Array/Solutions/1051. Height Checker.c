int cmp(const void *a,const void *b) {
    return (*(int*)a-*(int*)b);
}

int heightChecker(int* heights, int heightsSize){
    int *temp = (int*)malloc(heightsSize*sizeof(int));
    int i;
    int res=0;
    for(i=0;i<heightsSize;i++) temp[i]=heights[i];
    qsort(heights,heightsSize,sizeof(int),cmp);
    for(i=0;i<heightsSize;i++) {
        if(heights[i]!=temp[i]) res++;
    }
    free(temp);
    return res;
}