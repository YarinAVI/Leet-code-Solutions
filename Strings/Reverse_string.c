#include <stdio.h>

void reverseString(char* s, int sSize){
int i,j,t;

for(i=0,j=sSize-1;i<j;i++,j--) {
    t=s[j];
    s[j]=s[i];
    s[i]=t;
}
return;
}



int main () {
    char chars[14] = "this is a test";
    int i,s=sizeof(chars)/sizeof(chars[0]);
    reverseString(chars,s);
    for(i=0;i<s;i++) printf("%c ",chars[i]);
}
