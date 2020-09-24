bool isMonotonic(int* A, int ASize){
    char de=0, inc=0, eq=0;
    int i,j;
    for(i=0,j=1;j<ASize;i++,j++) {
        if(A[i]==A[j]) eq=1;
        else if(A[j]>A[i]) inc=1;
        else if(A[j]<A[i]) de=1;
        if(de && inc) return false;
    }
    return true;
}