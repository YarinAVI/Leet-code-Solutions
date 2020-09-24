

char findTheDifference(char * s, char * t){
    char hs[26] = {0};
    char ht[26] = {0};
    int i;
    for(i=0;s[i];i++) hs[s[i]-97]++;
    for(i=0;t[i];i++)ht[t[i]-97]++;
    
    for(i=0;i<26;i++)  {
        ht[i] -=hs[i];
        if(ht[i]==1) return i+97;
    }
    return ' ';
}