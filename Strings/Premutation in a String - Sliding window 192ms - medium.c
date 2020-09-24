//https://leetcode.com/problems/permutation-in-string/solution/
// sliding window approach
bool checkInclusion(char * s1, char * s2){
    int h2[26],h1[26];
    int i,j,k,l;
    int sS1=strlen(s1),sS2=strlen(s2);
    for(i=0;i<26;i++) h2[i]=0,h1[i]=0;
    for(i=0;s1[i]!='\0';i++) h1[s1[i]-97]++;
    i=0;
    while(i<=(sS2-sS1)) {
        for(l=0;l<sS1;l++) h2[s2[i+l]-97]++;
        fofor(r(l=0,k=25;l<13;l++,k--) if(h1[l]!=h2[l] || h1[k]!=h2[k]) break;
       // l=0;l<26;l++) printf("%d",)
        if(k!=12 || l!=13 )  {
            i++;
            for(l=0;l<26;l++) h2[l]=0;
        }
        else return true;
    }
    return false;
}