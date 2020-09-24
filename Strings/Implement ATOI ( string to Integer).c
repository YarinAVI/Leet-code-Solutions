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
return 0;
}
int myAtoi(char * str){
int i=0,j=0,f; // string indexer and digits counter.
int res=0;
while(str[i]==32) i++; // ignore white-spaces
if((str[i]!=45 && str[i]!=43) && str[i]<48 || str[i]>57) return res;
else if(str[i]==45) {// minus case goes here

    do{
            if(str[i]>=49 && str[i]<=57) break;
     i++;
     if(str[i]=='\0'|| str[i]<48 || str[i]>57) return res;
    }
    while(str[i]==48); // check if zeros at begging of the number and dont mind them
    f=i;
    while(str[i]>=48 && str[i]<=57)i++,j++; // counting digits.
    if(j>10) return INT_MIN;
        else if (j==10) {
            i=f;
                        if(str[i]>50) return INT_MIN;
            else if(str[i]==50) res=convert_asci(str[i]) * pow(10,j-1);
            else goto B;
            i++,j--;
                        if(str[i]>49) return INT_MIN;
            else if(str[i]==49) res=res+convert_asci(str[i]) * pow(10,j-1);
            else goto B;
            i++,j--;
                        if(str[i]>52) return INT_MIN;
            else if(str[i]==52) res=res+convert_asci(str[i]) * pow(10,j-1);
            else goto B;
            i++,j--;
                        if(str[i]>55) return INT_MIN;
            else if(str[i]==55) res=res+convert_asci(str[i]) * pow(10,j-1);
            else goto B;
            i++,j--;
                        if(str[i]>52) return INT_MIN;
            else if(str[i]==52) res=res+convert_asci(str[i]) * pow(10,j-1);
            else goto B;
            i++,j--;
                        if(str[i]>56) return INT_MIN;
            else if(str[i]==56) res=res+convert_asci(str[i]) * pow(10,j-1);
            else goto B;
            i++,j--;
                        if(str[i]>51) return INT_MIN;
            else if(str[i]==51) res=res+convert_asci(str[i]) * pow(10,j-1);
            else goto B;
            i++,j--;
                        if(str[i]>54) return INT_MIN;
            else if(str[i]==54) res=res+convert_asci(str[i]) * pow(10,j-1);
            else goto B;
            i++,j--;
                        if(str[i]>52) return INT_MIN;
            else if(str[i]==52) res=res+convert_asci(str[i]) * pow(10,j-1);
            else goto B;
            i++,j--;
                        if(str[i]>56) return INT_MIN;
            else if(str[i]==56) res=res+convert_asci(str[i]) * pow(10,j-1);
            else goto B;
            return INT_MIN;

            do {
            j--;
            i++;
            B:
            res=res+convert_asci(str[i])*pow(10,j-1);
            }
            while(j>1);
            return res=-res;
    }
        else if(j<10) {
            i=f;
            do {
                res=res+convert_asci(str[i])*pow(10,j-1);
            j--;
            i++;
            }
            while(j>0);
            return res=-res;
    }
}
else  {// plus case goes here and zero case without plus at begging
    do{
        if(str[i]>=49 && str[i]<=57) break;
     i++;
     if(str[i]=='\0' || str[i]<48 || str[i]>57) return res;
    }
    while(str[i]==48); // check if zeros at begging of the number and dont mind them
    f=i;
    while(str[i]>=48 && str[i]<=57) {
        i++,j++; // counting digits.
    }
    if(j>10) return INT_MAX;
    else if (j==10) {
            i=f;
                        if(str[i]>50) return INT_MAX;
            else if(str[i]==50) res=convert_asci(str[i]) * pow(10,j-1);
            else goto A;
            i++,j--;
                        if(str[i]>49) return INT_MAX;
            else if(str[i]==49) res=res+convert_asci(str[i]) * pow(10,j-1);
            else goto A;
            i++,j--;
                        if(str[i]>52) return INT_MAX;
            else if(str[i]==52) res=res+convert_asci(str[i]) * pow(10,j-1);
            else goto A;
            i++,j--;
                        if(str[i]>55) return INT_MAX;
            else if(str[i]==55) res=res+convert_asci(str[i]) * pow(10,j-1);
            else goto A;
            i++,j--;
                        if(str[i]>52) return INT_MAX;
            else if(str[i]==52) res=res+convert_asci(str[i]) * pow(10,j-1);
            else goto A;
            i++,j--;
                        if(str[i]>56) return INT_MAX;
            else if(str[i]==56) res=res+convert_asci(str[i]) * pow(10,j-1);
            else goto A;
            i++,j--;
                        if(str[i]>51) return INT_MAX;
            else if(str[i]==51) res=res+convert_asci(str[i]) * pow(10,j-1);
            else goto A;
            i++,j--;
                        if(str[i]>54) return INT_MAX;
            else if(str[i]==54) res=res+convert_asci(str[i]) * pow(10,j-1);
            else goto A;
            i++,j--;
                        if(str[i]>52) return INT_MAX;
            else if(str[i]==52) res=res+convert_asci(str[i]) * pow(10,j-1);
            else goto A;
            i++,j--;
                        if(str[i]>55) return INT_MAX;
            else if(str[i]==55) res=res+convert_asci(str[i]) * pow(10,j-1);
            else goto A;
            return res;

            do {
            j--;
            i++;
             A:
            res=res+convert_asci(str[i])*pow(10,j-1);
            }
            while(j>1);
            return res;
    }
    else if(j<10) {
            i=f;
            do {
                res=res+convert_asci(str[i])*pow(10,j-1);
            j--;
            i++;
            }
            while(j>0);
            return res;
    }

}
return res;
}

int main () {
//char test[30]= "000002147483647";
//char test[30]= "+00192345";
char test[30]= "   -42";
printf("%d",myAtoi(test));


}
