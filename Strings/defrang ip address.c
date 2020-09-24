#include <stdio.h>
char * defangIPaddr(char * address){
static char result[22];
int i=0;
while(*address!='\0') {
        do {
         result[i]=*address;
         i++,address++;
        }
        while(*address!=46 && *address!='\0');
        if(*address=='\0') {
            result[i]='\0';
            return result;
        }
        result[i]='[',i++;
        result[i]='.',i++;
        result[i]=']',i++;
        address++;

}
return result;
}
int main() {
char ip[20] = "151.230.31.91";
printf("%s",defangIPaddr(ip));

}
