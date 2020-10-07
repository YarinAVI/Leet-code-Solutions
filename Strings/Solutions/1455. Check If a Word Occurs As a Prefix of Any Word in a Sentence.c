bool check(char *a,char *b) {
    while((*b) && (*a)) {
        if((*b)!=(*a)) return false;
        b++,a++;
    }
    if((*b)) return false;
    else return true;
}

int isPrefixOfWord(char * sentence, char * searchWord){
int res = 1;
    int i=0,s_size = strlen(sentence);
    while(i<s_size) {
        if(check(&sentence[i],searchWord)) return res;
        while(sentence[i]!=' ' && i<s_size) i++;
        i++,res++;
    }
    return -1;
}