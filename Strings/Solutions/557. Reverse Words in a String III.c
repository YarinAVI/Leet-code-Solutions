void reverse(char *s,int end) {
    char temp;
    int i =0;
    while(i<end) {
        temp = s[i];
        s[i] = s[end];
        s[end] = temp;
        i++,end--;
    }
}
char * reverseWords(char * s){
    int i=0;
    while(s[i]==' ')i++;
    int j=i;
    int size = strlen(s);
    while(j<size) {
    
        while(s[j]!=' ' && j<size) j++;
        reverse(&s[i],j-i-1);
        j++,i=j;
    }
    return s;
}