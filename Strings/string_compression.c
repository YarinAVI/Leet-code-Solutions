#include <stdio.h>
void convert_asci(char* chars,int a,int b) {
    int i;
    for(i=a;i<=b;i++) {
        switch(chars[i])
        {
        case 0:
            chars[i]=48;
            break;
        case 1:
            chars[i]=49;
            break;
        case 2:
            chars[i]=50;
            break;
        case 3:
            chars[i]=51;
            break;
        case 4:
            chars[i]=52;
            break;
        case 5:
            chars[i]=53;
            break;
        case 6:
            chars[i]=54;
            break;
        case 7:
            chars[i]=55;
            break;
        case 8:
            chars[i]=56;
            break;
        case 9:
            chars[i]=57;
            break;
        }
    }
}
void reverse(char* chars,int a, int b) {
char *x=&chars[a],*y=&chars[b];
// thx sergey for the xor swap <3
while(x<y) {
    *x^=*y;
    *y^=*x;
    *x^=*y;
    x++,y--;

}
convert_asci(chars,a,b);


}
int compress(char* chars, int charsSize){
if(charsSize==1) return 1;
else if(charsSize==2 && chars[0]==chars[1])
{
    chars[1]=50;
     return 2;
}
int j=1,i=0,c,f=0,g,k=0,b=0;
while(j<=charsSize-1) {
    c=1,g=0,b=0;
while(chars[j]!=chars[i]) {
    if(j<charsSize-1) i++,j++;
    else return j+1;
}
while(chars[j]==chars[i]) {
    c++;
    if(j<charsSize-1) j++;
    else break;
}
if(c>1 && c<10) {
    f=i+2,i++;
    chars[i]=c,convert_asci(chars,i,i);
    if(i==charsSize-1) return charsSize;
    i=f;
    chars[i]=chars[j];
    while(j<charsSize-1) chars[++i]=chars[++j];
    i=f,j=f+1,charsSize-=(c-2);
}
else if(c>9) {
    f=i+1,b=c;
    while(c>0) k=c%10,chars[++i]=k,g++,c/=10;
    b=b-(g+1);//very important to notice this
    reverse(chars,f,i),i++; // we return pointer after the symbolic digits,notice that j is untouched
    f=i; // we backup i position before copying all other elements
    chars[i++]=chars[j];
    while(j<charsSize-1) chars[i++]=chars[++j];
    charsSize=charsSize-(b),i=f,j=f+1;
}

}
return charsSize;
}

int main () {
    char chars[7] = {'a','a','b','b','c','c','c'};
 int charsSize = sizeof(chars)/sizeof(chars[0]);
 int i;
printf("New Size is :%d ",charsSize=compress(chars,charsSize));
printf("New array is:\n");
for(i=0;i<charsSize;i++) printf("%c ",chars[i]);
}
