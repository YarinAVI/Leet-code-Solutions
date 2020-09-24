#include <stdio.h>
#include <limits.h>
#include <math.h>
int convert_asci(char a) {
switch(a) {
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
int myAtoi(char * str){
int i=0,j=0,f; // string indexer and digits counter.
int res=0,s=0;
if((str[i]!=45 && str[i]!=43) && str[i]<48 || str[i]>57) return res;
else if(str[i]==45) {// minus case goes here

    do{
     i++;
     if(str[i]='\0') return res;
    }
    while(str[i]==48); // check if zeros at begging of the number and dont mind them
    f=i;
    while(str[i]>=48 && str[i]<=57)i++,j++; // counting digits.
    if(j>10) return INT_MIN;
}
else  {// plus case goes here and zero case without plus at begging
    do{
     i++;
     if(str[i]='\0') return res;
    }
    while(str[i]==48); // check if zeros at begging of the number and dont mind them
    f=i;
    while(str[i]>=48 && str[i]<=57) { // need to debrief this
        i++,j++; // counting digits.
    }
    if(j>10) return INT_MAX;
    else if (j==10) {
            i=f;
            if(str[i]>50) return INT_MAX;
            else res=convert_asci(str[i]) * pow(10,j-1);
            do {
            j--;
            i++;
            res=res+convert_asci(str[i])*pow(10,j-1);
            }
            while(j>=0);
            return res;

    }
    else if(j<10) {
            i=f;
            do {
                res=res+convert_asci(str[i])*pow(10,j-1);
            j--;
            i++;
            }
            while(j>=0);
            return res;
    }

}

}

int main () {
char test[30]= "000002147483647";

printf("%d",myAtoi(test));


}
