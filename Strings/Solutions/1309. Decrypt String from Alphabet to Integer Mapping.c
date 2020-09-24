char * freqAlphabets(char * s){
    int sS=strlen(s);
    char *res = (char*)calloc(sS,sizeof(char));
    int i =0;
    int k=0;
    int x;
    while(i<=sS-2) {
        if(s[i+2]=='\0') {
            res[k++] = s[i++] + 48;
            res[k++] = s[i++] + 48;
        }
        else if(s[i+2]!='#') {
            res[k++] = s[i++] + 48;
        }
        else {
        x=atoi(&s[i]);
        res[k++] = x+96;
        i+=3;
        }
    }
    if(i==sS-1) {
        res[k++] = s[i++] + 48;
    }
    return res;
}