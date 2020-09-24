//solution written by Yarin Avisidris
//https://leetcode.com/problems/integer-to-roman/submissions/
char * reverse_string(char *s , int end) {
    int i=0,j=end-1;
    char tmp;
    while(i<j) {
        tmp=s[j];
        s[j]=s[i];
        s[i]=tmp;
        i++,j--;
    }
    return s;
}
char * intToRoman(int num){
char *res = (char*)calloc(25,sizeof(char));
    int b=num,g,digits=0,i=0;
    while(num) {
        g=num%10;
        switch(digits) {
            case 0:
                switch(g) {
                    case 1:
                        res[i]='I',i++;
                        break;
                    case 2:
                        res[i]='I', res[i+1]='I';i+=2;
                        break;
                    case 3:
                        res[i]='I',res[i+1]='I',res[i+2]='I',i+=3;
                        break;
                    case 4:
                        res[i]='V',res[i+1]='I',i+=2;
                        break;
                    case 5:
                        res[i]='V',i++;
                        break;
                    case 6:
                        res[i]='I',res[i+1]='V',i+=2;
                        break;
                    case 7: 
                        res[i]='I',res[i+1]='I',res[i+2]='V',i+=3;
                        break;
                    case 8:
                        res[i]='I',res[i+1]='I',res[i+2]='I',res[i+3]='V',i+=4;
                        break;
                    case 9:
                        res[i]='X',res[i+1]='I',i+=2;
                        break;
                }
                digits++;
            break;
            case 1:
                switch(g) {
                    case 1:
                        res[i]='X',i++;
                        break;
                    case 2:
                        res[i]='X', res[i+1]='X';i+=2;
                        break;
                    case 3:
                        res[i]='X',res[i+1]='X',res[i+2]='X',i+=3;
                        break;
                    case 4:
                        res[i]='L',res[i+1]='X',i+=2;
                        break;
                    case 5:
                        res[i]='L',i++;
                        break;
                    case 6:
                        res[i]='X',res[i+1]='L',i+=2;
                        break;
                    case 7: 
                        res[i]='X',res[i+1]='X',res[i+2]='L',i+=3;
                        break;
                    case 8:
                        res[i]='X',res[i+1]='X',res[i+2]='X',res[i+3]='L',i+=4;
                        break;
                    case 9:
                        res[i]='C',res[i+1]='X',i+=2;
                        break;
                }
                digits++;
            break;
            case 2:
                switch(g) {
                    case 1:
                        res[i]='C',i++;
                        break;
                    case 2:
                        res[i]='C', res[i+1]='C';i+=2;
                        break;
                    case 3:
                        res[i]='C',res[i+1]='C',res[i+2]='C',i+=3;
                        break;
                    case 4:
                        res[i]='D',res[i+1]='C',i+=2;
                        break;
                    case 5:
                        res[i]='D',i++;
                        break;
                    case 6:
                        res[i]='C',res[i+1]='D',i+=2;
                        break;
                    case 7: 
                        res[i]='C',res[i+1]='C',res[i+2]='D',i+=3;
                        break;
                    case 8:
                        res[i]='C',res[i+1]='C',res[i+2]='C',res[i+3]='D',i+=4;
                        break;
                    case 9:
                        res[i]='M',res[i+1]='C',i+=2;
                        break;
                }
                digits++;
            break;
            case 3:
                switch(g) {
                    case 1:
                        res[i]='M',i++;
                        break;
                    case 2:
                        res[i]='M', res[i+1]='M';i+=2;
                        break;
                    case 3:
                        res[i]='M',res[i+1]='M',res[i+2]='M',i+=3;
                        break;
                        // we dont continue here because maximum is 3999! cant convert into 4000 and above!
                }
                digits++;
            break;
        }
        num/=10;
    }
    //printf("%d",i);
    
    return reverse_string(res,i);
}