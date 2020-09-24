#include <stdio.h>
#include <stdbool.h>
int s1[26];
int s2[26];
void counter(char a,int sw){
    int *ptr=&s1;
    if(sw) ptr=&s2;
    switch(a) {
        case 'a':
            ptr[0]++;
            return;
                    case 'b':
            ptr[1]++;
            return;
                    case 'c':
            ptr[2]++;
            return;
                    case 'd':
            ptr[3]++;
            return;
                    case 'e':
            ptr[4]++;
            return;
                    case 'f':
            ptr[5]++;
            return;
                    case 'g':
            ptr[6]++;
            return;
                    case 'h':
            ptr[7]++;
            return;
                    case 'i':
            ptr[8]++;
            return;
                    case 'j':
            ptr[9]++;
            return;
                    case 'k':
            ptr[10]++;
            return;
                    case 'l':
            ptr[11]++;
            return;
                    case 'm':
            ptr[12]++;
            return;
                    case 'n':
            ptr[13]++;
            return;
                    case 'o':
            ptr[14]++;
            return;
                    case 'p':
            ptr[15]++;
            return;
                    case 'q':
            ptr[16]++;
            return;
                    case 'r':
            ptr[17]++;
            return;
                    case 's':
            ptr[18]++;
            return;
                    case 't':
            ptr[19]++;
            return;
                    case 'u':
            ptr[20]++;
            return;
                    case 'v':
            ptr[21]++;
            return;
                    case 'w':
            ptr[22]++;
            return;
                    case 'x':
            ptr[23]++;
            return;
                    case 'y':
            ptr[24]++;
            return;
                    case 'z':
            ptr[25]++;
            return;

    }
}
bool isAnagram(char * s, char * t){
int i=0;
    for(i=0;i<26;i++) s1[i]=0,s2[i]=0;
    for(i=0;s[i]!='\0';i++) counter(s[i],0);
    for(i=0;t[i]!='\0';i++) counter(t[i],1);
    for(i=0;i<26;i++) if(s1[i]!=s2[i]) return false;
    return true;

}


int main () {
     char s[30]="anagram";
     char t[30]="nagaram";

     printf("%d",isAnagram(s,t));





}
