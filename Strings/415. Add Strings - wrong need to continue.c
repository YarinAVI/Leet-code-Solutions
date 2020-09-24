#include <stdio.h>
// https://leetcode.com/problems/add-strings/ - need to continue this is wrong solution ( understood wrongly )
int convert(char a) {
    switch(a) {
    case 48:
        return 0;
        break;
        case 49:
            return 1;
            break;
                    case 50:
            return 2;
            break;
                    case 51:
            return 3;
            break;
                    case 52:
            return 4;
            break;
                    case 53:
            return 5;
            break;
                    case 54:
            return 6;
            break;
                    case 55:
            return 7;
            break;
                    case 56:
            return 8;
            break;
                    case 57:
            return 9;
            break;
    }
}
int convert2(char a) {
    switch(a) {
    case 0:
            return 48;
            break;
        case 1:
            return 49;
            break;
                    case 2:
            return 50;
            break;
                    case 3:
            return 51;
            break;
                    case 4:
            return 52;
            break;
                    case 5:
            return 53;
            break;
                    case 6:
            return 54;
            break;
                    case 7:
            return 55;
            break;
                    case 8:
            return 56;
            break;
                    case 9:
            return 57;
            break;
    }
}

char * addStrings(char * num1, char * num2){
int a,i,j;
static char result[6] = "000000";
    while(*num1!='\0') a=a+convert(*num1), num1++;
    while(*num2!='\0') a=a+convert(*num2),num2++;
for(i=0;a!=0;i++,a=a/10) result[i]=a%10;
for(i=0,j=5;i<j;i++,j--) a=convert2(result[i]),result[i]=convert2(result[j]),result[j]=a;
return result;
}
int main () {
char s[5] = "45";
char b[5] = "459";

printf("%s",addStrings(s,b));
}
