bool isPowerOfFour(int num){
    float n=num;
if(num<1) return false;
    else if(num==1) return true;
    else if(num==4) return true;
    else if(num%2!=0) return false;
    while(n>=4) n/=4;
    if(n!=1) return false;
    else return true;
}