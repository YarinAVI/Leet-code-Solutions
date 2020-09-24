#include <stdio.h>
int strStr(char * haystack, char * needle){
    if(!*needle) return 0;
    int i=0,j=0,b;
    while(haystack[i]!='\0') {
    if(haystack[i]!=needle[j])i++;
    A:
    b=i;
    while(haystack[i]==needle[j]) {
        i++,j++;
        if(needle[j]=='\0') return b;
        else if (haystack[i]=='\0') return -1;
        if(haystack[i]!=needle[j]) {
          j=0,i=b+1;
          goto A;
        }

    }
    }
    return -1;
}

int main () {
    char haystack[38]= "mississippi";
    char needle[10] = "issipi";
   // printf("%d \n",sizeof(test)/sizeof(test[0]));
    printf("%d",strStr(haystack,needle));
}
