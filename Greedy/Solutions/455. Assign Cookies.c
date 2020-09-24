int compare (const void *a, const void *b) {
    return (*(int *)a-*(int*)b);
}
// s - cookies sizes
// g - greed factor of each child
int findContentChildren(int* g, int gSize, int* s, int sSize){
    int res=0,i,j;
    if(sSize==0 || gSize==0) return res;
    qsort(g,gSize,sizeof(int),compare);
    qsort(s,sSize,sizeof(int),compare);
    for(i=gSize-1,j=sSize-1;i>=0 && j>=0;i--) {
        if(s[j]>=g[i]) res++,j--;
    }
    return res;
}