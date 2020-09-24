uint32_t reverseBits(uint32_t n) {
    if(n==0) return 0;
    int res[32],i;
    int o=0;
    for(i=0;i<=31;i++) {
        if((n>>i)& 1) res[i]=1;
        else res[i]=0;
    }
    // building up the uint:
    for(i=0;i<32;i++) {
        if(res[i]==1) o=o+pow(2,31-i);
    }
    return o;
}