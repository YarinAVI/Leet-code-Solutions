#include <stdio.h>
int numJewelsInStones(char * J, char * S){
int res=0,i,j;
    for(i=0;J[i]!='\0';i++) {
        for(j=0;S[j]!='\0';j++) {
            if(J[i]==S[j]) res++;
        }
    }
return res;
}






int main () {
char j[3]="aA";
char s[8]="aAAbbAa";
printf("%d",numJewelsInStones(j,s));

}