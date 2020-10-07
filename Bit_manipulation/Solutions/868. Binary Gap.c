int binaryGap(int N){
    int res = 0;
    if(!N) return res;
    bool n[32] = {0};
    for(int i=0;i<32;i++) n[i] = (N >> i) & 1;
    for(int i=0;i<32;i++) {
        if(n[i]) {
            int j;
            for(j=i+1;j<32;j++) {
                if(n[j]) {
                    if((j-i) > res) res = j-i;
                    break;
                }
        }
    }
    }
    return res;
}