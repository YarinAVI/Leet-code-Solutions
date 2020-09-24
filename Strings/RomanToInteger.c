#include <stdio.h>
int convert (char c) {
switch(c) {
    case 'I':
    return 1;
    case 'V':
    return 5;
    case 'X':
    return 10;
    case 'L':
    return 50;
    case 'C':
    return 100;
    case 'D':
    return 500;
    case 'M':
    return 1000;
}
    return -1;
}
int romanToInt(char * s){
    int res=0;
    while(*s!='\0') {
        if(*s=='I') {
            if(*(s+1)=='V' || *(s+1)=='X') res=res+ (convert(*(s+1))- convert(*s)),s++;
            else res=res+convert(*s);
        }
        else if(*s=='X') {
            if(*(s+1)=='L' || *(s+1)=='C') res=res+ (convert(*(s+1))-convert(*s)),s++;
            else res=res+convert(*s);
        }
        else if(*s=='C') {
            if(*(s+1)=='D' || *(s+1)=='M') res=res+(convert(*(s+1))-convert(*s)),s++;
            else res=res+convert(*s);
        }

        else res=res+convert(*s);

        s++;
    }
    return res;
}
int main() {

char roman[12] = "MMMDCCXXIV";

printf("%d",romanToInt(&roman));

}
