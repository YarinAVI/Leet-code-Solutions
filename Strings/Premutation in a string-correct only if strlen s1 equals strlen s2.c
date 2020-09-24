int h2[26];
int h1[26];
void counter(char a,char h1_or2) {
    int *p;
    if(h1_or2) p=h2;
    else p=h1;
switch(a) {
case 97:
    p[0]++;
    break;
case 98:
    p[1]++;
    break;
    case 99:
    p[2]++;
    break;
    case 100:
    p[3]++;
    break;
    case 101:
    p[4]++;
    break;
    case 102:
    p[5]++;
    break;
    case 103:
    p[6]++;
    break;
    case 104:
    p[7]++;
    break;
    case 105:
    p[8]++;
    break;
    case 106:
    p[9]++;
    break;
    case 107:
    p[10]++;
    break;
    case 108:
    p[11]++;
    break;
    case 109:
    p[12]++;
    break;
    case 110:
    p[13]++;
    break;
    case 111:
    p[14]++;
    break;
    case 112:
    p[15]++;
    break;
    case 113:
    p[16]++;
    break;
    case 114:
    p[17]++;
    break;
    case 115:
    p[18]++;
    break;
    case 116:
    p[19]++;
    break;
    case 117:
    p[20]++;
    break;
    case 118:
    p[21]++;
    break;
    case 119:
    p[22]++;
    break;
    case 120:
    p[23]++;
    break;
    case 121:
    p[24]++;
    break;
    case 122:
    p[25]++;
    break;

}

}
bool checkInclusion(char * s1, char * s2){
int i,j;
    if(strlen(s1)>strlen(s2)) return false;
    for(i=0;i<26;i++) h2[i]=0,h1[i]=0;
    for(i=0;s1[i]!='\0';i++) counter(s1[i],0);
    for(i=0;s2[i]!='\0';i++) counter(s2[i],1);
    
    if(strlen(s1)==strlen(s2)) {
    for(i=0;i<26;i++) {
        if(h2[i]<h1[i]) return false;
    }
    return true;
    }
    
}