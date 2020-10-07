int bitwiseComplement(int N){
    bool X[32] = {0};
    if(N==0) return 1;
    int i =0;
    int res =0;
    while(N) {
        X[i] = N & 1;
        i++;
        N = N >> 1;
    }
    for(int k=0;k<i;k++) {
        X[k] ^=1;
        if(X[k]) res += pow(2,k);
    } 
    return res;
}