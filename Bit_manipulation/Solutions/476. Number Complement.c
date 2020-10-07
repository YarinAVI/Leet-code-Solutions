int findComplement(int num){
        bool X[32] = {0};
    if(num==0) return 1;
    int i =0;
    int res =0;
    while(num) {
        X[i] = num & 1;
        i++;
        num = num >> 1;
    }
    for(int k=0;k<i;k++) {
        X[k] ^=1;
        if(X[k]) res += pow(2,k);
    } 
    return res;
}