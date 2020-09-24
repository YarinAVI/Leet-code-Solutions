int to_string(int num,char **s) {
    int x = floor(log10(num))+1;
    if(num==0) x = 1;
    (*s) = (char*)realloc((*s),x*sizeof(char));
   if(num==0) {
      (**s) = '0';
       return x;
   } 
    
    int res = x;
    x = res-1;
    while(num) {
        (*s)[x] = (num%10)+'0';
        num/=10;
        x--;
    }
    return res;
}

char * getHint(char * secret, char * guess){
    int hs[10] = {0};
    int hg[10] = {0};
    int i,bulls=0,cows=0;
    
    for(i=0;secret[i];i++) hs[secret[i]-'0']++;
    for(i=0;guess[i];i++) hg[guess[i]-'0']++;
    for(i=0;secret[i];i++) {
        if(secret[i]==guess[i]) hs[guess[i]-'0']--,hg[guess[i]-'0']--,bulls++;
    }
    for(i=0;secret[i];i++) if(hg[secret[i]-'0']>0 && secret[i]!=guess[i]) hg[secret[i]-'0']--,cows++;
    char * res = NULL;
    char * num = NULL;
    int x = (to_string(bulls,&num)+1);
    res = (char*)malloc(x*sizeof(char));
    memcpy(res,num,x-1);
    res[x-1] = 'A';
    
    int g = (to_string(cows,&num)+1);
    
    res=(char*)realloc(res,(g+x+1)*sizeof(char));
    memcpy(&res[x],num,g-1);
    res[g+x-1]= 'B';
    res[g+x] = 0;
    return res;
}