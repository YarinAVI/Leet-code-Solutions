#include <stdio.h>
int addDigits(int num){
int a;
    while(num>9 || num<-9) {
      a=num%10;
      num=num/10;
      num=num+a;

    }
    return num;
}
int main () {

int number=38;
printf("%d",addDigits(number));




}
