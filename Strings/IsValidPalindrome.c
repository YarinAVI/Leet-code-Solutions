#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
bool isPalindrome(char * s){
    int r=0,l=0,e;
    while(s[r]!='\0') s[r]=tolower(s[r]),r++;
    e=r-1;
    printf("%d \n",e);
    //if(e==2) return true;
    r--;
    while(r>0 && l <e) {
        while( (s[r]>57 || s[r]<48)  &&s[r]<97 || s[r]>122) {
            r--;
            if(r==0) break;
        }
        printf("%d ",r);
        while( (s[l]>57 || s[l]<48)  && s[l]<97 || s[l]>122) {
            l++;
            if(l==e) break;
        }
        if(l==e || r == 0 ) break;
        if(s[l]!=s[r]) return false;
        r--,l++;
    }
    return true;
}


int main () {

char s[50] = "A man, a plan, a canal: Panama";

printf("\n%d",isPalindrome(s));
}
