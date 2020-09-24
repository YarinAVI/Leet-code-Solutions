

char * toLowerCase(char * str){
    int i;
    for(i=0;str[i];i++) {
        if(str[i]>=65 && str[i]<=90) str[i]+=32;
    }
    return str;
}