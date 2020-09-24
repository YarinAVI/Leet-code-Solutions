int cmp(const void *a,const void *b) {
    return (*(int*)a-*(int*)b);
}

bool uniqueOccurrences(int* arr, int arrSize){
    int h[2001] = {0};
    int i;
    for(i=0;i<arrSize;i++) {
        h[arr[i]+1000]++;
    }
    qsort(h,2001,sizeof(int),cmp);
    for(i=0;i<2000;i++) {
        if(h[i]==h[i+1] && h[i]!=0 && h[i+1]!=0) return false;
    }
    return true;
}
