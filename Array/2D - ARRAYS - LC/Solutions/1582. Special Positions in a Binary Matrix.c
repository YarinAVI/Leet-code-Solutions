int numSpecial(int** mat, int matSize, int* matColSize){
int i,j;
int k,c;
    int res = 0;
    bool flag1 = false;
    for(i=0;i<matSize;i++) {
        for(j=0,c=0,flag1=false;j<(*matColSize);j++) {
            if(mat[i][j] == 1) {
                c++;
                if(c>1) break;
                for(k=0;k<matSize;k++) {
                    if(mat[k][j] == 1 && k!=i) {
                        flag1 = true;
                        break;
                    }
                }
                if(flag1) break;
            }
        }
        if(!flag1 && c==1) res++;
    }
    return res;
}