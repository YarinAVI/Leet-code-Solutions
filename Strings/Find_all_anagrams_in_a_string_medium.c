#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
//https://leetcode.com/problems/find-all-anagrams-in-a-string/submissions/
// Moving window solution 824ms 
int* findAnagrams(char * s, char * p, int* returnSize){
    *returnSize=0;
    //int *h = (int * )calloc(26,sizeof(int));
    //int *h1 = (int * )calloc(26,sizeof(int));
    int h[26];
    int h1[26];
    int pS=0,sS=0,i=0,j,k=0,f=0,l=0;
    sS=strlen(s),pS=strlen(p);
    int *res = (int*)malloc(sS*sizeof(int));
    for(i=0;i<26;i++) h[i]=0,h1[i]=0;
    //printf("%d %d",sS,pS);
    if(pS>sS || pS==0 || sS==0) return res;
    for(i=0;p[i]!='\0';i++) h[p[i]-97]++;
    for(i=0;i<26;i++) printf("%d ",h[i]);
    i=0;
    while(i<=(sS-pS)) {
        for(f=0;f<pS;f++) h1[s[i+f]-97]++;
        for(k=0,j=25;k<13;j--,k++) if(h1[k]!=h[k] || h1[j]!=h[j]) break;
        if(k!=13 || j!=12) i++;
        else  {
                *returnSize+=1,res[l++]=i++;
        }
        //printf("\n");
        //for(k=0;k<26;k++) printf("%d ",h1[k]);
        for(k=0;k<26;k++) h1[k]=0;

    }
        return res;
}
int main () {

char s[200] = "ababasdvbasdadeeeababazazazazababazazag";
char p[100] = "ab";
int returnSize;
int *f= findAnagrams(s,p,&returnSize);
int i=0;
printf("\n");
for(i=0;i<returnSize;i++) printf("%d ",f[i]);
}
